//
// Created by piotr@janczura.pl on 2020.07.09
//

#include "GetLogRecordJson.hpp"

#include "gtest/tools-and-fakes/ResponseFromServerToClient.hpp"
#include "client/input/protocol/GetLogRecordJson.h"

namespace test {

TEST_F(Client_Input_GetLogRecordJson, correct_get_log_by_id)
{
    cl::in::GetLogRecordJson in(test::ResponseFromServerToClient::getLogById());
    EXPECT_TRUE(in.parse());

    auto rec = in.record();
    EXPECT_EQ(rec->id(), 1);
    EXPECT_EQ(rec->logPriority(), cm::LogPriority::ok);
    EXPECT_EQ(rec->message(), "msg-1");
    EXPECT_EQ(rec->timestamp().toString(cm::DATE_TIME_TEMPLATE.c_str()), "1970-01-01 00:00:01");
}

}