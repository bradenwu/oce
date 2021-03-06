#ifndef __USERBASEI_H__
#define __USERBASEI_H__

#include "UserBase.h"
#include <Ice/Ice.h>
#include <IceUtil/AbstractMutex.h>
#include <IceUtil/Mutex.h>
#include <IceUtil/RWRecMutex.h>
#include "user/UserBase/hotback/data/UserBaseDataI.h"
#include "TaskManager.h"

#include "ServiceI.h"
#include "QueryRunner.h"
#include "TempMutex.h"
#include "util/cpp/InvokeMonitor.h"

namespace xce
{
namespace userbase
{

//service name
const string USER_BASEVIEW_MANAGER   = "UBVM";
const string USER_PASSPORT_MANAGER   = "UPM";
const string USER_NAME_MANAGER       = "UNM";
const string USER_RIGHT_MANAGER      = "URM";
const string USER_STATE_MANAGER      = "USM";
const string USER_LOGINCOUNT_MANAGER = "ULCM";
const string USER_URL_MANAGER        = "U";
const string USER_BASIC_MANAGER      = "UBM";

const string USER_BORN_MANAGER       = "UBOM";
const string USER_STAGE_MANAGER      = "USGM";
const string USER_DOING_MANAGER      = "UDM";
//-------------------------UserPassportManagerI-------------------------------
class UserPassportManagerI : virtual public UserPassportWriter, public MyUtil::Singleton<UserPassportManagerI>
{
public:
	UserPassportManagerI()  {
		tempMutexManagerPtr_ = new xce::tempmutex::TempMutexManager;
	}
	
    virtual void createUserPassport(
		const Str2StrMap& props,
		const Ice::Current& = Ice::Current());

    virtual void setUserPassport(
		Ice::Int userId,
		const MyUtil::Str2StrMap& props,
		const Ice::Current& = Ice::Current());

	virtual void reload(Ice::Int userId,const Ice::Current& =Ice::Current());

	virtual void setValid(bool valid, const ::Ice::Current& = ::Ice::Current());
private:
	
	xce::tempmutex::TempMutexManagerPtr tempMutexManagerPtr_;

};




//-------------------------UserNameManagerI-------------------------------
class UserNameManagerI : virtual public UserNameWriter, public MyUtil::Singleton<UserNameManagerI>
{
public:
	UserNameManagerI()  {
		tempMutexManagerPtr_ = new xce::tempmutex::TempMutexManager;
	}
	
    virtual void createUserName(
		const Str2StrMap& props,
		const Ice::Current& = Ice::Current());

    virtual void setUserName(
		Ice::Int userId,
		const MyUtil::Str2StrMap& props,
		const Ice::Current& = Ice::Current());

	virtual void reload(Ice::Int userId,const Ice::Current& =Ice::Current());
	virtual void setValid(bool valid, const ::Ice::Current& = ::Ice::Current());
private:
	
	xce::tempmutex::TempMutexManagerPtr tempMutexManagerPtr_;
};


//-------------------------UserRightManagerI-------------------------------
class UserRightManagerI : virtual public UserRightWriter, public MyUtil::Singleton<UserRightManagerI>
{
public:
	UserRightManagerI()  {
		tempMutexManagerPtr_ = new xce::tempmutex::TempMutexManager;
	}
	
    virtual void createUserRight(
		const Str2StrMap& props,
		const Ice::Current& = Ice::Current());

    virtual void setUserRight(
		Ice::Int userId,
		const MyUtil::Str2StrMap& props,
		const Ice::Current& = Ice::Current());
	
	virtual void reload(Ice::Int userId,const Ice::Current& =Ice::Current());

	virtual void setValid(bool valid, const ::Ice::Current& = ::Ice::Current());
private:
	
	xce::tempmutex::TempMutexManagerPtr tempMutexManagerPtr_;
};

//-------------------------UserStateManagerI-------------------------------
class UserStateManagerI : virtual public UserStateWriter, public MyUtil::Singleton<UserStateManagerI>
{
public:
	UserStateManagerI()  {
		tempMutexManagerPtr_ = new xce::tempmutex::TempMutexManager;
	}
	
    virtual void createUserState(
		const Str2StrMap& props,
		const Ice::Current& = Ice::Current());

    virtual void setUserState(
		Ice::Int userId,
		const MyUtil::Str2StrMap& props,
		const Ice::Current& = Ice::Current());

