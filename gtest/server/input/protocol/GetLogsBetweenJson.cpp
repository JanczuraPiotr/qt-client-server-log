//
// Created by piotr@janczura.pl on 2019.12.15
//

#include "GetLogsBetweenJson.h"

#include <QString>

#include "gtest/tools-and-fakes/RequestFromClientToServer.hpp"

#include "server/input/protocol/GetLogsBetweenJson.h"

namespace test {


TEST_F(Server_Input_GetLogsBetween_Json, correct_input)
{
    sv::in::GetLogsBetweenJson in(test::RequestFromClientToServer::getLogsBetweenJson());
    EXPECT_TRUE(in.parse());
    data::entity::Interval::ptr interval = in.interval();
    EXPECT_TRUE(interval->isOk());

    EXPECT_EQ(interval->timeFrom().toString(cm::DATE_TIME_TEMPLATE.c_str()), "1970-01-01 00:00:00");
    EXPECT_EQ(interval->timeTo().toString(cm::DATE_TIME_TEMPLATE.c_str()), "1970-01-01 01:00:00");
}

// @work Przetestować obsługę błędnego wejścia

}