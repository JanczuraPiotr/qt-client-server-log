//
// Created by piotr@janczura.pl on 2020.01.08
//

#include "ResponseFromServerToClient.hpp"

#include <memory>
#include <QDebug>

namespace test {


r::Log::ptr ResponseFromServerToClient::getLogRecord()
{
    r::Log::ptr record = r::Log::create(
            1
            , QDateTime::fromString("1970-01-01 00:00:01", cm::DATE_TIME_TEMPLATE.c_str())
            , cm::LogPriority::ok
            , "msg-1"
    );
    return record;
}

cm::JsonString ResponseFromServerToClient::getLogById()
{
    static cm::JsonString jsonString = R"(
        {
            "data": {
                    "id": "1",
                    "message": "msg-1",
                    "priority": "1",
                    "timestamp": "1970-01-01 00:00:01"
            },
            "header" : {
                "command": "getLogById",
                "logId" : "1"
            }
        }
    )";

    return jsonString;

}


cm::JsonString ResponseFromServerToClient::getLogsBetweenJson_Empty()
{
    static cm::JsonString jsonString = R"(
        {
            "header" : {
                "command": "getLogsBetween",
                "timeFrom": "1970-01-01 00:00:00",
                "timeTo": "1970-01-01 01:00:00"
            },
            "data":[
            ]
        }
    )";

    return jsonString;
}

cm::JsonString ResponseFromServerToClient::getLogsBetweenJson_One()
{
    static cm::JsonString jsonString = R"(
        {
            "data": [
                {
                    "id": "1",
                    "message": "msg-1",
                    "priority": "1",
                    "timestamp": "1970-01-01 00:00:01"
                }
            ],
            "header": {
                "command": "getLogsBetween",
                "timeFrom": "1970-01-01 00:00:00",
                "timeTo": "1970-01-01 01:00:00"
            }
        }
    )";

    return jsonString;
}

cm::JsonString ResponseFromServerToClient::getLogsBetweenJson_Many()
{
    static cm::JsonString jsonString = R"(
        {
            "data":[
                {
                    "id": "1",
                    "message": "msg-1",
                    "priority": "1",
                    "timestamp": "1970-01-01 00:00:01"
                },
                {
                    "id": "2",
                    "message": "msg-2",
                    "priority": "2",
                    "timestamp": "1970-01-01 00:00:02"
                },
                {
                    "id": "3",
                    "message": "msg-3",
                    "priority": "3",
                    "timestamp": "1970-01-01 00:00:03"
                },
                {
                    "id": "4",
                    "message": "msg-4",
                    "priority": "4",
                    "timestamp": "1970-01-01 00:00:04"
                }
            ],
            "header" : {
                "command": "getLogsBetween",
                "timeFrom": "1970-01-01 00:00:00",
                "timeTo": "1970-01-01 01:00:00"
            }
        }
    )";

    return jsonString;
}

r::Log::map ResponseFromServerToClient::getLogsBetweenMap_Many()
{
    r::Log::map map;

    map.insert(std::make_pair(1, r::Log::create(1, QDateTime::fromString("1970-01-01 00:00:01", cm::DATE_TIME_TEMPLATE.c_str()), cm::LogPriority::ok, "msg-1")));
    map.insert(std::make_pair(2, r::Log::create(2, QDateTime::fromString("1970-01-01 00:00:02", cm::DATE_TIME_TEMPLATE.c_str()), cm::LogPriority::info, "msg-2")));
    map.insert(std::make_pair(3, r::Log::create(3, QDateTime::fromString("1970-01-01 00:00:03", cm::DATE_TIME_TEMPLATE.c_str()), cm::LogPriority::warning, "msg-3")));
    map.insert(std::make_pair(4, r::Log::create(4, QDateTime::fromString("1970-01-01 00:00:04", cm::DATE_TIME_TEMPLATE.c_str()), cm::LogPriority::error, "msg-4")));

    return map;
}

cm::EBNFString ResponseFromServerToClient::getLogsBetweenEbnf()
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

r::Log::map ResponseFromServerToClient::getLogMap()
{
    return {};
}


}