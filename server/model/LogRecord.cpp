//
// Created by piotr@janczura.pl on 2019.04.18
//

#include "LogRecord.h"

namespace sv::model {

LogRecord::ptr LogRecord::makeShared(const QSqlRecord &rec)
{
    return std::shared_ptr<LogRecord>(new LogRecord(rec));
}

LogRecord::LogRecord(const QSqlRecord& record)
        : Record(record)
{

}

void LogRecord::timestamp(const QDateTime &dateTime)
{
    rec.setValue("timestamp", dateTime);
}

void LogRecord::priority(cm::LogPriority logPriority)
{
    rec.setValue("priority", static_cast<short>(logPriority));
}

void LogRecord::message(const cm::Message &message)
{
    rec.setValue("message", message);
}

QDateTime LogRecord::timestamp()
{
    return rec.value("timestamp").toDateTime();
}

cm::LogPriority LogRecord::priority()
{
    return static_cast<cm::LogPriority >(rec.value("priority").toInt());
}

cm::Message LogRecord::message()
{
    return rec.value("message").toString();
}



}