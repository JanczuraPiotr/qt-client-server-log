//
// Created by piotr@janczura.pl on 2019.12.15
//

#include "GetLogsBetweenTest.h"

#include <string>

#include "../../../server/input/GetLogsBetween.h"


TEST_F(GetLogsBetweenTest, parse_0)
{
    QString input = "getLogsBetween|2011-11-11 00:00:00|2012-12-12 00:00:00";
    int lim = input.indexOf("|");
    sv::input::GetLogsBetween getLogsBetween(input, lim);
    EXPECT_TRUE(getLogsBetween.parse());
}
TEST_F(GetLogsBetweenTest, parse_1)
{
    QString input = "getLogsBetween|2011-11-11 00:00:00|2011-11-11 00:00:00|string";
    int lim = input.indexOf("|");
    sv::input::GetLogsBetween getLogsBetween(input, lim);
    EXPECT_FALSE(getLogsBetween.parse());
}
TEST_F(GetLogsBetweenTest, parse_2)
{
    QString input = "getLogsBetween|2011-11-11 00:00:00|2011-11-11 00:00:00|";
    int lim = input.indexOf("|");
    sv::input::GetLogsBetween getLogsBetween(input, lim);
    EXPECT_FALSE(getLogsBetween.parse());
}
TEST_F(GetLogsBetweenTest, parse_3)
{
    QString input = "getLogsBetween|2011-11-11 00:00:00||string";
    int lim = input.indexOf("|");
    sv::input::GetLogsBetween getLogsBetween(input, lim);
    EXPECT_FALSE(getLogsBetween.parse());
}
TEST_F(GetLogsBetweenTest, parse_4)
{
    QString input = "getLogsBetween|2011-11-11 00:00:00||";
    int lim = input.indexOf("|");
    sv::input::GetLogsBetween getLogsBetween(input, lim);
    EXPECT_FALSE(getLogsBetween.parse());
}
TEST_F(GetLogsBetweenTest, parse_5)
{
    QString input = "getLogsBetween|asdfasdf|2011-11-11 00:00:00";
    int lim = input.indexOf("|");
    sv::input::GetLogsBetween getLogsBetween(input, lim);
    EXPECT_FALSE(getLogsBetween.parse());
}
TEST_F(GetLogsBetweenTest, parse_6)
{
    QString input = "getLogsBetween||2011-11-11 00:00:00";
    int lim = input.indexOf("|");
    sv::input::GetLogsBetween getLogsBetween(input, lim);
    EXPECT_FALSE(getLogsBetween.parse());
}
