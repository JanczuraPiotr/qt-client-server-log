//
// Created by piotr@janczura.pl on 2020.01.07
//
#include "GetLogsBetweenJson.h"

#include <QDebug>

#include "gtest/tools-and-fakes/ResponseFromServerToClient.hpp"

#include "client/input/protocol/GetLogsBetweenJson.h"
#include "common/algorithm/String.h"
#include "common/data/record/Log.hpp"

namespace rec = data::record;
namespace ent = data::entity;

namespace test {

TEST_F(Client_Input_GetLogsBetweenJson, correct_input_empty)
{
    qDebug() << __FILE__ << __LINE__ << test::ResponseFromServerToClient::getLogsBetweenJson_Empty();
    cl::in::GetLogsBetweenJson in(test::ResponseFromServerToClient::getLogsBetweenJson_Empty());

    EXPECT_TRUE(in.parse());
    rec::Log::map map = in.logMap();

    ent::Interval::ptr interval = in.interval();
    qDebug() << __FILE__ << __LINE__ << interval->timeFrom();
    qDebug() << __FILE__ << __LINE__ << interval->timeTo();
    EXPECT_TRUE(interval->isOk());
    EXPECT_EQ(interval->timeFrom().toString(cm::DATE_TIME_TEMPLATE.c_str()), "1970-01-01 00:00:00");
    EXPECT_EQ(interval->timeTo().toString(cm::DATE_TIME_TEMPLATE.c_str()), "1970-01-01 01:00:00");

    EXPECT_EQ(map.size(), 0);
}

TEST_F(Client_Input_GetLogsBetweenJson, correct_input_one)
{
    cl::in::GetLogsBetweenJson in(test::ResponseFromServerToClient::getLogsBetweenJson_One());

    EXPECT_TRUE(in.parse());
    rec::Log::map map = in.logMap();

    ent::Interval::ptr interval = in.interval();
    EXPECT_TRUE(interval->isOk());
    EXPECT_EQ(interval->timeFrom().toString(cm::DATE_TIME_TEMPLATE.c_str()), "1970-01-01 00:00:00");
    EXPECT_EQ(interval->timeTo().toString(cm::DATE_TIME_TEMPLATE.c_str()), "1970-01-01 01:00:00");

    EXPECT_EQ(map.size(), 1);
    EXPECT_ANY_THROW(map.at(0));
    EXPECT_ANY_THROW(map.at(2));

    EXPECT_EQ(map[1]->timestamp().toString(cm::DATE_TIME_TEMPLATE.c_str()), "1970-01-01 00:00:01");
    EXPECT_EQ(map[1]->message(), "msg-1");
    EXPECT_EQ(map[1]->logPriority(), cm::LogPriority::ok);
}

TEST_F(Client_Input_GetLogsBetweenJson, correct_input_many)
{
    cl::in::GetLogsBetweenJson in(test::ResponseFromServerToClient::getLogsBetweenJson_Many());

    EXPECT_TRUE(in.parse());
    rec::Log::map map = in.logMap();

    ent::Interval::ptr interval = in.interval();
    EXPECT_TRUE(interval->isOk());
    EXPECT_EQ(interval->timeFrom().toString(cm::DATE_TIME_TEMPLATE.c_str()), "1970-01-01 00:00:00");
    EXPECT_EQ(interval->timeTo().toString(cm::DATE_TIME_TEMPLATE.c_str()), "1970-01-01 01:00:00");

    EXPECT_EQ(map.size(), 4);
    EXPECT_ANY_THROW(map.at(0));
    EXPECT_ANY_THROW(map.at(5));

    EXPECT_EQ(map[1]->timestamp().toString(cm::DATE_TIME_TEMPLATE.c_str()), "1970-01-01 00:00:01");
    EXPECT_EQ(map[1]->message(), "msg-1");
    EXPECT_EQ(map[1]->logPriority(), cm::LogPriority::ok);
    EXPECT_EQ(map[2]->timestamp().toString(cm::DATE_TIME_TEMPLATE.c_str()), "1970-01-01 00:00:02");
    EXPECT_EQ(map[2]->message(), "msg-2");
    EXPECT_EQ(map[2]->logPriority(), cm::LogPriority::info);
    EXPECT_EQ(map[3]->timestamp().toString(cm::DATE_TIME_TEMPLATE.c_str()), "1970-01-01 00:00:03");
    EXPECT_EQ(map[3]->message(), "msg-3");
    EXPECT_EQ(map[3]->logPriority(), cm::LogPriority::warning);
    EXPECT_EQ(map[4]->timestamp().toString(cm::DATE_TIME_TEMPLATE.c_str()), "1970-01-01 00:00:04");
    EXPECT_EQ(map[4]->message(), "msg-4");
    EXPECT_EQ(map[4]->logPriority(), cm::LogPriority::error);
}

}