	virtual void reload(Ice::Int userId,const Ice::Current& =Ice::Current());
	virtual void setStateOn(Ice::Int userId, Ice::Int pos, const Ice::Current& = Ice::Current());
        virtual void setStateOff(Ice::Int userId, Ice::Int pos, const Ice::Current& = Ice::Current());
	virtual void setValid(bool valid, const ::Ice::Current& = ::Ice::Current());
private:
	
	xce::tempmutex::TempMutexManagerPtr tempMutexManagerPtr_;
};


//-------------------------UserLoginCountManagerI-------------------------------
class UserLoginCountManagerI : virtual public UserLoginCountWriter, public MyUtil::Singleton<UserLoginCountManagerI>
{
public:
	UserLoginCountManagerI()  {
		tempMutexManagerPtr_ = new xce::tempmutex::TempMutexManager;
	}
	
    virtual void createUserLoginCount(
		const Str2StrMap& props,
		const Ice::Current& = Ice::Current());

    virtual void incUserLoginCount(
		Ice::Int userId,
		const Ice::Current& = Ice::Current());

	virtual void reload(Ice::Int userId,const Ice::Current& =Ice::Current());
	virtual void setValid(bool valid, const ::Ice::Current& = ::Ice::Current());
private:
	
	xce::tempmutex::TempMutexManagerPtr tempMutexManagerPtr_;
};

//----------------------------------------------------------------------------
class UserUrlManagerI : virtual public UserUrlWriter, public MyUtil::Singleton<UserUrlManagerI>{
public:
	UserUrlManagerI() {
		tempMutexManagerPtr_ = new xce::tempmutex::TempMutexManager;
	}
	virtual void setUserUrl(Ice::Int userId, const MyUtil::Str2StrMap& props, const Ice::Current& = Ice::Current());
	virtual void createUserUrl(const MyUtil::Str2StrMap& props, const Ice::Current& = Ice::Current());
	virtual void reload(Ice::Int userId, const Ice::Current& = Ice::Current());
	virtual void setValid(bool valid, const ::Ice::Current& = ::Ice::Current());
private:
	
	xce::tempmutex::TempMutexManagerPtr tempMutexManagerPtr_;
};

//----------------------------------------------------------------------------

class UserBornManagerI : virtual public UserBornWriter,  public MyUtil::Singleton<UserBornManagerI>
{
public:
	UserBornManagerI() {
		tempMutexManagerPtr_ = new xce::tempmutex::TempMutexManager;
	}
	virtual void createUserBorn(const Str2StrMap& props,const Ice::Current& = Ice::Current());
	virtual void reloadUserBorn(Ice::Int userId,const Ice::Current& = Ice::Current());
	virtual void setUserBorn(Ice::Int userId, const Str2StrMap& props,const Ice::Current& = Ice::Current());
	
	virtual void setValid(bool valid, const ::Ice::Current& = ::Ice::Current());
private:
	
	xce::tempmutex::TempMutexManagerPtr tempMutexManagerPtr_;
};


//----------------------------------------------------------------------------


class UserStageManagerI : virtual public UserStageWriter,  public MyUtil::Singleton<UserStageManagerI>
{
public:
	UserStageManagerI() {
		tempMutexManagerPtr_ = new xce::tempmutex::TempMutexManager;
	}
	virtual void createUserStage(const Str2StrMap& props,const Ice::Current& = Ice::Current());
	virtual void reloadUserStage(Ice::Int userId,const Ice::Current& = Ice::Current());
	virtual void setUserStage(Ice::Int userId, const Str2StrMap& props,const Ice::Current& = Ice::Current());

	virtual void setValid(bool valid, const ::Ice::Current& = ::Ice::Current());
private:
	
	xce::tempmutex::TempMutexManagerPtr tempMutexManagerPtr_;
};




//----------------------------------------------------------------------------


class UserDoingManagerI : virtual public UserDoingWriter,  public MyUtil::Singleton<UserDoingManagerI>
{
public:
	UserDoingManagerI() {
		tempMutexManagerPtr_ = new xce::tempmutex::TempMutexManager;
	}
	virtual void createUserDoing(const Str2StrMap& props,const Ice::Current& = Ice::Current());
	virtual void reloadUserDoing(Ice::Int userId,const Ice::Current& = Ice::Current());
	virtual void setUserDoing(Ice::Int userId, const Str2StrMap& props,const Ice::Current& = Ice::Current());
	
	virtual void setValid(bool valid, const ::Ice::Current& = ::Ice::Current());
private:
	
	xce::tempmutex::TempMutexManagerPtr tempMutexManagerPtr_;
};


};
};
#endif

