//
// Created by piotr@janczura.pl on 2020.07.10
//

#include "GetLogRecordJson.hpp"
#include <QDebug>
#include "gtest/tools-and-fakes/ResponseFromServerToClient.hpp"
#include "server/output/protocol/GetLogRecordJson.h"


namespace d = data;
namespace r = d::record;
namespace e = d::entity;

namespace test {

TEST_F(Server_Output_GetLogRecordJson, command)
{
    r::Log::ptr record = test::ResponseFromServerToClient::getLogRecord();
    sv::out::GetLogRecordJson out;
    auto jsonString = out.command(record);
    EXPECT_EQ(jsonString.replace('\n',"").replace(' ', "").replace('\\', ""), R"({"id":"1","message":"msg-1","priority":"1","timestamp":"1070-01-0100:00:01"})");
}


}