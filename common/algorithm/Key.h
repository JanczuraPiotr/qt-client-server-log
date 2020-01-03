//
// Created by piotr@janczura.pl on 2020.01.03
//

#ifndef COMMON_ALGORITHM_INTERVALKEY_H
#define COMMON_ALGORITHM_INTERVALKEY_H

#include <string>

#include "common/def.h"

namespace cm::algorithm {

class Key {
public:
    static cm::Key create(const QString &earlier, const QString &latter);
};

}



#endif
