//
// Created by piotr@janczura.pl on 2019.12.15
//

#include "GetLogsBetween.h"

#include <QDebug>
#include <utility>
#include "common/def.h"

namespace sv::input {

GetLogsBetween::GetLogsBetween(QString input, int lim)
    : input(std::move(input))
    , lim(lim)
{

}

bool GetLogsBetween::parse()
{
    // getLogsBetween|yyyy-MM-dd hh:mm:ss|yyyy-MM-dd hh:mm:ss"
    const int CORRECT_INPUT_LONG = 54;
    const int FIRST_LIM_INDEX = lim;
    const int LAST_LIM_INDEX = lim + cm::DATE_TIME_TEMPLATE.length() + 1;

    if (input.length() != CORRECT_INPUT_LONG) {
        return false;
    }
    if (input.at(FIRST_LIM_INDEX) != '|' && input.at(LAST_LIM_INDEX) != '|') {
        return false;
    }

    borderEarlier = QDateTime::fromString(input.mid(FIRST_LIM_INDEX + 1, cm::DATE_TIME_TEMPLATE.length()), cm::DATE_TIME_TEMPLATE.c_str());
    if (!borderEarlier.isValid()) {
        return false;
    }

    borderLatter  = QDateTime::fromString(input.mid(LAST_LIM_INDEX + 1, cm::DATE_TIME_TEMPLATE.length()), cm::DATE_TIME_TEMPLATE.c_str());
    if (!borderLatter.isValid()) {
        return false;
    }

    return true;
}

QDateTime GetLogsBetween::getBorderEarlier()
{
    return borderEarlier;
}

QDateTime GetLogsBetween::getBorderLatter()
{
    return borderLatter;
}



}