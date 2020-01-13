//
// Created by piotr@janczura.pl on 2020.01.08
//

#include "DataFromServerToClient.h"

namespace test {

cm::JsonString DataFromServerToClient::getLogsBetween()
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

}