//
// Created by piotr@janczura.pl on 2019.11.05
//

#include "Collection.h"

#include "common/db/Db.h"

namespace cm::db {

Collection::Collection()
    : connection(Db::connection())
{
}

AutoId Collection::lastInsertId()
{
    return connection->lastInsertId();
}

}

