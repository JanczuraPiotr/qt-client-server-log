//
// Created by piotr@janczura.pl on 2020.07.04
//

#include "Log.hpp"

namespace data::record {

Log::Log(AutoId id, const entity::Log &log)
    : id_(id)
    , log_(log)
{

}

Log::Log(AutoId id, QDateTime timestamp, cm::LogPriority logPriority, cm::Message message)
    : id_(id)
    , log_(std::move(timestamp), logPriority, std::move(message))
{

}

AutoId Log::id() const
{
    return id_;
}

QDateTime Log::timestamp() const
{
    return log_.timestamp();
}

cm::LogPriority Log::logPriority() const
{
    return log_.logPriority();
}

cm::Message Log::message() const
{
    return log_.message();
}


}