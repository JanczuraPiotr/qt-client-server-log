//
// Created by piotr@janczura.pl on 2020.07.10
//

#ifndef SERVER_OUTPUT_GETLOGRECORDJSON
#define SERVER_OUTPUT_GETLOGRECORDJSON

#include "common/def.h"
#include "common/data/entity/Log.hpp"
#include "common/data/record/Log.hpp"

namespace d = data;
namespace e = data::entity;
namespace r = data::record;

namespace sv::out {

class GetLogRecordJson {
public:
    GetLogRecordJson() = default;
    virtual ~GetLogRecordJson() = default;

    cm::JsonString command(r::Log::ptr rLog);

public: // lock
    GetLogRecordJson(const GetLogRecordJson &) = delete;
    GetLogRecordJson(GetLogRecordJson &&) = delete;
    GetLogRecordJson &operator = (const GetLogRecordJson&) = delete;
    GetLogRecordJson &operator = (GetLogRecordJson &&) = delete;

};

}


#endif
