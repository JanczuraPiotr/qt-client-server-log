//
// Created by piotr@janczura.pl on 2020.01.16
//

#include "GetLogsBetweenEbnf.h"

#include "gtest/tools-and-fakes/ResponseFromServerToClient.hpp"

#include <QDebug>

#include "client/input/GetLogsBetween.h"

namespace test {

TEST_F(Client_Input_GetLogsBetweenEbnf, correct_input)
{
    EXPECT_TRUE(false);
//    cl::in::GetLogsBetweenJson in(alg::String::condense(test::ResponseFromServerToClient::getLogsBetweenJson()), 14);
//    cl::in::GetLogsBetweenJson in(test::ResponseFromServerToClient::getLogsBetweenEbnf());
//
//    EXPECT_TRUE(in.parse());
//    EXPECT_EQ(in.timeFrom().toString(cm::DATE_TIME_IN_COMMAND_TEMPLATE.c_str()), "1970-01-01-00-00-00");
//    EXPECT_EQ(in.timeTo().toString(cm::DATE_TIME_IN_COMMAND_TEMPLATE.c_str()), "1970-01-01-01-00-00");
//    EXPECT_EQ(in.getLogCollection()->size(), 4);
//    EXPECT_EQ(in.getLogCollection()->getById(1)->getMessage(), "msg-1");
//    EXPECT_EQ(in.getLogCollection()->getById(4)->getMessage(), "msg-4");
//    EXPECT_EQ(
//            in.getLogCollection()->getById(1)->getTmestamp().toString(cm::DATE_TIME_TEMPLATE.c_str())
//            , "1070-01-01 00:00:01");
//    EXPECT_EQ(
//            in.getLogCollection()->getById(4)->getTmestamp().toString(cm::DATE_TIME_TEMPLATE.c_str())
//            , "1970-01-01 00:00:04");
}

}
