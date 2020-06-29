//
// Created by piotr@janczura.pl on 2020.01.08
//

#include "DataFromServerToClient.h"

#include <memory>
#include <QDebug>

namespace test {

data::LogRecord::ptr LogRecord::makeShared(const QString &timestamp, cm::LogPriority priority, const cm::Message &message)
{
    return std::shared_ptr<LogRecord>(
            new LogRecord(
                    QDateTime::fromString(timestamp, cm::DATE_TIME_TEMPLATE.c_str())
                    , priority
                    , message
            )
        );
}

LogRecord::LogRecord(const QDateTime &timestamp, cm::LogPriority priority, const cm::Message &message)
    : data::LogRecord(
            [=](){
                QSqlRecord rec;
                rec.append(QSqlField("timestamp",  QVariant::DateTime));
                rec.append(QSqlField("priority",   QVariant::Int));
                rec.append(QSqlField("message",    QVariant::TextFormat));
                rec.setValue("timestamp", timestamp);
                rec.setValue("priority", static_cast<short>(priority));
                rec.setValue("message", message);
                return rec;
            }())
{

}

cm::JsonString DataFromServerToClient::getLogsBetweenJson()
{
    static cm::JsonString jsonString = R"(getLogsBetween|1970-01-01-00-00-00|1970-01-01-01-00-00{
            "data":[
                {
                    "id": "1",
                    "message": "msg-1",
                    "priority": "1",
                    "timestamp": "1070-01-01 00:00:01"
                },
                {
                    "id": "2",
                    "message": "msg-2",
                    "priority": "1",
                    "timestamp": "1970-01-01 00:00:02"
                },
                {
                    "id": "3",
                    "message": "msg-3",
                    "priority": "1",
                    "timestamp": "1970-01-01 00:00:03"
                },
                {
                    "id": "4",
                    "message": "msg-4",
                    "priority": "4",
                    "timestamp": "1970-01-01 00:00:04"
                }
            ]
        }
    )";

    return jsonString;
}
cm::EBNFString DataFromServerToClient::getLogsBetweenEbnf()
{
    // @work zaprojektować format komunikatu w kodowaniu EBNF
    static cm::EBNFString ebnfString;
//    static cm::JsonString jsonString = R"(getLogsBetween|1970-01-01-00-00-00|1970-01-01-01-00-00{
//            "data":[
//                {
//                    "id": "1",
//                    "message": "msg-1",
//                    "priority": "1",
//                    "timestamp": "1070-01-01 00:00:01"
//                },
//                {
//                    "id": "2",
//                    "message": "msg-2",
//                    "priority": "1",
//                    "timestamp": "1970-01-01 00:00:02"
//                },
//                {
//                    "id": "3",
//                    "message": "msg-3",
//                    "priority": "1",
//                    "timestamp": "1970-01-01 00:00:03"
//                },
//                {
//                    "id": "4",
//                    "message": "msg-4",
//                    "priority": "4",
//                    "timestamp": "1970-01-01 00:00:04"
//                }
//            ]
//        }
//    )";

    return ebnfString;
}

data::LogRecord::ptr DataFromServerToClient::getLogRecord()
{
    data::LogRecord::ptr record = LogRecord::makeShared(
            "1070-01-01 00:00:01"
            , cm::LogPriority::ok
            , "msg-1"
            );
    return record;
}

sv::data::LogRecord::map DataFromServerToClient::getLogMap()
{

}


}