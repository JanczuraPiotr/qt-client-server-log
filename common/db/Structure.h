//
// Created by piotr@janczura.pl on 2019.11.03
//

#ifndef COMMON_DB_STRUCTURE_H
#define COMMON_DB_STRUCTURE_H

#include <QSqlRecord>

#include "common/def.h"

namespace cm::db {


class Structure {
public:

    Structure() = default;
    virtual ~Structure() = default;

    void initStructure();

protected:

    virtual bool isLog() = 0;
    virtual void initLog() = 0;
};



}



#endif //LOG_STRUCTURE_H
