//
// Created by piotr@janczura.pl on 2019.12.15
//

#include "GetLogsBefore.h"

#include "../../../server/input/GetLogsBefore.h"

#include <QString>

namespace test {

TEST_F(Server_Input_GetLogsBefore, parse_date_time_correct) {
    QString input = "getLogsBefore|2011-11-11-00-00-00";
    int lim = input.indexOf("|");
    sv::input::GetLogsBefore getLogsBefore(input, lim);
    EXPECT_TRUE(getLogsBefore.parse());
}

TEST_F(Server_Input_GetLogsBefore, parse_date_time_incorrect) {
    QString input = "getLogsBefore|2011-11-11 00:00:00";
    int lim = input.indexOf("|");
    sv::input::GetLogsBefore getLogsBefore(input, lim);
    EXPECT_FALSE(getLogsBefore.parse());
}

TEST_F(Server_Input_GetLogsBefore, parse_date_correct) {
    QString input = "Server_Input_GetLogsBefore|2011-11-11";
    int lim = input.indexOf("|");
    sv::input::GetLogsBefore GetLogsBefore(input, lim);
    EXPECT_FALSE(GetLogsBefore.parse());
}

TEST_F(Server_Input_GetLogsBefore, parse_date_time_correct_param_1) {
    QString input = "Server_Input_GetLogsBefore|2011-11-11 00:00:00|1";
    int lim = input.indexOf("|");
    sv::input::GetLogsBefore GetLogsBefore(input, lim);
    EXPECT_FALSE(GetLogsBefore.parse());
}

TEST_F(Server_Input_GetLogsBefore, parse_date_time_correct_param_2) {
    QString input = "Server_Input_GetLogsBefore|2011-11-11 00:00:00|2|";
    int lim = input.indexOf("|");
    sv::input::GetLogsBefore GetLogsBefore(input, lim);
    EXPECT_FALSE(GetLogsBefore.parse());
}

TEST_F(Server_Input_GetLogsBefore, parse_param_1) {
    QString input = "Server_Input_GetLogsBefore|1";
    int lim = input.indexOf("|");
    sv::input::GetLogsBefore GetLogsBefore(input, lim);
    EXPECT_FALSE(GetLogsBefore.parse());
}

TEST_F(Server_Input_GetLogsBefore, parse_empty) {
    QString input = "Server_Input_GetLogsBefore";
    int lim = input.indexOf("|");
    sv::input::GetLogsBefore GetLogsBefore(input, lim);
    EXPECT_FALSE(GetLogsBefore.parse());
}

}