//
// Created by piotr@janczura.pl on 2019.11.24
//

#ifndef QT_CLIENT_SERVER_LogRecord_LogRecord_H
#define QT_CLIENT_SERVER_LogRecord_LogRecord_H

#include <memory>

#include <QtCore/QDateTime>

#include "common/def.h"

namespace cl::model {


class LogRecord {
public:
    typedef std::shared_ptr<LogRecord> ptr;
    typedef std::map<cm::AutoId, ptr> map;

    explicit LogRecord(QDateTime timestamp, cm::LogPriority LopPriority, cm::Message message);
    virtual ~LogRecord() = default;

public: // methods
    [[nodiscard]] QDateTime timestamp();
    [[nodiscard]] cm::LogPriority LogRecordPriority();
    [[nodiscard]] cm::Message message();

private: // attributes
    QDateTime timestamp_;
    cm::LogPriority LogPriority_;
    cm::Message message_;

public: // lock
    LogRecord(const LogRecord &) = delete;
    LogRecord(LogRecord &&) = delete;
    LogRecord &operator = (const LogRecord&) = delete;
    LogRecord &operator = (LogRecord &&) = delete;
};

}



#endif //QT_CLIENT_SERVER_LogRecord_LogRecord_H
