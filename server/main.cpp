//
// Created by piotr@janczura.pl on 2019.04.13
//

#include <iostream>

#include <QCoreApplication>

#include "config.h"
#include "common/def.h"
#include "common/model/Log.h"
#include "common/model/LogTable.h"


int main(int argc, char **argv) {
    QCoreApplication app(argc, argv);

    model::LogTable logTable(model::db::Driver::i());
    QDateTime dateTime = QDateTime::currentDateTime();
    common::LogMsg msg("test " + dateTime.toString("yyyy-MM-dd hh:mm:ss"));

    std::cout << dateTime.toString("yyyy-MM-dd hh:mm:ss").toStdString() << std::endl;
    std::cout << msg.toStdString() << std::endl;

    model::Log::ptr log = std::make_shared<model::Log>(
            dateTime
            , common::LogPriority::ok
            , msg);

    // @work all.add(log);

    model::Log::map all = logTable.getAll();

    for (const auto& it : all) {
        std::cout << it.first << " -> "
                << it.second->getDateTime().toString("yyyy-MM-dd hh:mm:ss").toStdString() << " "
                << static_cast<int>(it.second->getPriority()) << " "
                << it.second->getText().toStdString()
                << std::endl;
    }

    std::cout << "server" << std::endl;
    return 0;
}


// @task server socket
