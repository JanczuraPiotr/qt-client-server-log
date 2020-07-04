//
// Created by piotr@janczura.pl on 2020.01.16
//
#include "LogJson.h"

#include <QDebug>

#include "gtest/tools-and-fakes/ResponseFromServerToClient.hpp"
#include "server/output/protocol/LogJson.h"

namespace test {

TEST_F(Server_Output_LogJson, one_1)
{
    auto record(test::ResponseFromServerToClient::getLogRecord());
    sv::out::LogJson out;
    auto jsonString = out.one(record->id(), record->timestamp(), record->priority(), record->message());

    EXPECT_EQ(jsonString.replace('\n',"").replace(' ', "").replace('\\', ""), R"({"id":"0","message":"msg-1","priority":"1","timestamp":"1070-01-0100:00:01"})");
}

TEST_F(Server_Output_LogJson, map_1)
{
    EXPECT_TRUE(false);
}

}