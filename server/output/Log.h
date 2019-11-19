//
// Created by piotr@janczura.pl on 2019.11.19
//

#ifndef QT_CLIENT_SERVER_LOG_LOG_H
#define QT_CLIENT_SERVER_LOG_LOG_H

#include <QDateTime>

#include "common/def.h"


namespace output {

class Log {
public:
    Log() = default;
    virtual ~Log() = default;

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


#endif //QT_CLIENT_SERVER_LOG_LOG_H
