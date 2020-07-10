//
// Created by piotr@janczura.pl on 2020.01.16
//

#include "LogEbnf.h"
#include <QDateTime>

#include "server/output/protocol/GetLogsBetweenEbnf.h"

#include "common/def.h"

namespace test {

TEST_F(Server_Output_LogEbnf, one_1)
{
    EXPECT_TRUE(false);
//    cm::AutoId id = 1;
//    QDateTime  dateTime = QDateTime::fromString("1970-01-01 00:00:00", cm::DATE_TIME_TEMPLATE.c_str());
//    cm::LogPriority logPriority = cm::LogPriority::error;
//    cm::Message mmessage("msg-1");
//
//    sv::out::GetLogsBetweenEbnf logEbnf;
//    EXPECT_EQ("1|1970-01-01 00:00:00|4|msg-1", logEbnf.one(id, dateTime, logPriority, mmessage));
}

TEST_F(Server_Output_LogEbnf, map_1)
{
    EXPECT_TRUE(false);
//    cm::AutoId id = 1;
//    QDateTime  dateTime = QDateTime::fromString("1970-01-01 00:00:00", cm::DATE_TIME_TEMPLATE.c_str());
//    cm::LogPriority logPriority = cm::LogPriority::error;
//    cm::Message mmessage("msg-1");
//
//    sv::output::GetLogsBetweenEbnf logEbnf;
//    EXPECT_EQ("1|1970-01-01 00:00:00|4|msg-1", logEbnf.one(id, dateTime, logPriority, mmessage));

}

}