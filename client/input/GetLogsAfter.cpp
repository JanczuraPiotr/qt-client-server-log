//
// Created by piotr@janczura.pl on 2020.01.07
//

#include "GetLogsAfter.h"

namespace cl::input {

GetLogsAfter::GetLogsAfter(const cm::NetInput &input, cm::Index lim)
    : input(input)
    , lim(lim)
{

}

bool GetLogsAfter::parse()
{
    return false;
}

}