//
// Created by piotr@janczura.pl on 2019.04.18
//

#ifndef QT_LOG_COLLECTION_H
#define QT_LOG_COLLECTION_H

#include <memory>
#include "common/db/Record.h"

namespace model {

class LogRecord : public cm::db::Record {
friend class LogCollection;
public:

    typedef std::shared_ptr<LogRecord> ptr;
    typedef std::map<cm::AutoId, ptr> map;

    ~LogRecord() override = default;

protected: // methods

    static ptr makeShared(const QSqlRecord& rec);
    LogRecord();
    explicit LogRecord(const QSqlRecord& rec);

private: // locks

    LogRecord(const LogRecord &other) = default;
    LogRecord(LogRecord &&other) = default;
    LogRecord& operator = (const LogRecord& other) = default;
    LogRecord& operator = (LogRecord&& other) = default;
};

}



#endif //QT_LOG_COLLECTION_H
