//
// Created by piotr@janczura.pl on 2019.04.18
//

#ifndef QT_LOG_LOG_COLLECTION_H
#define QT_LOG_LOG_COLLECTION_H

#include <map>

#include <QtSql>
#include <QSqlDatabase>

#include "common/def.h"
#include "common/db/Collection.h"
#include "LogRecord.h"

namespace model {

class LogRecord;
class LogCollection : public cm::db::Collection {
public:
    std::map<cm::AutoId, model::LogRecord::ptr> map;
    explicit LogCollection() noexcept ;

    [[nodiscard]] QSqlRecord genericRecord() noexcept override;

    [[nodiscard]] LogRecord::ptr get() noexcept ;


    //db::Map getAll();

};

}



#endif //QT_LOG_LOG_COLLECTION_H
