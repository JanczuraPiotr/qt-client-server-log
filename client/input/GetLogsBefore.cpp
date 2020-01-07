//
// Created by piotr@janczura.pl on 2020.01.07
//

#include "GetLogsBefore.h"

namespace cl::input {

GetLogsBefore::GetLogsBefore(const cm::NetInput &input, cm::Index lim)
    : input(input)
    , lim(lim)
{

}

bool GetLogsBefore::parse()
{
    return false;

}

}