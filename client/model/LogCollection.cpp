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

void LogCollection::insert(cm::AutoId logId, const QDateTime &timestamp, cm::LogPriority logPriority, const cm::Message &message) {
    LogRecord::ptr record = LogRecord::makeShared(
            logId
            , timestamp
            , logPriority
            , message
            );
    qDebug() << "LogCollection::insert :"<< timestamp << logId << static_cast<int>(logPriority) << message;
    records.insert(std::make_pair(logId, record));
}

}