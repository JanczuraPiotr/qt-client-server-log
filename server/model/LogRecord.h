//
// Created by piotr@janczura.pl on 2019.04.18
//

#ifndef QT_LOG_RECORD_H
#define QT_LOG_RECORD_H

#include <memory>

#include <QDateTime>

#include "common/db/Record.h"

namespace model {

class LogRecord : public cm::db::Record {
friend class LogCollection;
public:

    typedef std::shared_ptr<LogRecord> ptr;
    typedef std::map<cm::AutoId, ptr> map;

    ~LogRecord() override = default;

    void timestamp(const QDateTime &dateTime);
    void priority(cm::LogPriority logPriority);
    void message(const cm::Message &message);

    QDateTime timestamp();
    cm::LogPriority priority();
    cm::Message message();

protected: // methods

    static ptr makeShared(const QSqlRecord& rec);
    explicit LogRecord(const QSqlRecord& rec);

};

}



#endif
