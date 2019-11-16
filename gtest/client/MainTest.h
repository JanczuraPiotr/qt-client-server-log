//
// Created by piotr@janczura.pl on 2019.04.16
//

#ifndef QT_LOG_MAINTEST_H
#define QT_LOG_MAINTEST_H

#include <gtest/gtest.h>

class MainTest  : public ::testing::Test {
public:
    MainTest() = default;
    ~MainTest() override = default;
protected:

    void SetUp() override;
    void TearDown() override ;
};


#endif //QT_LOG_MAINTEST_H
