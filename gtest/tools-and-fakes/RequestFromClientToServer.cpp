//
// Created by piotr@janczura.pl on 2020.07.04
//

#include "RequestFromClientToServer.hpp"

namespace test {

cm::JsonString RequestFromClientToServer::getLogsBetweenJson()
{
    static cm::JsonString jsonString = R"(
        {
            "command": "getLogsBetween",
            "timeEarlier": "1970-01-01 00:00:00",
            "timeLatter": "1970-01-01 01:00:00"
        }
    )";

return jsonString;
}



}