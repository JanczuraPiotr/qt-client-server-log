//
// Created by piotr@janczura.pl on 2019.12.15
//

#include "../../../server/input/GetLogsBefore.h"
#include "GetLogsBeforeTest.h"

#include <string>

TEST_F(GetLogsBeforeTest, parse_date_time_correct)
{
    QString input = "getLogsBefore|2011-11-11 00:00:00";
    int lim = input.indexOf("|");
    sv::input::GetLogsBefore getLogsBefore(input, lim);
    EXPECT_TRUE(getLogsBefore.parse());
}

TEST_F(GetLogsBeforeTest, parse_date_time_incorrect)
{
    QString input = "getLogsBefore|2011-11-11 00:00:00";
    int lim = input.indexOf("|");
    sv::input::GetLogsBefore getLogsBefore(input, lim);
    EXPECT_TRUE(getLogsBefore.parse());
}

TEST_F(GetLogsBeforeTest, parse_date_correct)
{
    QString input = "GetLogsBeforeTest|2011-11-11";
    int lim = input.indexOf("|");
    sv::input::GetLogsBefore GetLogsBefore(input, lim);
    EXPECT_FALSE(GetLogsBefore.parse());
}

TEST_F(GetLogsBeforeTest, parse_date_time_correct_param_1)
{
    QString input = "GetLogsBeforeTest|2011-11-11 00:00:00|1";
    int lim = input.indexOf("|");
    sv::input::GetLogsBefore GetLogsBefore(input, lim);
    EXPECT_FALSE(GetLogsBefore.parse());
}

TEST_F(GetLogsBeforeTest, parse_date_time_correct_param_2)
{
    QString input = "GetLogsBeforeTest|2011-11-11 00:00:00|2|";
    int lim = input.indexOf("|");
    sv::input::GetLogsBefore GetLogsBefore(input, lim);
    EXPECT_FALSE(GetLogsBefore.parse());
}

TEST_F(GetLogsBeforeTest, parse_param_1)
{
    QString input = "GetLogsBeforeTest|1";
    int lim = input.indexOf("|");
    sv::input::GetLogsBefore GetLogsBefore(input, lim);
    EXPECT_FALSE(GetLogsBefore.parse());
}

TEST_F(GetLogsBeforeTest, parse_empty)
{
    QString input = "GetLogsBeforeTest";
    int lim = input.indexOf("|");
    sv::input::GetLogsBefore GetLogsBefore(input, lim);
    EXPECT_FALSE(GetLogsBefore.parse());
}
