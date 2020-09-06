//
// Created by piotr@janczura.pl on 2020.07.29
//

#include "GetLogRecordEbnf.hpp"
#include "gtest/tools-and-fakes/ResponseFromServerToClient.hpp"
#include "client/input/protocol/GetLogRecordEbnf.hpp"

namespace test {

TEST_F(Client_Input_GetLogRecordEbnf, correct_get_log_by_id)
{
    cl::in::GetLogRecordEbnf in(test::ResponseFromServerToClient::getLogByIdEbnf());
    EXPECT_TRUE(in.parse());

    auto rec = in.record();
    EXPECT_EQ(rec->id(), 1);
    EXPECT_EQ(rec->logPriority(), cm::LogPriority::ok);
    EXPECT_EQ(rec->message(), "msg-1");
    EXPECT_EQ(rec->timestamp().toString(cm::DATE_TIME_TEMPLATE.c_str()), "1970-01-01 00:00:01");
}

}
