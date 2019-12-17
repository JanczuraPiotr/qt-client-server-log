//
// Created by piotr@janczura.pl on 2019.12.15
//

#include "GetLogsBetween.h"

namespace sv::input {

GetLogsBetween::GetLogsBetween(const QString &input, int lim)
    : input(input)
    , lim(lim)
{

}

bool GetLogsBetween::parse() {
    return false;
}

QDateTime GetLogsBetween::getBorderEarlier()
{
    return QDateTime();
}

QDateTime GetLogsBetween::getBorderLatter()
{
    return QDateTime();
}



}