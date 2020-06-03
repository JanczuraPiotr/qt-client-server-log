//
// Created by piotr@janczura.pl on 2020.01.16
//

#include "LogEbnf.h"

#include "common/def.h"


namespace test {


TEST_F(Client_Input_LogEBNF, test_1) {
    cm::Index lim = 0;
    cm::JsonString input = R"(0|1970-01-01 00:00:00|1|msg)";
    EXPECT_TRUE(false) << input.toStdString();
//    cl::input::Log inputLog(input, lim);
//    EXPECT_FALSE(inputLog.parse()); // ze względu na id == 0
}

TEST_F(Client_Input_LogEBNF, test_2) {
    cm::Index lim = 0;
    cm::JsonString input = R"(-1|1970-01-01 00:00:00|1|msg)";
    EXPECT_TRUE(false) << input.toStdString();

//    cl::input::Log inputLog(input, lim);
//    EXPECT_FALSE(inputLog.parse()); // ze względu na id == -1
}

TEST_F(Client_Input_LogEBNF, test_3) {
    cm::Index lim = 0;
    cm::JsonString input = R"(1|1970-01-01 00:00:00|-1|msg)";
    EXPECT_TRUE(false) << input.toStdString();

//    cl::input::Log inputLog(input, lim);
//    EXPECT_FALSE(inputLog.parse()); // ze względu na priority == -1. Priorytety mają wartość > 1
}

TEST_F(Client_Input_LogEBNF, test_4) {
    cm::Index lim = 0;
    cm::JsonString input = R"(1||1|msg)";
    EXPECT_TRUE(false) << input.toStdString();

//    cl::input::Log inputLog(input, lim);
//    EXPECT_FALSE(inputLog.parse());
}

TEST_F(Client_Input_LogEBNF, test_5) {
    cm::Index lim = 0;
    cm::JsonString input = R"(1|1970-01-01|1|msg)";
    EXPECT_TRUE(false) << input.toStdString();

//    cl::input::Log inputLog(input, lim);
//    EXPECT_FALSE(inputLog.parse());
}

TEST_F(Client_Input_LogEBNF, test_6) {
    cm::Index lim = 0;
    cm::JsonString input = R"(1|00:00:00|1|msg)";
    EXPECT_TRUE(false) << input.toStdString();

//    cl::input::Log inputLog(input, lim);
//    EXPECT_FALSE(inputLog.parse());
}

}
