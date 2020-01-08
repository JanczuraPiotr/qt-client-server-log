//
// Created by piotr@janczura.pl on 2020.01.08
//

#include "DataFromServerToClient.h"

namespace test {

cm::JsonString DataFromServerToClient::getLogsBetween()
{
    static cm::JsonString jsonString = "getLogsBetween|1970-01-01-00-00-00|1970-01-01-01-00-00\n"
                                       "{\n"
                                       "[\n"
                                       "    {\n"
                                       "        \"id\": \"1\",\n"
                                       "        \"message\": \"msg-1\",\n"
                                       "        \"priority\": \"1\",\n"
                                       "        \"timestamp\": \"1070-01-01 00:00:01\"\n"
                                       "    },\n"
                                       "    {\n"
                                       "        \"id\": \"2\",\n"
                                       "        \"message\": \"msg-2\",\n"
                                       "        \"priority\": \"1\",\n"
                                       "        \"timestamp\": \"1970-01-01 00:00:02\"\n"
                                       "    },\n"
                                       "    {\n"
                                       "        \"id\": \"3\",\n"
                                       "        \"message\": \"msg-3\",\n"
                                       "        \"priority\": \"1\",\n"
                                       "        \"timestamp\": \"1970-01-01 00:00:03\"\n"
                                       "    },\n"
                                       "    {\n"
                                       "        \"id\": \"4\",\n"
                                       "        \"message\": \"msg-4\",\n"
                                       "        \"priority\": \"4\",\n"
                                       "        \"timestamp\": \"1970-01-01 00:00:04\"\n"
                                       "    }\n"
                                       "    ]\n"
                                       "}";

    return jsonString;
}

}