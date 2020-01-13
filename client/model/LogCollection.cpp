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

LogRecord::map::iterator LogCollection::getBegin()
{
    return records.begin();
}

LogRecord::map::iterator LogCollection::getEnd()
{
    return records.end();
}

// @task happy path
LogRecord::ptr LogCollection::getById(cm::AutoId id) {
    return records[id];
}

LogRecord::ptr LogCollection::insert(
        cm::AutoId id
        , const QDateTime &timestamp
        , cm::LogPriority priority
        , const cm::Message &message)
{
    LogRecord::ptr record = LogRecord::makeShared(
            id
            , timestamp
            , priority
            , message
            );
    records.insert(std::make_pair(id, record));
    return record;
}

cm::Size LogCollection::size()
{
    return records.size();
}

}