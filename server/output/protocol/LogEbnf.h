//
// Created by piotr@janczura.pl on 2020.01.16
//

#ifndef SERVER_OUTPUT_LOGEBNF_H
#define SERVER_OUTPUT_LOGEBNF_H

#include <QDateTime>

#include "common/def.h"
#include "server/model/LogRecord.h"

namespace sv::out {

// @work uruchomić możliwość wyboru protokołu
class LogEBNF {
public:
    LogEBNF() = default;
    virtual ~LogEBNF() = default;

    QString map(data::LogRecord::map records);
    QString one(
            cm::AutoId id
            , const QDateTime &dateTime
            , cm::LogPriority logPriority
            , const cm::Message &message);

public: // lock
    LogEBNF(const LogEBNF &) = delete;
    LogEBNF(LogEBNF &&) = delete;
    LogEBNF &operator = (const LogEBNF&) = delete;
    LogEBNF &operator = (LogEBNF &&) = delete;

};

}

#endif
