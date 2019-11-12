//
// Created by piotr@janczura.pl on 2019.11.03
//

#ifndef LOG_STRUCTURE_H
#define LOG_STRUCTURE_H

#include "common/def.h"
#include <QSqlRecord>

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
