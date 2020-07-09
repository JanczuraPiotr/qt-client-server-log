//
// Created by piotr@janczura.pl on 2020.01.16
//
#include "GetLogsBetweenJson.h"

#include <QDebug>

#include "gtest/tools-and-fakes/ResponseFromServerToClient.hpp"
#include "server/output/protocol/GetLogsBetweenJson.h"

namespace test {

TEST_F(Server_Output_GetLogsBetweenJson, one_1)
{
    auto record(test::ResponseFromServerToClient::getLogRecord());
    sv::out::GetLogsBetweenJson out;
    auto jsonString = out.one(record->id(), record->timestamp(), record->priority(), record->message());

    EXPECT_EQ(jsonString.replace('\n',"").replace(' ', "").replace('\\', ""), R"({"id":"0","message":"msg-1","priority":"1","timestamp":"1070-01-0100:00:01"})");
}

TEST_F(Server_Output_GetLogsBetweenJson, map_1)
{
    auto map(test::ResponseFromServerToClient::getLogsBetweenJson_Many());
    EXPECT_TRUE(false);
}

}