/*
 * AdConfig.cpp
 *
 *  Created on: 2010-11-22
 *      Author: ark
 */
#include "AdConfig.h"
#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>
#include <fstream>
#include "IceLogger.h"

namespace xce {
namespace ad {

bool AdConfig::LoadConfig() {

  //string file_name = "../etc/ad_quality.config";
  string file_name = "../etc/ad_quality_n" + server_index + ".config";

  try {
    ifstream config(file_name.c_str());
    string line;

    if (config) {
      while (config >> line) {
        typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
        boost::char_separator<char> sep("=");
        tokenizer tokens(line, sep);
        string key;
        string value;
        int n = 0;
        for(tokenizer::iterator it = tokens.begin(); it != tokens.end(); ++it, ++n) {
          if (0==n) {
            key = *it;
          } else if(1==n) {
            value = *it;
          }
        }
        if (!key.empty()) {
          map_[key] = value;
          MCE_INFO("AdConfig::LoadConfig Get config key: " << key
              << ", value: " << value);
        }
      }
    } else {
      MCE_INFO("no file " << file_name);
    }
    if (config) {
      config.close();
    }
  } catch (Ice::Exception& e) {
    MCE_WARN("AdConfig::LoadConfig error : " << e);
  } catch (...) {
    MCE_WARN("AdConfig::LoadConfig error : unkown error \"...\"");
  }
  return true;
}

}
}
