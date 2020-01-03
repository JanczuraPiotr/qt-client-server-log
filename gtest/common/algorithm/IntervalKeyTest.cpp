//
// Created by piotr@janczura.pl on 2020.01.03
//

#include "IntervalKeyTest.h"

#include <string>

#include "common/algorithm/Key.h"

TEST_F(IntervalKeyTest, test_1)
{
    QString earlier("1");
    QString latter("2");
    QString key("12");
    EXPECT_EQ(key, cm::algorithm::Key::create(earlier, latter));
}

TEST_F(IntervalKeyTest, test_2)
{
    QString earlier("123!@#");
    QString latter("qweQWE");
    QString key("123!@#qweQWE");
    EXPECT_EQ(key, cm::algorithm::Key::create(earlier, latter));
}

TEST_F(IntervalKeyTest, test_3)
{
    QString earlier("1970-01-01 00:00:00");
    QString latter("2020-11-11 11:11:11");
    QString key("1970-01-01 00:00:002020-11-11 11:11:11");
    EXPECT_EQ(key, cm::algorithm::Key::create(earlier, latter));
}
TEST_F(IntervalKeyTest, empty_earlier)
{
    QString earlier("");
    QString latter("2020-11-11 11:11:11");
    QString key("-- 2020-11-11 11:11:11");
    EXPECT_EQ(key, cm::algorithm::Key::create(earlier, latter));
}
TEST_F(IntervalKeyTest, empty_latter)
{
    QString earlier("1970-01-01 00:00:00");
    QString latter("");
    QString key("1970-01-01 00:00:00 --");
    EXPECT_EQ(key, cm::algorithm::Key::create(earlier, latter));
}
