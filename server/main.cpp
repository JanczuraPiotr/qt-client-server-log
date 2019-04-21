//
// Created by piotr@janczura.pl on 2019.04.13
//

#include <QCoreApplication>
#include <iostream>
#include <server/model/LogTable.h>

#include "config.h"

int main(int argc, char **argv) {
    QCoreApplication app(argc, argv);

    sp9pj::model::LogTable logTable;
    sp9pj::model::LogTable::Map all = logTable.getAll();

    std::cout << "server" << std::endl;
    return 0;
}


// @task model class Record, Table
// @task server socket
