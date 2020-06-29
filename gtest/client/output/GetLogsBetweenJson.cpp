//
// Created by piotr@janczura.pl on 2020.01.07
//

#include "GetLogsBetweenJson.h"

#include "client/output/GetLogsBetween.h"
#include "common/def.h"

namespace test {

// @task Do czasu opracowania systemu wyjątków zakładam "szczęśliwą ścieżkę" - rozbudować testy o błędne dane wejściowe.
TEST_F(Client_Output_GetLogsBetween, test_1)
{
    EXPECT_TRUE(false);
//    cm::DateTime earlier("2011-11-11 11:11:11");
//    cm::DateTime latter("2012-12-12 12:12:12");
//    cl::out::GetLogsBetween output(cm::NetProtocol::JSON);
//
//    EXPECT_EQ(output.command(earlier, latter), "getLogsBetween|2011-11-11 11:11:11|2012-12-12 12:12:12");
}

}
