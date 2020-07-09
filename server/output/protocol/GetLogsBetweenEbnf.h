//
// Created by piotr@janczura.pl on 2020.01.16
//

#ifndef SERVER_OUTPUT_LOGEBNF_H
#define SERVER_OUTPUT_LOGEBNF_H

#include <QDateTime>

#include "common/def.h"
#include "server/data/LogRecord.h"

namespace sv::out {

// @work uruchomić możliwość wyboru protokołu
class GetLogsBetweenEbnf {
public:
    GetLogsBetweenEbnf() = default;
    virtual ~GetLogsBetweenEbnf() = default;

    QString map(data::LogRecord::map records);
    QString one(
            cm::AutoId id
            , const QDateTime &dateTime
            , cm::LogPriority logPriority
            , const cm::Message &message);

public: // lock
    GetLogsBetweenEbnf(const GetLogsBetweenEbnf &) = delete;
    GetLogsBetweenEbnf(GetLogsBetweenEbnf &&) = delete;
    GetLogsBetweenEbnf &operator = (const GetLogsBetweenEbnf&) = delete;
    GetLogsBetweenEbnf &operator = (GetLogsBetweenEbnf &&) = delete;

};

}

#endif
