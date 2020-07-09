//
// Created by piotr@janczura.pl on 2020.07.09
//

#include "GetLogRecordJson.hpp"

#include "gtest/tools-and-fakes/RequestFromClientToServer.hpp"

#include "gtest/tools-and-fakes/ResponseFromServerToClient.hpp"
#include "client/output/protocol/GetLogRecordJson.hpp"
#include "common/algorithm/String.h"

namespace test {

TEST_F(Client_Output_GetLogRecordJson, correct_get_log_by_id)
{
    cl::out::GetLogRecordJson output;

    auto command = cm::alg::String::condense(output.command(123));
    auto test = cm::alg::String::condense(test::RequestFromClientToServer::getLogById());

    EXPECT_EQ(command, test);
}

}