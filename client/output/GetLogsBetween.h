//
// Created by piotr@janczura.pl on 2020.01.16
//

#ifndef CLIENT_OUTPUT_GETLOGSBETWEEN
#define CLIENT_OUTPUT_GETLOGSBETWEEN

#include "common/def.h"

namespace cl::output {


class GetLogsBetween {
// @work na podstawie parametrów wiersza poleceń wybrać właściwy protokół
public:
    // @task Do czasu opracowania systemu wyjątków zakładam "szczęśliwą ścieżkę"
    // @task kontrola danych wejściowych
    // @task wyjątek gdy daty są niepoprawne
    explicit GetLogsBetween(cm::NetProtocol netProtocol);

    QString command(const cm::DateTime &earlier, const cm::DateTime &latter);

private: // attributes
    cm::NetProtocol netProtocol;

public: // lock
    GetLogsBetween(const GetLogsBetween &) = delete;
    GetLogsBetween(GetLogsBetween &&) = delete;
    GetLogsBetween &operator = (const GetLogsBetween&) = delete;
    GetLogsBetween &operator = (GetLogsBetween &&) = delete;

};

}

#endif
