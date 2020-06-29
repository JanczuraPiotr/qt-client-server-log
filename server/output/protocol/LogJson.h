//
// Created by piotr@janczura.pl on 2020.01.16
//

#ifndef SERVER_OUTPUT_LOGJSON
#define SERVER_OUTPUT_LOGJSON

#include <QDateTime>

#include "common/def.h"
#include "server/model/LogRecord.h"

namespace sv::out {

class LogJson {
public:
    LogJson() = default;
    virtual ~LogJson() = default;

    QString map(data::LogRecord::map records);
    QString one(
            cm::AutoId id
            , const QDateTime &dateTime
            , cm::LogPriority logPriority
            , const cm::Message &message);

public: // lock
    LogJson(const LogJson &) = delete;
    LogJson(LogJson &&) = delete;
    LogJson &operator = (const LogJson&) = delete;
    LogJson &operator = (LogJson &&) = delete;
};

}

#endif
