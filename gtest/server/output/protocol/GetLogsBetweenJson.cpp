//
// Created by piotr@janczura.pl on 2020.01.16
//
#include "GetLogsBetweenJson.h"

#include <QDebug>

#include "gtest/tools-and-fakes/ResponseFromServerToClient.hpp"
#include "common/algorithm/String.h"
#include "server/output/protocol/GetLogsBetweenJson.h"

namespace test {

TEST_F(Server_Output_GetLogsBetweenJson, one_1)
{
    auto record(test::ResponseFromServerToClient::getLogRecord());
    sv::out::GetLogsBetweenJson out;
    auto jsonString = out.one(record->id(), record->timestamp(), record->logPriority(), record->message());

    EXPECT_EQ(jsonString.replace('\n',"").replace(' ', "").replace('\\', ""), R"({"id":"1","message":"msg-1","priority":"1","timestamp":"1070-01-0100:00:01"})");
}

TEST_F(Server_Output_GetLogsBetweenJson, map_1)
{
    QString command("getLogsBetween");
    QDateTime timeFrom(QDateTime::fromString("1970-01-01 00:00:00", cm::DATE_TIME_TEMPLATE.c_str()));
    QDateTime toFrom(QDateTime::fromString("1970-01-01 10:00:0", cm::DATE_TIME_TEMPLATE.c_str()));
    sv::out::GetLogsBetweenJson out;


    EXPECT_EQ(alg::String::condense(ResponseFromServerToClient::getLogsBetweenJson_Many())
            , alg::String::condense(out.map(test::ResponseFromServerToClient::getLogsBetweenMap_Many()))
            );
}

}