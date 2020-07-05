//
// Created by piotr@janczura.pl on 2020.07.04
//

#include "Log.hpp"

namespace cm::data::record {

Log::ptr Log::create(AutoId id, entity::Log::ptr log)
{
    return std::shared_ptr<Log>(new Log(id, log));
}

Log::ptr Log::create(AutoId id, const QDateTime &timestamp, cm::LogPriority logPriority, const cm::Message &message)
{
    return std::shared_ptr<Log>(new Log(id, timestamp, logPriority, message));
}

Log::Log(AutoId id, entity::Log::ptr &log)
    : id_(id)
    , log_(log)
{

}

Log::Log(AutoId id, const QDateTime &timestamp, cm::LogPriority logPriority, const cm::Message &message)
    : id_(id)
    , log_(entity::Log::create(timestamp, logPriority, message))
{

}

AutoId Log::id() const
{
    return id_;
}

QDateTime Log::timestamp() const
{
    return log_->timestamp();
}

cm::LogPriority Log::logPriority() const
{
    return log_->logPriority();
}

cm::Message Log::message() const
{
    return log_->message();
}


}