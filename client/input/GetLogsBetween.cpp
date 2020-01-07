//
// Created by piotr@janczura.pl on 2020.01.07
//

#include "GetLogsBetween.h"

namespace cl::input {

GetLogsBetween::GetLogsBetween(const cm::NetInput &input, cm::Index lim)
        : input(input), lim(lim) {
}

bool GetLogsBetween::parse()
{
    return false;
}

}