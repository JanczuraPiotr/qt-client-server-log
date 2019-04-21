//
// Created by piotr@janczura.pl on 2019.04.16
//

#include "MainTest.h"
#include "Main.h"

void MainTest::SetUp() {}
void MainTest::TearDown() {}


TEST_F(MainTest, mainTest) {
    Main m;

    EXPECT_EQ(m.add(1,1) ,2);
    EXPECT_EQ(m.add(1,1) ,3);
}
