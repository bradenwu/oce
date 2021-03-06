#ifndef TIME_STAT_H_
#define TIME_STAT_H_

#include <string>
#include <cmath>
#include "TaskManager.h"
#include "IceLogger.h"
#include "Singleton.h"
namespace xce {
namespace notify {


class TimeStat {
  timeval _begin, _end;
  bool _log;
public:
  TimeStat(bool log = false) {
    _log = log;
    reset();
  }
  ~TimeStat() {
//    if (_log) {
//      MCE_INFO("######### " << getTime());
//    }
  }
  void reset() {
    gettimeofday(&_begin, NULL);
  }
  float getTime(bool resettime = true) {
    gettimeofday(&_end, NULL);
    float timeuse = 1000000 * (_end.tv_sec - _begin.tv_sec) + _end.tv_usec
        - _begin.tv_usec;
    timeuse /= 1000;
    if(resettime){
      reset();
    }
    return timeuse;
  }

};


}
}

#endif // FEED_GROUP_COMMON_H_

