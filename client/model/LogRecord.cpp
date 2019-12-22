//
// Created by piotr@janczura.pl on 2019.11.24
//

#include "LogRecord.h"

namespace cl::model{

LogRecord::ptr LogRecord::makeShared(
        cm::AutoId logId
        , const QDateTime &timestamp
        , cm::LogPriority logPriority
        , const cm::Message &message)
{
    return std::shared_ptr<LogRecord>(new LogRecord(logId, timestamp, logPriority, message));
}

LogRecord::LogRecord(cm::AutoId logId, QDateTime timestamp, cm::LogPriority logPriority, cm::Message message)
    : timestamp(std::move(timestamp))
    , logId(logId)
    , logPriority(logPriority)
    , message(std::move(message))
{
}

QDateTime LogRecord::getTmestamp()
{
    return timestamp;
}

cm::AutoId LogRecord::getAutoId()
{
    return logId;
}

cm::LogPriority LogRecord::getLogRecordPriority()
{
    return logPriority;
}

cm::Message LogRecord::getMessage()
{
    return message;
}


}