//
// Created by piotr@janczura.pl on 2019.12.15
//

#include "GetLogsBetweenTest.h"


#include "../../../server/input/GetLogsBetween.h"

#include <string>

TEST_F(GetLogsBetweenTest, parse)
{
    std::string input = "";
    sv::input::GetLogsBetween getLogsBetween(input);
    EXPECT_TRUE(getLogsBetween.parse());
}