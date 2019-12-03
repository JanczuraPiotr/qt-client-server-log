//
// Created by piotr@janczura.pl on 2019.11.24
//

#ifndef QT_CLIENT_SERVER_LOG_LOG_H
#define QT_CLIENT_SERVER_LOG_LOG_H

#include <QDateTime>

#include "common/def.h"

namespace cl::input {

class Log {
public:
    explicit Log();
    virtual ~Log() = default;

    void parse(const cm::JsonString &log);

    QDateTime getTimestamp();
    cm::AutoId getLogId();
    cm::LogPriority getLogPriority();
    cm::Message getMessage();

private: // attributes
    QDateTime timestamp;
    cm::AutoId logId;
    cm::LogPriority logPriority;
    cm::Message message;

public: // lock
    Log(const Log &) = delete;
    Log(Log &&) = delete;
    Log &operator = (const Log&) = delete;
    Log &operator = (Log &&) = delete;
};

}



#endif //QT_CLIENT_SERVER_LOG_LOG_H