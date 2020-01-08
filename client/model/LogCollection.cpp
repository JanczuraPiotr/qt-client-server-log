//
// Created by piotr@janczura.pl on 2019.11.24
//

#include "LogCollection.h"
#include <QDebug>

namespace cl::model {

LogCollection::ptr LogCollection::makeShared() {
    return std::shared_ptr<LogCollection>(new LogCollection());
}

LogCollection::LogCollection()
    : records(LogRecord::map())
{

}

// @task happy path
LogRecord::ptr LogCollection::getById(cm::AutoId id) {
    return records[id];
}

LogRecord::ptr LogCollection::insert(
        cm::AutoId logId
        , const QDateTime &timestamp
        , cm::LogPriority logPriority
        , const cm::Message &message)
{
    LogRecord::ptr record = LogRecord::makeShared(
            logId
            , timestamp
            , logPriority
            , message
            );
    records.insert(std::make_pair(logId, record));
    return record;
}

cm::Size LogCollection::size()
{
    return records.size();
}

}