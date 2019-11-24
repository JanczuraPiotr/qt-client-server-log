//
// Created by piotr@janczura.pl on 2019.11.24
//

#include "LogRecord.h"

#include <utility>

namespace cl::model{

LogRecord::LogRecord(QDateTime timestamp, cm::LogPriority LogPriority, cm::Message message)
    : timestamp_(std::move(timestamp))
    , LogPriority_(LogPriority)
    , message_(std::move(message))
{
}

QDateTime LogRecord::timestamp()
{
    return timestamp_;
}

cm::LogPriority LogRecord::LogRecordPriority()
{
    return LogPriority_;
}

cm::Message LogRecord::message()
{
    return message_;
}


}