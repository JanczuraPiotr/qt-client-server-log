//
// Created by piotr@janczura.pl on 2019.04.18
//

#ifndef MODEL_LOGCOLLECTION_H
#define MODEL_LOGCOLLECTION_H

#include <map>

#include <QtSql>
#include <QSqlDatabase>

#include "common/def.h"
#include "common/db/Collection.h"
#include "server/model/LogRecord.h"

namespace model {

class LogRecord;
class LogCollection : public cm::db::Collection {
public:
    std::map<cm::AutoId, model::LogRecord::ptr> map;
    explicit LogCollection() noexcept ;

    cm::AutoId insert(QDateTime timestamp, cm::LogPriority priority, const cm::Message &message);

    [[nodiscard]] QSqlRecord genericRecord() noexcept override;
    [[nodiscard]] LogRecord::ptr get(cm::AutoId autoId) noexcept ;


    //db::Map getAll();

private: // attributes

//    server::SignalBus &signalBus;

};

}



#endif //MODEL_LOGCOLLECTION_H
