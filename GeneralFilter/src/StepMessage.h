#ifndef __STEPMESSAGE_H__
#define __STEPMESSAGE_H__

#include <Ice/Ice.h>
#include <IceUtil/Mutex.h>
#include <cmath>
#include "IceLogger.h"
#include "Step.h"
namespace mop
{
namespace hi
{
namespace svc
{
namespace gf
{
    using namespace std;
    
	static const int MAX_COUNT_MESSAGE = 20;
	static int OVER_COUNT_MESSAGE = 12;
	
    static int MAX_MARK_MESSAGE = 10000;
    static int DEC_MARK_TIMESLOT_MESSAGE = 60*5;
    static int MAX_DEC_MARK_MESSAGE = 15;
    
    static double ALPHA_MESSAGE = 0.5;//加倍系数
    static double BETA_MESSAGE = 15; //指数分母
    
	class StepMessage :public Step
	{
	protected:
		IceUtil::Mutex _lock;
	public:
		
		int steps[MAX_COUNT_MESSAGE];
		int currentTime;
		int index;
		int avg;
		int likeAvgCount;
		int total;
		
		int mark;
		int decMarkCount;
        int mistakeCount;
        
	//int dayCount;

		StepMessage()
		{
			memset(&steps[0],0, sizeof(int)*20);
			currentTime = time(NULL);
			index = -1;
			avg = 0 ;
			likeAvgCount = 0;
			total = 0;
	//		dayCount = 0;
			
			mark = 0;
			decMarkCount = 0;
			mistakeCount = 0;
		};

		void add(int time)
		{
			IceUtil::Mutex::Lock lock(_lock);
	/*		if (++dayCount >= 300) {
				if (time - currentTime < 60*60*24) {
					++likeAvgCount;
					return;
				} else {
					likeAvgCount = 0;
					dayCount = 0;
				}
			}*/
			MCE_DEBUG("call add");
			index = (index+1)% MAX_COUNT_MESSAGE;
			total -= steps[index];
			steps[index] = time - currentTime;
			total += steps[index];
			currentTime = time;
			avg = total / MAX_COUNT_MESSAGE;
			if(abs(avg - steps[index]) <= 1)
			{
			    likeAvgCount ++;
			}
			MCE_DEBUG("TIME_STEP:"<< steps[index]<<"\tAVG:"<< avg <<"\tLIKE_AVG_COUNT:"<< likeAvgCount);	
		};

		int getAvgCount(int fromid, int toid)
		{
			IceUtil::Mutex::Lock lock(_lock);
		/*	if (dayCount >= 300)	
			{
				return likeAvgCount;
			}*/
			if(likeAvgCount >= OVER_COUNT_MESSAGE)
			{
				likeAvgCount = 0;
				for(int i = 0; i< MAX_COUNT_MESSAGE; ++i)
				{
					if(abs(avg - steps[i]) <= 1) likeAvgCount ++;
				}
			}
			MCE_DEBUG("call getAvgCount:"<<likeAvgCount);
			if((likeAvgCount >= OVER_COUNT_MESSAGE) || (mark > 0)) 
			{
				MCE_INFO("FROMID::"<<fromid<<"\tTOID:"<<toid<<"\tTIME_STEP:"<< steps[index]<<"\tAVG:"<< avg << "\tMARK:"<<mark <<"\tMISTAKECOUNT:"<< mistakeCount << "\tDECMARKCOUNT:"<< decMarkCount << "\tLIKE_AVG_COUNT:"<< likeAvgCount);
			}
			return likeAvgCount;
		};
		
		void incMark()
		{
		    IceUtil::Mutex::Lock lock(_lock);
		    MCE_DEBUG("call incMark");
		    if(mark > MAX_MARK_MESSAGE) return;
		    mark += (int)(ALPHA_MESSAGE * pow(2,(double)mistakeCount/(double)BETA_MESSAGE));
		    mistakeCount++;
		    decMarkCount = 0;
			MCE_DEBUG("MARK:"<<mark<<"\tMISTAKECOUNT:"<<mistakeCount);
		};
		
		void decMark()
		{
		    IceUtil::Mutex::Lock lock(_lock);
		    MCE_DEBUG("call decMark");
		    mistakeCount -= decMarkCount++/5;
		    if(mistakeCount<0) mistakeCount = 0;
		    
		   
		    mark = mark - (steps[index]/DEC_MARK_TIMESLOT_MESSAGE)*MAX_DEC_MARK_MESSAGE -1;
		    if(mark < 0) mark = 0;
			MCE_DEBUG("DEC_MARK_COUNT:"<<decMarkCount<<"\tMISTAKE_COUNT:"<<mistakeCount<<"\tMARK:"<<mark);
		   
		};
		
		int getMark()
		{
		    IceUtil::Mutex::Lock lock(_lock);
			MCE_DEBUG("call getMark:"<<mark);
		    return mark;
		};
		
	};
	
	//typedef IceUtil::Handle<Step> StepPtrMessage;

	
};
};
};
};

#endif

