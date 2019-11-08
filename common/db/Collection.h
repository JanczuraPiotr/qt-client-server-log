//
// Created by piotr@janczura.pl on 2019.11.05
//

#ifndef QT_CLIENT_SERVER_LOG_COLLECTION_H
#define QT_CLIENT_SERVER_LOG_COLLECTION_H

#include "common/def.h"
#include "common/db/Connection.h"

namespace cm::db {

class Collection {
public:

    explicit Collection();
    virtual ~Collection() = default;

    virtual Params params() = 0;
    virtual QSqlRecord genericRecord() = 0;

    virtual cm::AutoId lastInsertId();

protected:

    Connection *connection;

private: // locks

    Collection(const Collection &other) noexcept = default;
    Collection(Collection &&other) noexcept = default;
    Collection& operator = (const Collection& other) noexcept = default;
    Collection& operator = (Collection&& other) noexcept = default;
};

}


#endif //QT_CLIENT_SERVER_LOG_COLLECTION_H
