//
// Created by piotr@janczura.pl on 2019.11.05
//

#ifndef SERVER_COLLECTION_H
#define SERVER_COLLECTION_H

#include "common/def.h"
#include "common/db/Connection.h"

namespace cm::db {

class Collection {
public:

    explicit Collection() noexcept ;
    virtual ~Collection() = default;

    [[nodiscard]] virtual QSqlRecord genericRecord() = 0;
    [[nodiscard]] virtual cm::AutoId lastInsertId() noexcept ;

protected:

    Connection *connection;

private: // locks
    Collection(const Collection &other) noexcept = default;
    Collection(Collection &&other) noexcept = default;
    Collection& operator = (const Collection& other) noexcept = default;
    Collection& operator = (Collection&& other) noexcept = default;
};

}


#endif //SERVER_COLLECTION_H
