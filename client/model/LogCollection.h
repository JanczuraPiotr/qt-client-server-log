//
// Created by piotr@janczura.pl on 2019.11.24
//

#ifndef QT_CLIENT_SERVER_LOG_LOGCOLLECTION_H
#define QT_CLIENT_SERVER_LOG_LOGCOLLECTION_H

#include <memory>
#include <QDateTime>
#include "common/def.h"
#include "client/model/LogRecord.h"

namespace cl::model {

class LogRecord;
class LogCollection {
public:
    typedef std::shared_ptr<LogCollection> ptr;

    explicit LogCollection();
    virtual ~LogCollection() = default;

    void insert(cm::AutoId logId, const QDateTime &timestamp, cm::LogPriority logPriority, const cm::Message &message);

private: // attributes
    LogRecord::map records;

public: // lock
    LogCollection(const LogCollection &) noexcept = delete;
    LogCollection(LogCollection &&) noexcept = delete;
    LogCollection &operator = (const LogCollection&) noexcept = delete;
    LogCollection &operator = (LogCollection &&) noexcept = delete;
    
};

}



#endif //QT_CLIENT_SERVER_LOG_LOGCOLLECTION_H
