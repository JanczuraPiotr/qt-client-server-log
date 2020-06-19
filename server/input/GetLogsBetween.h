//
// Created by piotr@janczura.pl on 2020.01.16
//

#ifndef SERVER_INPUT_GETLOGSBETWEEN
#define SERVER_INPUT_GETLOGSBETWEEN

#include <QDateTime>

#include "common/def.h"
#include "Input.hpp"

namespace sv::in {

/*@work */class GetLogsBetween : public Input {
// @work na podstawie parametrów wiersza poleceń wybrać właściwy protokół
public:
    explicit GetLogsBetween(cm::NetProtocol netProtocol);// @work uruchomić możliwość wyboru protokołu

    bool parse(cm::NetInput input, cm::Index lim);

    QDateTime getBorderEarlier();
    QDateTime getBorderLatter();

private: // methods
    cm::NetProtocol netProtocol;

    QDateTime borderEarlier;
    QDateTime borderLatter;

public: // lock
    GetLogsBetween(const GetLogsBetween &) = delete;
    GetLogsBetween(GetLogsBetween &&) = delete;
    GetLogsBetween &operator = (const GetLogsBetween&) = delete;
    GetLogsBetween &operator = (GetLogsBetween &&) = delete;

};
}


#endif
