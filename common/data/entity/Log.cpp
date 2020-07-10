//
// Created by piotr@janczura.pl on 2020.07.04
//

#include "Log.hpp"

#include <utility>

namespace data::entity {

Log::ptr Log::create()
{
    return std::shared_ptr<Log>(new Log());
}

Log::ptr Log::create(const QDateTime &timestamp, cm::LogPriority logPriority, const cm::Message &message)
{
    return std::shared_ptr<Log>(new Log(timestamp, logPriority, message));
}


Log::Log(const QDateTime &timestamp, cm::LogPriority logPriority, const cm::Message &message)
    : timestamp_(timestamp)
    , logPriority_(logPriority)
    , message_(message)
{

}

bool Log::isOk()
{
    return (timestamp_.isValid() && !message_.isEmpty());
}

void Log::timestamp(const QDateTime &dateTime)
{
    timestamp_ = dateTime;
}

void Log::logPriority(cm::LogPriority logPriority)
{
    logPriority_ = logPriority;
}

void Log::logPriority(unsigned logPriority)
{
    logPriority_ = static_cast<cm::LogPriority>(logPriority);
}

void Log::message(const cm::Message &message)
{
    message_ = message;
}

QDateTime Log::timestamp() const
{
    return timestamp_;
}

cm::LogPriority Log::logPriority() const
{
    return logPriority_;
}

cm::Message Log::message() const
{
    return message_;
}

}