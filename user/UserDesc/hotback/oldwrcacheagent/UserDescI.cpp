/*
 * =====================================================================================
 *
 *       Filename:  UserDescI.cpp
 *
 *    Description:  new Service UserDesc inlude UserTime,UserContact and big UserDesc.
 *
 *        Version:  1.0
 *        Created:  2009年08月28日 18时07分42秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  guanghe.ge (ggh), guanghe.ge@opi-corp.com
 *        Company:  XiaoNei
 *
 * =====================================================================================
 */

#include "UserDescI.h"
#include "util/cpp/String.h"
#include "UserLogicAdapter.h"
#include "util/cpp/TimeCost.h"

#include "ReplicaCluster/ServerState/src/client/cxx/ServerStateSubscriber.h"

#include "UserContactReaderAdapter.h"
#include "UserTimeReaderAdapter.h"
#include "UserDescReaderAdapter.h"

#include "util/cpp/InvokeMonitor.h"
#include "Monitor/client/service/ServiceMonitor.h"

using namespace xce::userdesc;
using namespace com::xiaonei::xce;
using namespace mop::hi::svc::adapter;
using namespace xce::serverstate;
using namespace xce::adapter::usercontact;
using namespace xce::adapter::usertime;
using namespace xce::adapter::userdesc;
using namespace xce::tempmutex;

void MyUtil::initialize() {
	ServiceI& service = MyUtil::ServiceI::instance();

	service.getAdapter()->add(&UserTimeManagerI::instance(), service.createIdentity("T", ""));
	service.getAdapter()->add(&UserContactManagerI::instance(), service.createIdentity("C", ""));
	service.getAdapter()->add(&UserFavManagerI::instance(), service.createIdentity("F", ""));
	service.getAdapter()->add(&UserDescManagerI::instance(), service.createIdentity("M", ""));

	//-----------------------------------HA---------------------------------------------
	int mod = service.getCommunicator()->getProperties()->getPropertyAsInt("UserDesc.Mod");
	int interval = service.getCommunicator()->getProperties()->getPropertyAsIntWithDefault("UserDesc.Interval",5);
	
	map<string,Ice::ObjectPtr> mapNameAndService;
	
	mapNameAndService.insert(make_pair<string,Ice::ObjectPtr>("T",&UserTimeManagerI::instance()));
	mapNameAndService.insert(make_pair<string,Ice::ObjectPtr>("C",&UserContactManagerI::instance()));
	mapNameAndService.insert(make_pair<string,Ice::ObjectPtr>("M",&UserDescManagerI::instance()));
	
	ServerStateSubscriber::instance().initialize("ControllerUserDesc",mapNameAndService,mod,interval);

	{
		int status = service.getCommunicator()->getProperties()->getPropertyAsIntWithDefault("UserDesc.Status",0);
		ServerStateSubscriber::instance().setStatus(status,"T");
		ServerStateSubscriber::instance().setStatus(status,"C");
		ServerStateSubscriber::instance().setStatus(status);
		
		std::ostringstream os;
		os<<"MyUtil::initialize set status : "<<status;

		MCE_WARN( os.str() );
	}

	ServiceMonitorManager::instance().start();
}

//-----------------------------------ManagerIs------------------------
//----------------------------------UserTimeManagerI-----------------
UserTimeManagerI::UserTimeManagerI() {
	_isValid = false;
	_tempMutexManager = new xce::tempmutex::TempMutexManager;
}

UserTimeManagerI::~UserTimeManagerI() {
}

bool UserTimeManagerI::isValid()
{
	IceUtil::Mutex::Lock lock(_mutex);
	return _isValid;
}

UserTimeDataPtr UserTimeManagerI::getUserTime(Ice::Int id, const Ice::Current& current) {
	ostringstream inMsg;
	inMsg<<"id = "<<id;
	InvokeClient::create(current, inMsg.str(), InvokeClient::INVOKE_LEVEL_DEBUG);

	return UserTimeReaderAdapter::instance().getUserTimeData(id);
}

void UserTimeManagerI::setUserTime(Ice::Int id, const MyUtil::Str2StrMap& properities, const Ice::Current & current)
{
	ostringstream inMsg;
	inMsg<<"id = "<<id;
	InvokeClient::create(current, inMsg.str(), InvokeClient::INVOKE_LEVEL_INFO);

	//去掉map中的用户id
	Str2StrMap::iterator it = const_cast<Str2StrMap&>(properities).find("ID");
	if(it!=properities.end())
	{
		const_cast<Str2StrMap&>(properities).erase(it);
	}

	MyUtil::Str2StrMap filter;
	filter["id"] = boost::lexical_cast<string>(id);
	{
		xce::tempmutex::Lock lock(_tempMutexManager, id);
		QueryRunner(DB_USER_TIME,CDbWServer).execute(Statement::buildUpdate(TABLE_USER_TIME, filter, properities));
		UserTimeReaderAdapter::instance().setUserTime(id, properities);
	}
	UserLogicAdapter::instance().updateUserTime(id, properities, current.ctx);
}

