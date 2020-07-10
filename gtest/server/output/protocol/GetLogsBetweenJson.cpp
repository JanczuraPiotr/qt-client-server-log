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
    QString command("getLogsBetween");
    QDateTime timeFrom(QDateTime::fromString("1970-01-01 00:00:00", cm::DATE_TIME_TEMPLATE.c_str()));
    QDateTime timeTo(QDateTime::fromString("1970-01-01 01:00:00", cm::DATE_TIME_TEMPLATE.c_str()));

    auto record = test::ResponseFromServerToClient::getLogRecord();
    sv::out::GetLogsBetweenJson out;
    auto response = out.one(command, timeFrom, timeTo, record);
    auto templ    = test::ResponseFromServerToClient::getLogsBetweenJson_One();

    EXPECT_EQ(alg::String::condense(response), alg::String::condense(templ));
}

TEST_F(Server_Output_GetLogsBetweenJson, map_1)
{
    QString command("getLogsBetween");
    QDateTime timeFrom(QDateTime::fromString("1970-01-01 00:00:00", cm::DATE_TIME_TEMPLATE.c_str()));
    QDateTime timeTo(QDateTime::fromString("1970-01-01 01:00:00", cm::DATE_TIME_TEMPLATE.c_str()));

    auto records = test::ResponseFromServerToClient::getLogsBetweenMap_Many();
    sv::out::GetLogsBetweenJson out;
    auto response = out.map(command, timeFrom, timeTo, records);
    auto templ    = test::ResponseFromServerToClient::getLogsBetweenJson_Many();

    EXPECT_EQ(alg::String::condense(response), alg::String::condense(templ));
}

}