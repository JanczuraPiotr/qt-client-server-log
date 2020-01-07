//
// Created by piotr@janczura.pl on 2019.12.15
//

#include "GetLogsAfter.h"

#include "../../../server/input/GetLogsAfter.h"
#include <string>

namespace test {

TEST_F(Server_Input_GetLogsAfter, parse_date_time_correct) {
    QString input = "getLogsAfter|2011-11-11-00-00-00";
    int lim = input.indexOf("|");
    sv::input::GetLogsAfter getLogsAfter(input, lim);
    EXPECT_TRUE(getLogsAfter.parse());
}

TEST_F(Server_Input_GetLogsAfter, parse_date_time_incorrect) {
    QString input = "getLogsAfter|2011-11-11 11:11:11";
    int lim = input.indexOf("|");
    sv::input::GetLogsAfter getLogsAfter(input, lim);
    EXPECT_FALSE(getLogsAfter.parse());
}

TEST_F(Server_Input_GetLogsAfter, parse_date_correct) {
    QString input = "getLogsAfter|2011-11-11";
    int lim = input.indexOf("|");
    sv::input::GetLogsAfter getLogsAfter(input, lim);
    EXPECT_FALSE(getLogsAfter.parse());
}

TEST_F(Server_Input_GetLogsAfter, parse_date_time_correct_param_1) {
    QString input = "getLogsAfter|2011-11-11-00-00-00|1";
    int lim = input.indexOf("|");
    sv::input::GetLogsAfter getLogsAfter(input, lim);
    EXPECT_FALSE(getLogsAfter.parse());
}

TEST_F(Server_Input_GetLogsAfter, parse_date_time_correct_param_2) {
    QString input = "getLogsAfter|2011-11-11-00-00-00|2|";
    int lim = input.indexOf("|");
    sv::input::GetLogsAfter getLogsAfter(input, lim);
    EXPECT_FALSE(getLogsAfter.parse());
}

TEST_F(Server_Input_GetLogsAfter, parse_date_time_empty_param_1) {
    QString input = "getLogsAfter|1";
    int lim = input.indexOf("|");
    sv::input::GetLogsAfter getLogsAfter(input, lim);
    EXPECT_FALSE(getLogsAfter.parse());
}

TEST_F(Server_Input_GetLogsAfter, parse_empty) {
    QString input = "getLogsAfter";
    int lim = input.indexOf("|");
    sv::input::GetLogsAfter getLogsAfter(input, lim);
    EXPECT_FALSE(getLogsAfter.parse());
}

}