void UserTimeManagerI::createUserTime(const MyUtil::Str2StrMap& properities, const Ice::Current & current)
{
	InvokeClient::create(current, "", InvokeClient::INVOKE_LEVEL_INFO);

	MyUtil::Str2StrMap::const_iterator itr = properities.find("ID");
	int id;
	if (itr == properities.end()) {
		MCE_WARN("UserTimeManagerI::createUserTime, Exception[NoId]");
		return;
	} else {
		id = boost::lexical_cast<int>(itr->second);
	} 
	
	{
		xce::tempmutex::Lock lock(_tempMutexManager, id);
		QueryRunner(DB_USER_TIME,CDbWServer).execute(Statement::buildInsert(TABLE_USER_TIME, properities));
		UserTimeDataIPtr result = new UserTimeDataI;
        Statement sql;
        sql << "SELECT id, registertime, activatetime, lastlogintime, lastlogouttime FROM user_time WHERE id = '" << id << "'";
        UserTimeResultHandlerI handler(result);
        QueryRunner(DB_USER_TIME, CDbWServer).query(sql, handler);
        if (id == result->id) {
        	UserTimeReaderAdapter::instance().setData(id, result);
        } else {
        	MCE_WARN("UserTimeManagerI::createUserTime, Exception[NoSuchUserTime], Information[id=" << id << "]");
        	return;
        }

	}
}

void UserTimeManagerI::reload(Ice::Int id, const Ice::Current & current) {
	ostringstream inMsg;
	inMsg<<"id = " << id;
	InvokeClient::create(current, inMsg.str(), InvokeClient::INVOKE_LEVEL_INFO);

	{
		UserTimeDataIPtr result = new UserTimeDataI;
		Statement sql;
		sql << "SELECT id, registertime, activatetime, lastlogintime, lastlogouttime FROM user_time WHERE id = '" << id << "'";
		UserTimeResultHandlerI handler(result);
		Lock lock(_tempMutexManager, id);
		QueryRunner(DB_USER_TIME, CDbWServer).query(sql, handler);
		if (id == result->id) {
			UserTimeReaderAdapter::instance().setData(id, result);
		} else {
			MCE_WARN("UserTimeWriterI::createUserTime, Exception[NoSuchUserTime], Information[id=" << id << "]");
			return;
		}
	}

}

//----------------UserContactManager--------------------
UserContactManagerI::UserContactManagerI() {
	_isValid = false;
	_tempMutexManager = new xce::tempmutex::TempMutexManager;
}

UserContactManagerI::~UserContactManagerI() {
}

bool UserContactManagerI::isValid()
{
	IceUtil::Mutex::Lock lock(_mutex);
	return _isValid;
}

UserContactDataPtr UserContactManagerI::getUserContact(Ice::Int id, const Ice::Current& current) {
	ostringstream inMsg;
	inMsg<<"id = " << id;
	InvokeClient::create(current, inMsg.str(), InvokeClient::INVOKE_LEVEL_DEBUG);

	return UserContactReaderAdapter::instance().getUserContact(id);
}

void UserContactManagerI::setUserContact(Ice::Int id,const MyUtil::Str2StrMap& properities, const Ice::Current & current) {
	ostringstream inMsg;
	inMsg<<"id = " << id;
	InvokeClient::create(current, inMsg.str(), InvokeClient::INVOKE_LEVEL_INFO);

	//去掉map中的用户id
	Str2StrMap::iterator it = const_cast<Str2StrMap&>(properities).find("ID");
	if(it!=properities.end())
	{
		const_cast<Str2StrMap&>(properities).erase(it);
	}

	MyUtil::Str2StrMap filter;
	filter["id"] = boost::lexical_cast<string>(id);

	{
		xce::tempmutex::Lock lock(_tempMutexManager, id);
		QueryRunner(DB_USER_CONTACT,CDbWServer).execute(Statement::buildUpdate(TABLE_USER_CONTACT, filter, properities));
		UserContactReaderAdapter::instance().setUserContact(id, properities);
	}
	UserLogicAdapter::instance().updateUserContact(id, properities, current.ctx);
}

