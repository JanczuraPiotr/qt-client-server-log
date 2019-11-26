//
// Created by piotr@janczura.pl on 2019.11.24
//

#include "LogCollection.h"
#include <QDebug>

namespace cl::model {


LogCollection::LogCollection()
    : records(LogRecord::map())
{

}

void LogCollection::insert(
        const QDateTime &timestamp
        , cm::AutoId logId
        , cm::LogPriority logPriority
        , const cm::Message &message
) {
    LogRecord::ptr record = LogRecord::makeShared(
            timestamp
            , logId
            , logPriority
            , message
            );
    records.insert(std::make_pair(logId, record));
}

}