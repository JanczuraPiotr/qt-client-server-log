//
// Created by piotr@janczura.pl on 2020.01.07
//

#include "gtest/tools-and-fakes/DataFromServerToClient.h"

#include <QDebug>

#include "client/input/GetLogsBetween.h"
#include "GetLogsBetweenJson.h"

namespace test {

TEST_F(Client_Input_GetLogsBetweenJson, correct_input)
{
//    cl::input::GetLogsBetweenJson input(alg::String::condense(test::DataFromServerToClient::getLogsBetweenJson()), 14);
    cl::input::GetLogsBetween input(cm::NetProtocol::JSON);

    EXPECT_TRUE(input.parse(test::DataFromServerToClient::getLogsBetweenJson()));
    EXPECT_EQ(input.getBorderEarlier().toString(cm::DATE_TIME_IN_COMMAND_TEMPLATE.c_str()), "1970-01-01-00-00-00");
    EXPECT_EQ(input.getBorderLatter().toString(cm::DATE_TIME_IN_COMMAND_TEMPLATE.c_str()), "1970-01-01-01-00-00");
    EXPECT_EQ(input.getLogCollection()->size(), 4);
    EXPECT_EQ(input.getLogCollection()->getById(1)->getMessage(), "msg-1");
    EXPECT_EQ(input.getLogCollection()->getById(4)->getMessage(), "msg-4");
    EXPECT_EQ(
            input.getLogCollection()->getById(1)->getTmestamp().toString(cm::DATE_TIME_TEMPLATE.c_str())
            , "1070-01-01 00:00:01");
    EXPECT_EQ(
            input.getLogCollection()->getById(4)->getTmestamp().toString(cm::DATE_TIME_TEMPLATE.c_str())
            , "1970-01-01 00:00:04");
}

}
