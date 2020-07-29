//
// Created by piotr@janczura.pl on 2020.07.10
//

#include "GetLogRecordJson.h"

#include "gtest/tools-and-fakes/RequestFromClientToServer.hpp"

#include "server/input/protocol/GetLogRecordJson.h"

namespace test {

TEST_F(Server_Input_GetLogRecordJson, correct_get_log_by_id)
{
    sv::in::GetLogRecordJson input(test::RequestFromClientToServer::getLogById());

    EXPECT_TRUE(input.parse());
    EXPECT_EQ(input.id(), 123);

}

}