//
// Created by piotr@janczura.pl on 2019.12.15
//

#include "GetLogsAfter.h"

#include "common/def.h"

namespace sv::input {

GetLogsAfter::GetLogsAfter(const QString &input, int lim)
    : input(input)
    , lim(lim)
{
}

bool GetLogsAfter::parse()
{
    // "getLogsAfter|".length() = 13
    if (input.length() - cm::DATE_TIME_TEMPLATE.length() != 13) {
        return false;
    }

    borderMoment = QDateTime::fromString(input.mid(lim + 1) , cm::DATE_TIME_TEMPLATE.c_str());
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