/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 */
#include "engine_types.h"

namespace com { namespace renren { namespace ad { namespace engine {

const char* UserAndAction::ascii_fingerprint = "7B59D276409F5BB3949BDF420ADA8753";
const uint8_t UserAndAction::binary_fingerprint[16] = {0x7B,0x59,0xD2,0x76,0x40,0x9F,0x5B,0xB3,0x94,0x9B,0xDF,0x42,0x0A,0xDA,0x87,0x53};

uint32_t UserAndAction::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->id);
          this->__isset.id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->stage);
          this->__isset.stage = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->gender);
          this->__isset.gender = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->age);
          this->__isset.age = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->school);
          this->__isset.school = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->userMajor);
          this->__isset.userMajor = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->grade);
          this->__isset.grade = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->homeArea);
          this->__isset.homeArea = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 9:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->currentArea);
          this->__isset.currentArea = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 10:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->ip);
          this->__isset.ip = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 11:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->ipArea);
          this->__isset.ipArea = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 12:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast0;
          xfer += iprot->readI32(ecast0);
          this->actionType = (ActionType::type)ecast0;
          this->__isset.actionType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 13:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->object);
          this->__isset.object = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t UserAndAction::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("UserAndAction");
  xfer += oprot->writeFieldBegin("id", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->id);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("stage", ::apache::thrift::protocol::T_I16, 2);
  xfer += oprot->writeI16(this->stage);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("gender", ::apache::thrift::protocol::T_I16, 3);
  xfer += oprot->writeI16(this->gender);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("age", ::apache::thrift::protocol::T_I16, 4);
  xfer += oprot->writeI16(this->age);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("school", ::apache::thrift::protocol::T_I64, 5);
  xfer += oprot->writeI64(this->school);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("userMajor", ::apache::thrift::protocol::T_I32, 6);
  xfer += oprot->writeI32(this->userMajor);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("grade", ::apache::thrift::protocol::T_I16, 7);
  xfer += oprot->writeI16(this->grade);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("homeArea", ::apache::thrift::protocol::T_STRING, 8);
  xfer += oprot->writeString(this->homeArea);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("currentArea", ::apache::thrift::protocol::T_STRING, 9);
  xfer += oprot->writeString(this->currentArea);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("ip", ::apache::thrift::protocol::T_I32, 10);
  xfer += oprot->writeI32(this->ip);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("ipArea", ::apache::thrift::protocol::T_STRING, 11);
  xfer += oprot->writeString(this->ipArea);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("actionType", ::apache::thrift::protocol::T_I32, 12);
  xfer += oprot->writeI32((int32_t)this->actionType);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("object", ::apache::thrift::protocol::T_STRING, 13);
  xfer += oprot->writeString(this->object);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

const char* AdRequest::ascii_fingerprint = "B9B163C61BD22CB12D6F7371B816CEE2";
const uint8_t AdRequest::binary_fingerprint[16] = {0xB9,0xB1,0x63,0xC6,0x1B,0xD2,0x2C,0xB1,0x2D,0x6F,0x73,0x71,0xB8,0x16,0xCE,0xE2};

uint32_t AdRequest::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->userAndAction.read(iprot);
          this->__isset.userAndAction = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->referer);
          this->__isset.referer = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->channelId);
          this->__isset.channelId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->syndicationId);
          this->__isset.syndicationId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->memberId);
          this->__isset.memberId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->matchId);
          this->__isset.matchId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->zoneDict.clear();
            uint32_t _size1;
            ::apache::thrift::protocol::TType _ktype2;
            ::apache::thrift::protocol::TType _vtype3;
            iprot->readMapBegin(_ktype2, _vtype3, _size1);
            uint32_t _i5;
            for (_i5 = 0; _i5 < _size1; ++_i5)
            {
              int64_t _key6;
              xfer += iprot->readI64(_key6);
              int16_t& _val7 = this->zoneDict[_key6];
              xfer += iprot->readI16(_val7);
            }
            iprot->readMapEnd();
          }
          this->__isset.zoneDict = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->attributes.clear();
            uint32_t _size8;
            ::apache::thrift::protocol::TType _ktype9;
            ::apache::thrift::protocol::TType _vtype10;
            iprot->readMapBegin(_ktype9, _vtype10, _size8);
            uint32_t _i12;
            for (_i12 = 0; _i12 < _size8; ++_i12)
            {
              std::string _key13;
              xfer += iprot->readString(_key13);
              std::string& _val14 = this->attributes[_key13];
              xfer += iprot->readString(_val14);
            }
            iprot->readMapEnd();
          }
          this->__isset.attributes = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t AdRequest::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("AdRequest");
  xfer += oprot->writeFieldBegin("userAndAction", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += this->userAndAction.write(oprot);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("referer", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->referer);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("channelId", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32(this->channelId);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("syndicationId", ::apache::thrift::protocol::T_I32, 4);
  xfer += oprot->writeI32(this->syndicationId);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("memberId", ::apache::thrift::protocol::T_I32, 5);
  xfer += oprot->writeI32(this->memberId);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("matchId", ::apache::thrift::protocol::T_I32, 6);
  xfer += oprot->writeI32(this->matchId);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("zoneDict", ::apache::thrift::protocol::T_MAP, 7);
  {
    xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_I64, ::apache::thrift::protocol::T_I16, this->zoneDict.size());
    std::map<int64_t, int16_t> ::const_iterator _iter15;
    for (_iter15 = this->zoneDict.begin(); _iter15 != this->zoneDict.end(); ++_iter15)
    {
      xfer += oprot->writeI64(_iter15->first);
      xfer += oprot->writeI16(_iter15->second);
    }
    xfer += oprot->writeMapEnd();
  }
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("attributes", ::apache::thrift::protocol::T_MAP, 8);
  {
    xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_STRING, ::apache::thrift::protocol::T_STRING, this->attributes.size());
    std::map<std::string, std::string> ::const_iterator _iter16;
    for (_iter16 = this->attributes.begin(); _iter16 != this->attributes.end(); ++_iter16)
    {
      xfer += oprot->writeString(_iter16->first);
      xfer += oprot->writeString(_iter16->second);
    }
    xfer += oprot->writeMapEnd();
  }
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

