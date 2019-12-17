//
// Created by piotr@janczura.pl on 2019.12.15
//

#include "GetLogsBefore.h"

namespace sv::input {


GetLogsBefore::GetLogsBefore(const QString &input, int lim)
    : input(input)
    , lim(lim)
{

}

bool GetLogsBefore::parse()
{
    return  false;
}

QDateTime GetLogsBefore::getBorderMoment()
{
    return QDateTime();
}

}