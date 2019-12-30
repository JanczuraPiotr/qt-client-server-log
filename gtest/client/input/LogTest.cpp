//
// Created by piotr@janczura.pl on 2019.04.16
//
#include "LogTest.h"

#include "common/def.h"

#include "client/input/Log.h"

TEST_F(LogTest, test_1) {
    cm::Index lim = 0;
    cm::JsonString input = R"({
            "logId": "0",
            "logPriority": "1",
            "message": "msg",
            "timestamp": "1970-01-01 00:00:00"
    })";

    cl::input::Log inputLog(input, lim);
    EXPECT_FALSE(inputLog.parse()); // ze względu na logId == 0
}

TEST_F(LogTest, test_2) {
    cm::Index lim = 0;
    cm::JsonString input = R"({
            "logId": "-1",
            "logPriority": "1",
            "message": "msg",
            "timestamp": "1970-01-01 00:00:00"
    })";
    cl::input::Log inputLog(input, lim);
    EXPECT_FALSE(inputLog.parse()); // ze względu na logId == -1
}

TEST_F(LogTest, test_3) {
    cm::Index lim = 0;
    cm::JsonString input = R"({
            "logId": "1",
            "logPriority": "-1",
            "message": "msg",
            "timestamp": "1970-01-01 00:00:00"
    })";
    cl::input::Log inputLog(input, lim);
    EXPECT_FALSE(inputLog.parse()); // ze względu na logPriority == -1 Priorytety mają wartość > 1
}

TEST_F(LogTest, test_4) {
    cm::Index lim = 0;
    cm::JsonString input = R"({
            "logId": "1",
            "logPriority": "1",
            "message": "msg",
            "timestamp": ""
    })";
    cl::input::Log inputLog(input, lim);
    EXPECT_FALSE(inputLog.parse());
}

TEST_F(LogTest, test_5) {
    cm::Index lim = 0;
    cm::JsonString input = R"({
            "logId": "1",
            "logPriority": "1",
            "message": "msg",
            "timestamp": "1970-01-01"
    })";
    cl::input::Log inputLog(input, lim);
    EXPECT_FALSE(inputLog.parse());
}

TEST_F(LogTest, test_6) {
    cm::Index lim = 0;
    cm::JsonString input = R"({
            "logId": "1",
            "logPriority": "1",
            "message": "msg",
            "timestamp": "00:00:00"
    })";
    cl::input::Log inputLog(input, lim);
    EXPECT_FALSE(inputLog.parse());
}
