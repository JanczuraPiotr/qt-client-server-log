//
// Created by piotr@janczura.pl on 2019.12.15
//

#include "GetLogsBefore.h"

#include <QDebug>
#include <utility>

namespace sv::input {


GetLogsBefore::GetLogsBefore(cm::NetInput input, cm::Index lim)
    : input(std::move(input))
    , lim(lim)
    , borderMoment()
{

}

bool GetLogsBefore::parse()
{
    // "getLogsBefore|".length() = 14
    if (input.length() - static_cast<cm::Index>(cm::DATE_TIME_TEMPLATE.length()) != 14) {
        return false;
    }

    borderMoment = QDateTime::fromString(input.mid(lim + 1) , cm::DATE_TIME_TEMPLATE.c_str());
    if (!borderMoment.isValid()){
        return false;
    }

    return true;
}

QDateTime GetLogsBefore::getBorderMoment()
{
    return borderMoment;
}

}