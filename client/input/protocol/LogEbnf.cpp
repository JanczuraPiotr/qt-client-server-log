//
// Created by piotr@janczura.pl on 2020.01.16
//

#include "LogEbnf.h"

#include <boost/spirit/include/karma.hpp>


namespace cl::in {

LogEBNF::LogEBNF(cm::NetInput input, cm::Index lim)
    : input(input)
    , lim(lim)
    , timestamp(QDateTime::fromString("1970-01-01 00:00:00", cm::DATE_TIME_TEMPLATE.c_str()))
    , id(0)
    , priority(static_cast<cm::LogPriority>(0))
    , message("")
{
}

bool LogEBNF::parse()
{
    bool result = false;

    return result;
}

QDateTime LogEBNF::getTimestamp() const noexcept
{
    return timestamp;
}

cm::AutoId LogEBNF::getId() const noexcept
{
    return id;
}

cm::LogPriority LogEBNF::getPriority() const noexcept
{
    return priority;
}

cm::Message LogEBNF::getMessage() const noexcept
{
    return message;
}


}