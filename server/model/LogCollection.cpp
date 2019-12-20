//
// Created by piotr@janczura.pl on 2019.04.18
//

#include "LogCollection.h"

namespace sv::model {

LogCollection::LogCollection() noexcept
    : Collection()
{
}

QSqlRecord LogCollection::genericRecord() noexcept
{
    QSqlRecord rec;
    rec.append(QSqlField("timestamp",  QVariant::DateTime));
    rec.append(QSqlField("priority",   QVariant::Int));
    rec.append(QSqlField("message",    QVariant::TextFormat));
    return rec;
}

LogRecord::ptr LogCollection::get(cm::AutoId autoId) noexcept
{
    std::ignore = autoId;
    return model::LogRecord::makeShared(genericRecord());
}

cm::AutoId LogCollection::insert(QDateTime timestamp, cm::LogPriority priority, const cm::Message &message)
{
    QString query = "INSERT INTO log (timestamp, priority, message) VALUES (:timestamp,:priority,:message)";
    cm::Params params = {
            {":timestamp", timestamp},
            {":priority", static_cast<short>(priority)},
            {":message", message}
    };

    return connection->insert(query, params);
}

LogRecord::map LogCollection::getLogsAfter(const QDateTime &limit)
{
    QSqlQuery query;
    query.prepare("SELECT id, timestamp, priority, message FROM log WHERE timestamp < :limit");
    query.bindValue(":limit", limit);
    query.exec();
    LogRecord::map map;
    while (query.next()) {
        auto record = LogRecord::makeShared(query.record());
        map.insert(std::make_pair(record->id(), record));
    }
    return map;
}

LogRecord::map LogCollection::getLogsBefore(const QDateTime &limit)
{
    QSqlQuery query;
    query.prepare("SELECT id, timestamp, priority, message FROM log WHERE timestamp > :limit");
    query.bindValue(":limit", limit);
    query.exec();
    LogRecord::map map;
    while (query.next()) {
        auto record = LogRecord::makeShared(query.record());
        map.insert(std::make_pair(record->id(), record));
    }
    return map;
}

LogRecord::map LogCollection::getLogsBetween(const QDateTime &limitEarlier, const QDateTime &limitLatter)
{
    QSqlQuery query;
    query.prepare("SELECT id, timestamp, priority, message FROM log WHERE timestamp between :earlier and :latter");
    query.bindValue(":earlier", limitEarlier);
    query.bindValue(":latter", limitLatter);
    query.exec();
    LogRecord::map map;
    while (query.next()) {
        auto record = LogRecord::makeShared(query.record());
        map.insert(std::make_pair(record->id(), record));
    }
    return map;
}


}