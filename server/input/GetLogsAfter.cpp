//
// Created by piotr@janczura.pl on 2019.12.15
//

#include "GetLogsAfter.h"

#include <QDebug>

namespace sv::input {

GetLogsAfter::GetLogsAfter(const QString &input, int lim)
    : input(input)
    , lim(lim)
{
}

bool GetLogsAfter::parse()
{
    return false;
}

QDateTime GetLogsAfter::getBorderMoment()
{
    return QDateTime();
}

}