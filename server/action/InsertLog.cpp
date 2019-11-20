//
// Created by piotr@janczura.pl on 2019.11.12
//

#include "InsertLog.h"

namespace sv::action {

InsertLog::InsertLog()
    : timestamp_()
    , logPriority_()
    , message_()
    , id_(0)
    , logCollection_()
{

}

void InsertLog::timestamp(const QDateTime &timestamp)
{
    timestamp_ = timestamp;
}

void InsertLog::logPriority(cm::LogPriority logPriority)
{
    logPriority_ = logPriority;
}

void InsertLog::message(const cm::Message &message)
{
    message_ = message;
}

void InsertLog::make()
{
    id_ = logCollection_.insert(timestamp(), logPriority(), message());
}

QDateTime InsertLog::timestamp() const
{
    return timestamp_;
}

cm::LogPriority InsertLog::logPriority() const
{
    return logPriority_;
}

cm::Message InsertLog::message() const
{
    return message_;
}

cm::AutoId InsertLog::id() const
{
    return id_;
}

}