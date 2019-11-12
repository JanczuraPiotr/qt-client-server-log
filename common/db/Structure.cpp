//
// Created by piotr@janczura.pl on 2019.11.03
//

#include "Structure.h"

namespace cm::db {

void Structure::initStructure()
{
    if ( ! isLog()) {
        initLog();
    }
}

}
