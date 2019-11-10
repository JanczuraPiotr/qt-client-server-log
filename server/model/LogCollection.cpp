//
// Created by piotr@janczura.pl on 2019.04.18
//

#include "LogCollection.h"

namespace model {

LogCollection::LogCollection() noexcept
    : Collection()
    , map()
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
    qDebug() << timestamp << priority << message;
    return 0;
}

//
//LogTable::Map LogTable::getAll() {
//    Map all;
//    QSqlQuery query;
//
//    qDebug() << query.exec("SELECT * FROM log");
//    QSqlRecord rec = query.record();
//
//    while (query.next()) {
//        qDebug() << "id "           << query.value(0);
//        qDebug() << "timestamp "    << query.value(1).toString();
//        qDebug() << "priority "     << query.value(2).toString();
//        qDebug() << "text "         << query.value(3).toString();
//    }
//
//    return all;
//}

}