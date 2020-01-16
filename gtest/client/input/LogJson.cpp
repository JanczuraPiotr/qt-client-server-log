//
// Created by piotr@janczura.pl on 2019.04.16
//
#include "LogJson.h"

#include "common/def.h"

#include "client/input/Log.h"

namespace test {


TEST_F(Client_Input_Log, test_1) {
    cm::Index lim = 0;
    cm::JsonString input = R"({
            "id": "0",
            "priority": "1",
            "message": "msg",
            "timestamp": "1970-01-01 00:00:00"
    })";

    cl::input::Log inputLog(input, lim);
    EXPECT_FALSE(inputLog.parse()); // ze względu na id == 0
}

TEST_F(Client_Input_Log, test_2) {
    cm::Index lim = 0;
    cm::JsonString input = R"({
            "id": "-1",
            "priority": "1",
            "message": "msg",
            "timestamp": "1970-01-01 00:00:00"
    })";
    cl::input::Log inputLog(input, lim);
    EXPECT_FALSE(inputLog.parse()); // ze względu na id == -1
}

TEST_F(Client_Input_Log, test_3) {
    cm::Index lim = 0;
    cm::JsonString input = R"({
            "id": "1",
            "priority": "-1",
            "message": "msg",
            "timestamp": "1970-01-01 00:00:00"
    })";
    cl::input::Log inputLog(input, lim);
    EXPECT_FALSE(inputLog.parse()); // ze względu na priority == -1. Priorytety mają wartość > 1
}

TEST_F(Client_Input_Log, test_4) {
    cm::Index lim = 0;
    cm::JsonString input = R"({
            "id": "1",
            "priority": "1",
            "message": "msg",
            "timestamp": ""
    })";
    cl::input::Log inputLog(input, lim);
    EXPECT_FALSE(inputLog.parse());
}

TEST_F(Client_Input_Log, test_5) {
    cm::Index lim = 0;
    cm::JsonString input = R"({
            "id": "1",
            "priority": "1",
            "message": "msg",
            "timestamp": "1970-01-01"
    })";
    cl::input::Log inputLog(input, lim);
    EXPECT_FALSE(inputLog.parse());
}

TEST_F(Client_Input_Log, test_6) {
    cm::Index lim = 0;
    cm::JsonString input = R"({
            "id": "1",
            "priority": "1",
            "message": "msg",
            "timestamp": "00:00:00"
    })";
    cl::input::Log inputLog(input, lim);
    EXPECT_FALSE(inputLog.parse());
}

}
