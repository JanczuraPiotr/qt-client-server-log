//
// Created by piotr@janczura.pl on 2019.12.15
//

#include "GetLogsBefore.h"

#include <QDebug>
#include "common/def.h"

namespace sv::input {


GetLogsBefore::GetLogsBefore(const QString &input, int lim)
    : input(input)
    , lim(lim)
{

}

bool GetLogsBefore::parse()
{
    // "getLogsBefore|".length() = 14
    if (input.length() - cm::DATE_TIME_TEMPLATE.length() != 14) {
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