void UserContactManagerI::createUserContact(const MyUtil::Str2StrMap& properities, const Ice::Current & current) {
	InvokeClient::create(current, "", InvokeClient::INVOKE_LEVEL_INFO);

	MyUtil::Str2StrMap::const_iterator itr = properities.find("ID");
	int id;
	if (itr == properities.end()) {
		MCE_WARN("UserContactManagerI::createUserContact, Exception[NoId]");
		return;
	} else {
		id = boost::lexical_cast<int>(itr->second);
	}
	
	{
		xce::tempmutex::Lock lock(_tempMutexManager, id);
		QueryRunner(DB_USER_CONTACT,CDbWServer).execute(Statement::buildInsert(TABLE_USER_CONTACT,properities));
		UserContactDataIPtr result = new UserContactDataI;
		Statement sql;
		sql << "SELECT id, msn, homepage, mobilephone, fixphone, qq FROM user_contact WHERE id = '" << id << "'";
		UserContactResultHandlerI handler(result);
		QueryRunner(DB_USER_CONTACT, CDbWServer).query(sql, handler);
		if (id == result->id) {
			UserContactReaderAdapter::instance().setData(id, result);
		} else {
			MCE_WARN("UserContactManagerI::createUserContact, Exception[NoSuchUserContact], Information[id=" << id << "]");
			return;
		}
	}
}

void UserContactManagerI::reload(Ice::Int id, const Ice::Current & current) {
	ostringstream inMsg;
	inMsg<<"id = " << id;
	InvokeClient::create(current, inMsg.str(), InvokeClient::INVOKE_LEVEL_INFO);

	{
		UserContactDataIPtr result = new UserContactDataI;
		Statement sql;
		sql << "SELECT id, msn, homepage, mobilephone, fixphone, qq FROM user_contact WHERE id = '" << id << "'";
		UserContactResultHandlerI handler(result);
		Lock lock(_tempMutexManager, id);
		QueryRunner(DB_USER_CONTACT, CDbWServer).query(sql, handler);
		if (id == result->id) {
			UserContactReaderAdapter::instance().setData(id, result);
		}else{
			MCE_WARN("UserContactManagerI::reload, Exception[NoSuchUserContact], Information[id=" << id << "]");
			return;
		}
	}
}

//----------------UserFavManager--------------------
UserFavManagerI::UserFavManagerI() {
}

UserFavManagerI::~UserFavManagerI() {
}

UserFavDataPtr UserFavManagerI::getUserFav(Ice::Int id, const Ice::Current& current) {
	MCE_WARN("UserFavManagerI::getUserFav id=" << id << " ip = "<<current.con->toString());
	return new UserFavData;
}

void UserFavManagerI::setUserFav(Ice::Int id, const MyUtil::Str2StrMap& properities, const Ice::Current & current) {
	MCE_WARN("UserFavManagerI::setUserFav id=" << id << " ip = "<<current.con->toString());
}

void UserFavManagerI::createUserFav(const MyUtil::Str2StrMap& properities, const Ice::Current & current) {
	MCE_WARN("UserFavManagerI::createUserFav ip = "<<current.con->toString());
}

void UserFavManagerI::reload(Ice::Int id, const Ice::Current & current) {
	MCE_WARN("UserFavManagerI::reload id=" << id << " ip = "<<current.con->toString());
}

//----------------UserDescManager--------------------
UserDescManagerI::UserDescManagerI() {
}

UserDescManagerI::~UserDescManagerI() {
}
UserDescDataPtr UserDescManagerI::getUserDesc(int id, const Ice::Current& current) {
	ostringstream inMsg;
	inMsg<<"id = " << id;
	InvokeClient::create(current, inMsg.str(), InvokeClient::INVOKE_LEVEL_DEBUG);

	return UserDescReaderAdapter::instance().getUserDesc(id);
}
//-----------------------------------ManagerIs end--------------------

void UserTimeManagerI::setValid(bool valid, const Ice::Current& current) {
	InvokeClient::create(current, boost::lexical_cast<string>(valid), InvokeClient::INVOKE_LEVEL_INFO);
	ServerStateSubscriber::instance().setStatus((int)valid,"T");
	{
		IceUtil::Mutex::Lock lock(_mutex);
		_isValid = valid;
	}
	if(valid == UserContactManagerI::instance().isValid())
	{
		ServerStateSubscriber::instance().setStatus((int)valid,"M");
		ServerStateSubscriber::instance().setStatus((int)valid);
	}
}

void UserFavManagerI::setValid(bool valid, const Ice::Current&) {
	MCE_WARN("UserFavManagerI::setValid -> "<<valid);
}

void UserContactManagerI::setValid(bool valid, const Ice::Current& current) {
	InvokeClient::create(current, boost::lexical_cast<string>(valid), InvokeClient::INVOKE_LEVEL_INFO);
	ServerStateSubscriber::instance().setStatus((int)valid,"C");
	{
		IceUtil::Mutex::Lock lock(_mutex);
		_isValid = valid;
	}
	if(valid == UserTimeManagerI::instance().isValid())
	{
		ServerStateSubscriber::instance().setStatus((int)valid,"M");
		ServerStateSubscriber::instance().setStatus((int)valid);
	}
}

