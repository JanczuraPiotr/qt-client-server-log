//
// Created by piotr@janczura.pl on 2019.11.19
//

#ifndef SERVER_OUTPUT_LOG
#define SERVER_OUTPUT_LOG

#include <QDateTime>
#include <server/model/LogRecord.h>

#include "common/def.h"


namespace sv::output {

class Log {
public:
    Log() = default;
    virtual ~Log() = default;

    cm::JsonString map(model::LogRecord::map records);
    cm::JsonString json(
            cm::AutoId id
            , const QDateTime &dateTime
            , cm::LogPriority logPriority
            , const cm::Message &message);

public: // lock
    Log(const Log &) = delete;
    Log(Log &&) = delete;
    Log &operator = (const Log&) = delete;
    Log &operator = (Log &&) = delete;
};


}


#endif
