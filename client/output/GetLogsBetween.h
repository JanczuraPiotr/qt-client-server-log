//
// Created by piotr@janczura.pl on 2020.01.08
//

#ifndef CLIENT_OUTPUT_GETLOGSBETWEEN
#define CLIENT_OUTPUT_GETLOGSBETWEEN

#include "common/def.h"

namespace cl::output {

class GetLogsBetween {
public:
    // @task Do czasu opracowania systemu wyjątków zakładam "szczęśliwą ścieżkę"
    // @task kontrola danych wejściowych
    // @task wyjątek gdy daty są niepoprawne
    GetLogsBetween(const cm::DateTime &earlier, const cm::DateTime &latter);

    cm::JsonString command();

private: // attributes
    cm::DateTime earlier;
    cm::DateTime latter;

public: // lock
    GetLogsBetween(const GetLogsBetween &) = delete;
    GetLogsBetween(GetLogsBetween &&) = delete;
    GetLogsBetween &operator = (const GetLogsBetween&) = delete;
    GetLogsBetween &operator = (GetLogsBetween &&) = delete;
};

}


#endif