const char* ClickAction::ascii_fingerprint = "1F10F993631B3ABD721D79EE58C2056E";
const uint8_t ClickAction::binary_fingerprint[16] = {0x1F,0x10,0xF9,0x93,0x63,0x1B,0x3A,0xBD,0x72,0x1D,0x79,0xEE,0x58,0xC2,0x05,0x6E};

uint32_t ClickAction::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->userId);
          this->__isset.userId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->ip);
          this->__isset.ip = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->referer);
          this->__isset.referer = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->clickUrl);
          this->__isset.clickUrl = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->context);
          this->__isset.context = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->extra);
          this->__isset.extra = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ClickAction::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("ClickAction");
  xfer += oprot->writeFieldBegin("userId", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->userId);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("ip", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->ip);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("referer", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->referer);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("clickUrl", ::apache::thrift::protocol::T_STRING, 4);
  xfer += oprot->writeString(this->clickUrl);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("context", ::apache::thrift::protocol::T_STRING, 5);
  xfer += oprot->writeString(this->context);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("extra", ::apache::thrift::protocol::T_STRING, 6);
  xfer += oprot->writeString(this->extra);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

const char* Ad::ascii_fingerprint = "1448AFE5D8086FC1ADB058DEF2087478";
const uint8_t Ad::binary_fingerprint[16] = {0x14,0x48,0xAF,0xE5,0xD8,0x08,0x6F,0xC1,0xAD,0xB0,0x58,0xDE,0xF2,0x08,0x74,0x78};

uint32_t Ad::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->creativeId);
          this->__isset.creativeId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->adGroupId);
          this->__isset.adGroupId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->context);
          this->__isset.context = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->position);
          this->__isset.position = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->extra);
          this->__isset.extra = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t Ad::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("Ad");
  xfer += oprot->writeFieldBegin("creativeId", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->creativeId);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("adGroupId", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64(this->adGroupId);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("context", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->context);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("position", ::apache::thrift::protocol::T_I16, 4);
  xfer += oprot->writeI16(this->position);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("extra", ::apache::thrift::protocol::T_STRING, 5);
  xfer += oprot->writeString(this->extra);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

const char* AdResponse::ascii_fingerprint = "CA0CA6B8A2E981D02D982FFB3539599E";
const uint8_t AdResponse::binary_fingerprint[16] = {0xCA,0x0C,0xA6,0xB8,0xA2,0xE9,0x81,0xD0,0x2D,0x98,0x2F,0xFB,0x35,0x39,0x59,0x9E};

uint32_t AdResponse::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->candidates.clear();
            uint32_t _size17;
            ::apache::thrift::protocol::TType _ktype18;
            ::apache::thrift::protocol::TType _vtype19;
            iprot->readMapBegin(_ktype18, _vtype19, _size17);
            uint32_t _i21;
            for (_i21 = 0; _i21 < _size17; ++_i21)
            {
              int64_t _key22;
              xfer += iprot->readI64(_key22);
              std::vector<Ad> & _val23 = this->candidates[_key22];
              {
                _val23.clear();
                uint32_t _size24;
                ::apache::thrift::protocol::TType _etype27;
                iprot->readListBegin(_etype27, _size24);
                _val23.resize(_size24);
                uint32_t _i28;
                for (_i28 = 0; _i28 < _size24; ++_i28)
                {
                  xfer += _val23[_i28].read(iprot);
                }
                iprot->readListEnd();
              }
            }
            iprot->readMapEnd();
          }
          this->__isset.candidates = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t AdResponse::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("AdResponse");
  xfer += oprot->writeFieldBegin("candidates", ::apache::thrift::protocol::T_MAP, 1);
  {
    xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_I64, ::apache::thrift::protocol::T_LIST, this->candidates.size());
    std::map<int64_t, std::vector<Ad> > ::const_iterator _iter29;
    for (_iter29 = this->candidates.begin(); _iter29 != this->candidates.end(); ++_iter29)
    {
      xfer += oprot->writeI64(_iter29->first);
      {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, _iter29->second.size());
        std::vector<Ad> ::const_iterator _iter30;
        for (_iter30 = _iter29->second.begin(); _iter30 != _iter29->second.end(); ++_iter30)
        {
          xfer += (*_iter30).write(oprot);
        }
        xfer += oprot->writeListEnd();
      }
    }
    xfer += oprot->writeMapEnd();
  }
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

}}}} // namespace
