//
// Created by piotr@janczura.pl on 2020.01.16
//

#include "GetLogsBetweenEbnf.h"

namespace test {


TEST_F(Server_Input_GetLogsBetweenEbnf, parse_0) {
    EXPECT_TRUE(false);
//    QString input = "getLogsBetween|2011-11-11-00-00-00|2012-12-12-00-00-00";
//    int lim = input.indexOf("|");
//    sv::input::GetLogsBetweenJson getLogsBetween(input, lim);
//    EXPECT_TRUE(getLogsBetween.parse());
}

TEST_F(Server_Input_GetLogsBetweenEbnf, parse_1) {
        EXPECT_TRUE(false);
//    QString input = "getLogsBetween|2011-11-11 00:00:00|2011-12-12 00:00:00";
//    int lim = input.indexOf("|");
//    sv::input::GetLogsBetweenJson getLogsBetween(input, lim);
//    EXPECT_FALSE(getLogsBetween.parse());
}

TEST_F(Server_Input_GetLogsBetweenEbnf, parse_2) {
        EXPECT_TRUE(false);
//    QString input = "getLogsBetween|2011-11-11-00-00-00|2011-11-11-00-00-00|";
//    int lim = input.indexOf("|");
//    sv::input::GetLogsBetweenJson getLogsBetween(input, lim);
//    EXPECT_FALSE(getLogsBetween.parse());
}

TEST_F(Server_Input_GetLogsBetweenEbnf, parse_3) {
        EXPECT_TRUE(false);
//    QString input = "getLogsBetween|2011-11-11-00-00-00||string";
//    int lim = input.indexOf("|");
//    sv::input::GetLogsBetweenJson getLogsBetween(input, lim);
//    EXPECT_FALSE(getLogsBetween.parse());
}

TEST_F(Server_Input_GetLogsBetweenEbnf, parse_4) {
        EXPECT_TRUE(false);
//    QString input = "getLogsBetween|2011-11-11-00-00-00||";
//    int lim = input.indexOf("|");
//    sv::input::GetLogsBetweenJson getLogsBetween(input, lim);
//    EXPECT_FALSE(getLogsBetween.parse());
}

TEST_F(Server_Input_GetLogsBetweenEbnf, parse_5) {
        EXPECT_TRUE(false);
//    QString input = "getLogsBetween|asdfasdf|2011-11-11-00-00-00";
//    int lim = input.indexOf("|");
//    sv::input::GetLogsBetweenJson getLogsBetween(input, lim);
//    EXPECT_FALSE(getLogsBetween.parse());
}

TEST_F(Server_Input_GetLogsBetweenEbnf, parse_6) {
        EXPECT_TRUE(false);
//    QString input = "getLogsBetween||2011-11-11-00-00-00";
//    int lim = input.indexOf("|");
//    sv::input::GetLogsBetweenJson getLogsBetween(input, lim);
//    EXPECT_FALSE(getLogsBetween.parse());
}

}