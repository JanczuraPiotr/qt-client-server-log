//
// Created by piotr@janczura.pl on 2020.01.07
//

#include "GetLogsBetween.h"

#include "client/output/GetLogsBetween.h"
#include "common/def.h"

namespace test {

// @task Do czasu opracowania systemu wyjątków zakładam "szczęśliwą ścieżkę" - rozbudować testy o błędne dane wejściowe.
TEST_F(Client_Output_GetLogsBetween, test_1)
{
    cm::DateTime earlier("2011-11-11 11:11:11");
    cm::DateTime latter("2012-12-12 12:12:12");
    cl::output::GetLogsBetween output(earlier, latter);

    EXPECT_EQ(output.command(), "getLogsBetween|2011-11-11 11:11:11|2012-12-12 12:12:12");
}

}
