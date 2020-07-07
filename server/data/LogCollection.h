//
// Created by piotr@janczura.pl on 2019.04.18
//

#ifndef SERVER_MODEL_LOGCOLLECTION
#define SERVER_MODEL_LOGCOLLECTION

#include <map>

#include <QtSql>
#include <QSqlDatabase>
#include <QDateTime>

#include "common/def.h"
#include "common/db/Collection.h"
#include "server/data/LogRecord.h"

namespace sv::data {

class LogRecord;
class LogCollection : public cm::db::Collection {
public:
    explicit LogCollection() noexcept ;

    LogRecord::map getLogsAfter(const QDateTime &limit);
    LogRecord::map getLogsBefore(const QDateTime &limit);
    LogRecord::map getLogsBetween(const QDateTime &limitEarlier, const QDateTime &limitLatter);

    cm::AutoId insert(QDateTime timestamp, cm::LogPriority priority, const cm::Message &message);

    [[nodiscard]] QSqlRecord genericRecord() noexcept override;
    [[nodiscard]] LogRecord::ptr get(cm::AutoId autoId) noexcept;

private: // attributes

};

}



#endif
