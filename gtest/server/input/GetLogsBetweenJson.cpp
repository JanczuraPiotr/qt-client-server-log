//
// Created by piotr@janczura.pl on 2019.12.15
//

#include "GetLogsBetweenJson.h"

#include <QString>

#include "server/input/GetLogsBetween.h"

namespace test {


TEST_F(Server_Input_GetLogsBetween, parse_0) {
    QString input = "getLogsBetween|2011-11-11-00-00-00|2012-12-12-00-00-00";
    EXPECT_TRUE(false) << input.toStdString();
//    int lim = input.indexOf("|");
//    sv::in::GetLogsBetween getLogsBetween(cm::NetProtocol::JSON);
//    EXPECT_TRUE(getLogsBetween.parse(input, lim));
}

TEST_F(Server_Input_GetLogsBetween, parse_1) {
    QString input = "getLogsBetween|2011-11-11 00:00:00|2011-12-12 00:00:00";
    EXPECT_TRUE(false) << input.toStdString();
//    int lim = input.indexOf("|");
//    sv::in::GetLogsBetween getLogsBetween(cm::NetProtocol::JSON);
//    EXPECT_FALSE(getLogsBetween.parse(input, lim));
}

TEST_F(Server_Input_GetLogsBetween, parse_2) {
    QString input = "getLogsBetween|2011-11-11-00-00-00|2011-11-11-00-00-00|";
        EXPECT_TRUE(false) << input.toStdString();
//    int lim = input.indexOf("|");
//    sv::in::GetLogsBetween getLogsBetween(cm::NetProtocol::JSON);
//    EXPECT_FALSE(getLogsBetween.parse(input, lim));
}

TEST_F(Server_Input_GetLogsBetween, parse_3) {
    QString input = "getLogsBetween|2011-11-11-00-00-00||string";
        EXPECT_TRUE(false) << input.toStdString();
//    int lim = input.indexOf("|");
//    sv::in::GetLogsBetween getLogsBetween(cm::NetProtocol::JSON);
//    EXPECT_FALSE(getLogsBetween.parse(input, lim));
}

TEST_F(Server_Input_GetLogsBetween, parse_4) {
    QString input = "getLogsBetween|2011-11-11-00-00-00||";
        EXPECT_TRUE(false) << input.toStdString();
//    int lim = input.indexOf("|");
//    sv::in::GetLogsBetween getLogsBetween(cm::NetProtocol::JSON);
//    EXPECT_FALSE(getLogsBetween.parse(input, lim));
}

TEST_F(Server_Input_GetLogsBetween, parse_5) {
    QString input = "getLogsBetween|asdfasdf|2011-11-11-00-00-00";
        EXPECT_TRUE(false) << input.toStdString();
//    int lim = input.indexOf("|");
//    sv::in::GetLogsBetween getLogsBetween(cm::NetProtocol::JSON);
//    EXPECT_FALSE(getLogsBetween.parse(input, lim));
}

TEST_F(Server_Input_GetLogsBetween, parse_6) {
    QString input = "getLogsBetween||2011-11-11-00-00-00";
        EXPECT_TRUE(false) << input.toStdString();
//    int lim = input.indexOf("|");
//    sv::in::GetLogsBetween getLogsBetween(cm::NetProtocol::JSON);
//    EXPECT_FALSE(getLogsBetween.parse(input, lim));
}

}