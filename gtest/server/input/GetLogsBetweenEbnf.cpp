//
// Created by piotr@janczura.pl on 2020.01.16
//

#include "GetLogsBetweenEbnf.h"
#include <QString>

namespace test {


TEST_F(Server_Input_GetLogsBetweenEbnf, parse_0) {
    QString input = "getLogsBetween|2011-11-11-00-00-00|2012-12-12-00-00-00";
    EXPECT_TRUE(false) << input.toStdString();
//    int lim = input.indexOf("|");
//    sv::input::GetLogsBetweenJson getLogsBetween(input, lim);
//    EXPECT_TRUE(getLogsBetween.parse());
}

TEST_F(Server_Input_GetLogsBetweenEbnf, parse_1) {
    QString input = "getLogsBetween|2011-11-11 00:00:00|2011-12-12 00:00:00";
    EXPECT_TRUE(false) << input.toStdString();
//    int lim = input.indexOf("|");
//    sv::input::GetLogsBetweenJson getLogsBetween(input, lim);
//    EXPECT_FALSE(getLogsBetween.parse());
}

TEST_F(Server_Input_GetLogsBetweenEbnf, parse_2) {
    QString input = "getLogsBetween|2011-11-11-00-00-00|2011-11-11-00-00-00|";
        EXPECT_TRUE(false) << input.toStdString();
//    int lim = input.indexOf("|");
//    sv::input::GetLogsBetweenJson getLogsBetween(input, lim);
//    EXPECT_FALSE(getLogsBetween.parse());
}

TEST_F(Server_Input_GetLogsBetweenEbnf, parse_3) {
    QString input = "getLogsBetween|2011-11-11-00-00-00||string";
    EXPECT_TRUE(false) << input.toStdString();
//    int lim = input.indexOf("|");
//    sv::input::GetLogsBetweenJson getLogsBetween(input, lim);
//    EXPECT_FALSE(getLogsBetween.parse());
}

TEST_F(Server_Input_GetLogsBetweenEbnf, parse_4) {
    QString input = "getLogsBetween|2011-11-11-00-00-00||";
    EXPECT_TRUE(false) << input.toStdString();
//    int lim = input.indexOf("|");
//    sv::input::GetLogsBetweenJson getLogsBetween(input, lim);
//    EXPECT_FALSE(getLogsBetween.parse());
}

TEST_F(Server_Input_GetLogsBetweenEbnf, parse_5) {
    QString input = "getLogsBetween|asdfasdf|2011-11-11-00-00-00";
    EXPECT_TRUE(false) << input.toStdString();
//    int lim = input.indexOf("|");
//    sv::input::GetLogsBetweenJson getLogsBetween(input, lim);
//    EXPECT_FALSE(getLogsBetween.parse());
}

TEST_F(Server_Input_GetLogsBetweenEbnf, parse_6) {
    QString input = "getLogsBetween||2011-11-11-00-00-00";
     EXPECT_TRUE(false) << input.toStdString();
//    int lim = input.indexOf("|");
//    sv::input::GetLogsBetweenJson getLogsBetween(input, lim);
//    EXPECT_FALSE(getLogsBetween.parse());
}

}