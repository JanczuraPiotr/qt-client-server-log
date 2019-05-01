//
// Created by piotr@janczura.pl on 2019.04.13
//

#include <iostream>

#include <QCoreApplication>

#include "config.h"
#include "common/model/LogTable.h"


int main(int argc, char **argv) {
    QCoreApplication app(argc, argv);

    model::LogTable logTable(model::db::Driver::i());
    model::Log::map all = logTable.getAll();

    for (auto it : all) {
        std::cout << it.first << " -> "
                << it.second->getDateTime().toString("yyyy-MM-dd hh:mm:ss").toStdString() << " "
                << it.second->getPriority() << " "
                << it.second->getText().toStdString()
                << std::endl;
    }

    std::cout << "server" << std::endl;
    return 0;
}


// @task server socket
