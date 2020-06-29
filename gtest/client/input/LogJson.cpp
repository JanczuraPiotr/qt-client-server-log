//
// Created by piotr@janczura.pl on 2019.04.16
//
#include "LogJson.h"

#include "common/def.h"

#include "client/input/Log.h"

namespace test {


TEST_F(Client_Input_Log, test_1) {
    EXPECT_TRUE(false);
//    cm::Index lim = 0;
//    cm::JsonString input = R"({
//            "id": "0",
//            "priority": "1",
//            "message": "msg",
//            "timestamp": "1970-01-01 00:00:00"
//    })";
//    cl::in::Log inputLog(cm::NetProtocol::JSON);
//    EXPECT_FALSE(inputLog.parse(input, lim)); // ze względu na id == 0
}

TEST_F(Client_Input_Log, test_2) {
    EXPECT_TRUE(false);
//    cm::Index lim = 0;
//    cm::JsonString input = R"({
//            "id": "-1",
//            "priority": "1",
//            "message": "msg",
//            "timestamp": "1970-01-01 00:00:00"
//    })";
//    cl::in::Log inputLog(cm::NetProtocol::JSON);
//    EXPECT_FALSE(inputLog.parse(input, lim)); // ze względu na id == -1
}

TEST_F(Client_Input_Log, test_3) {
    EXPECT_TRUE(false);
//    cm::Index lim = 0;
//    cm::JsonString input = R"({
//            "id": "1",
//            "priority": "-1",
//            "message": "msg",
//            "timestamp": "1970-01-01 00:00:00"
//    })";
//    cl::in::Log inputLog(cm::NetProtocol::JSON);
//    EXPECT_FALSE(inputLog.parse(input, lim)); // ze względu na priority == -1. Priorytety mają wartość > 1
}

TEST_F(Client_Input_Log, test_4) {
    EXPECT_TRUE(false);
//    cm::Index lim = 0;
//    cm::JsonString input = R"({
//            "id": "1",
//            "priority": "1",
//            "message": "msg",
//            "timestamp": ""
//    })";
//    cl::in::Log inputLog(cm::NetProtocol::JSON);
//    EXPECT_FALSE(inputLog.parse(input, lim));
}

TEST_F(Client_Input_Log, test_5) {
    EXPECT_TRUE(false);
//    cm::Index lim = 0;
//    cm::JsonString input = R"({
//            "id": "1",
//            "priority": "1",
//            "message": "msg",
//            "timestamp": "1970-01-01"
//    })";
//    cl::in::Log inputLog(cm::NetProtocol::JSON);
//    EXPECT_FALSE(inputLog.parse(input, lim));
}

TEST_F(Client_Input_Log, test_6) {
    EXPECT_TRUE(false);
//    cm::Index lim = 0;
//    cm::JsonString input = R"({
//            "id": "1",
//            "priority": "1",
//            "message": "msg",
//            "timestamp": "00:00:00"
//    })";
//    cl::in::Log inputLog(cm::NetProtocol::JSON);
//    EXPECT_FALSE(inputLog.parse(input, lim));
}

}
