//
// Created by piotr@janczura.pl on 2019.12.15
//

#include "../../../server/input/GetLogsBefore.h"
#include "GetLogsBeforeTest.h"

#include <string>

TEST_F(GetLogsBeforeTest, parse)
{
    std::string input;
    sv::input::GetLogsBefore getLogsBefore(input);
    EXPECT_TRUE(getLogsBefore.parse());
}