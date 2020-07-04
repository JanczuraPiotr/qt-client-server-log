//
// Created by piotr@janczura.pl on 2020.01.07
//

#include "GetLogsBetweenJson.h"

#include <QDebug>

#include "client/output/protocol/GetLogsBetweenJson.h"
#include "common/algorithm/String.h"
#include "common/def.h"

#include "gtest/tools-and-fakes/RequestFromClientToServer.hpp"


namespace test {

TEST_F(Client_Output_GetLogsBetweenJson, test_1)
{
    cm::DateTime earlier("1970-01-01 00:00:00");
    cm::DateTime latter("1970-01-01 01:00:00");

    cl::out::GetLogsBetweenJson output;

    auto command = cm::alg::String::condense(output.command(earlier, latter));
    auto test    = cm::alg::String::condense(test::RequestFromClientToServer::getLogsBetweenJson());


    EXPECT_EQ(command, test);
}

}
