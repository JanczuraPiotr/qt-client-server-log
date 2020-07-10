//
// Created by piotr@janczura.pl on 2020.07.10
//

#ifndef SERVER_INPUT_GETLOGRECORDJSON
#define SERVER_INPUT_GETLOGRECORDJSON

#include "common/def.h"
#include "common/data/record/Log.hpp"

namespace d = data;
namespace e = data::entity;
namespace r = data::record;

namespace sv::in {


class GetLogRecordJson {
public:
    explicit GetLogRecordJson(cm::NetInput in);
    virtual ~GetLogRecordJson() = default;

    bool parse();
    d::AutoId id();

private: // attributes
    cm::NetInput in_;
    d::AutoId id_;

public: // lock
    GetLogRecordJson(GetLogRecordJson&) = delete;
    GetLogRecordJson(GetLogRecordJson&&) = delete;
    GetLogRecordJson &operator = (GetLogRecordJson&) = delete;
    GetLogRecordJson &operator = (GetLogRecordJson&&) = delete;
};

}

#endif //QT_CLIENT_SERVER_LOG_GETLOGRECORDJSON_H
