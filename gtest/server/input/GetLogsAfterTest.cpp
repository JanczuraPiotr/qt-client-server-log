//
// Created by piotr@janczura.pl on 2019.12.15
//

#include "GetLogsAfterTest.h"

#include "../../../server/input/GetLogsAfter.h"
#include <string>

TEST_F(GetLogsAfterTest, parse)
{
    std::string input;
    sv::input::GetLogsAfter getLogsAfter(input);
    EXPECT_TRUE(getLogsAfter.parse());
}