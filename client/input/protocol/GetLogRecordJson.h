//
// Created by piotr@janczura.pl on 2020.01.16
//

#ifndef CLIENT_INPUT_GETLOGRECORDJSON
#define CLIENT_INPUT_GETLOGRECORDJSON

#include "common/def.h"
#include "common/data/entity/Log.hpp"
#include "common/data/record/Log.hpp"

namespace cl::in {

namespace ent = data::entity;
namespace rec = data::record;

class GetLogRecordJson {
public:
    explicit GetLogRecordJson(cm::NetInput &&input);
    virtual ~GetLogRecordJson() = default;

    bool parse();
    rec::Log::ptr record();

private: //attributes
    cm::NetInput input_;
    rec::Log::ptr logRec_;

public: // lock
    GetLogRecordJson(const GetLogRecordJson &) = delete;
    GetLogRecordJson(GetLogRecordJson &&) = delete;
    GetLogRecordJson &operator = (const GetLogRecordJson&) = delete;
    GetLogRecordJson &operator = (GetLogRecordJson &&) = delete;
};

}


#endif //QT_CLIENT_SERVER_LOG_LOGJSON_H
