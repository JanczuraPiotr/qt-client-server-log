//
// Created by piotr@janczura.pl on 2020.01.03
//

#include "IntervalKey.h"

#include <QString>

#include "common/algorithm/Key.h"


namespace test {

TEST_F(Common_Algorithm_IntervalKey, test_1) {
    QString earlier("1");
    QString latter("2");
    QString key("12");
    EXPECT_EQ(key, cm::alg::Key::create(earlier, latter));
}

TEST_F(Common_Algorithm_IntervalKey, test_2) {
    QString earlier("123!@#");
    QString latter("qweQWE");
    QString key("123!@#qweQWE");
    EXPECT_EQ(key, cm::alg::Key::create(earlier, latter));
}

TEST_F(Common_Algorithm_IntervalKey, test_3) {
    QString earlier("1970-01-01 00:00:00");
    QString latter("2020-11-11 11:11:11");
    QString key("1970-01-01 00:00:002020-11-11 11:11:11");
    EXPECT_EQ(key, cm::alg::Key::create(earlier, latter));
}

TEST_F(Common_Algorithm_IntervalKey, empty_earlier) {
    QString earlier("");
    QString latter("2020-11-11 11:11:11");
    QString key("-- 2020-11-11 11:11:11");
    EXPECT_EQ(key, cm::alg::Key::create(earlier, latter));
}

TEST_F(Common_Algorithm_IntervalKey, empty_latter) {
    QString earlier("1970-01-01 00:00:00");
    QString latter("");
    QString key("1970-01-01 00:00:00 --");
    EXPECT_EQ(key, cm::alg::Key::create(earlier, latter));
}

}