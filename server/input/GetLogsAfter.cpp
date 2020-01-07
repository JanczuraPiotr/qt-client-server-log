//
// Created by piotr@janczura.pl on 2019.12.15
//

#include "GetLogsAfter.h"

#include <utility>
#include <QDebug>


namespace sv::input {

GetLogsAfter::GetLogsAfter(cm::NetInput input, cm::Index lim)
    : input(std::move(input))
    , lim(lim)
    , borderMoment()
{
}

bool GetLogsAfter::parse()
{
    // "getLogsAfter|".length() = 13
    if (input.length() - static_cast<cm::Index>(cm::DATE_TIME_IN_COMMAND_TEMPLATE.length()) != 13) {
        return false;
    }

    borderMoment = QDateTime::fromString(input.mid(static_cast<int>(lim + 1)) , cm::DATE_TIME_IN_COMMAND_TEMPLATE.c_str());
    if(!borderMoment.isValid()) {
        return false;
    }

    return true;
}

QDateTime GetLogsAfter::getBorderMoment()
{
    return borderMoment;
}

}