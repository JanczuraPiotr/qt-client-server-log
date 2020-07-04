//
// Created by piotr@janczura.pl on 2020.01.07
//
#include "GetLogsBetweenJson.h"

#include "gtest/tools-and-fakes/ResponseFromServerToClient.hpp"

#include <QDebug>

#include "client/input/protocol/GetLogsBetweenJson.h"
#include "common/algorithm/String.h"


namespace test {

TEST_F(Client_Input_GetLogsBetweenJson, correct_input)
{
    qDebug() << cm::alg::String::condense(test::ResponseFromServerToClient::getLogsBetweenJson());
    cl::in::GetLogsBetweenJson in(test::ResponseFromServerToClient::getLogsBetweenJson());
    in.parse();

//
//    EXPECT_TRUE(input.parse(test::ResponseFromServerToClient::getLogsBetweenJson()));
//    EXPECT_EQ(input.getBorderEarlier().toString(cm::DATE_TIME_IN_COMMAND_TEMPLATE.c_str()), "1970-01-01-00-00-00");
//    EXPECT_EQ(input.getBorderLatter().toString(cm::DATE_TIME_IN_COMMAND_TEMPLATE.c_str()), "1970-01-01-01-00-00");
//    EXPECT_EQ(input.getLogCollection()->size(), 4);
//    EXPECT_EQ(input.getLogCollection()->getById(1)->getMessage(), "msg-1");
//    EXPECT_EQ(input.getLogCollection()->getById(4)->getMessage(), "msg-4");
//    EXPECT_EQ(
//            input.getLogCollection()->getById(1)->getTmestamp().toString(cm::DATE_TIME_TEMPLATE.c_str())
//            , "1070-01-01 00:00:01");
//    EXPECT_EQ(
//            input.getLogCollection()->getById(4)->getTmestamp().toString(cm::DATE_TIME_TEMPLATE.c_str())
//            , "1970-01-01 00:00:04");
}

}
