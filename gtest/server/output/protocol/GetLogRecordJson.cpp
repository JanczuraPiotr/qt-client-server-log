//
// Created by piotr@janczura.pl on 2020.07.10
//

#include "GetLogRecordJson.hpp"
#include <QDebug>
#include "gtest/tools-and-fakes/ResponseFromServerToClient.hpp"
#include "common/algorithm/String.h"
#include "server/output/protocol/GetLogRecordJson.h"


namespace d = data;
namespace r = d::record;
namespace e = d::entity;

namespace test {

TEST_F(Server_Output_GetLogRecordJson, correct_get_log_by_id)
{
    r::Log::ptr record = test::ResponseFromServerToClient::getLogRecord();
    sv::out::GetLogRecordJson out;
    auto jsonString = out.command(record);
    EXPECT_EQ(alg::String::condense(jsonString), alg::String::condense(
            test::ResponseFromServerToClient::getLogByIdJson()));
}


}