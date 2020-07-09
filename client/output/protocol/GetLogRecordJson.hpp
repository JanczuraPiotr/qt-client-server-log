//
// Created by piotr@janczura.pl on 2020.07.09
//

#ifndef CLIENT_OUTPUT_GETLOGRECORDJSON
#define CLIENT_OUTPUT_GETLOGRECORDJSON

#include "common/def.h"

namespace cl::out {


class GetLogRecordJson {
public:
    explicit GetLogRecordJson();

    cm::JsonString command(cm::AutoId id);

private: // attributes

public: // lock
    GetLogRecordJson(const GetLogRecordJson &) = delete;
    GetLogRecordJson(GetLogRecordJson &&) = delete;
    GetLogRecordJson &operator = (const GetLogRecordJson&) = delete;
    GetLogRecordJson &operator = (GetLogRecordJson &&) = delete;
};

}

#endif
