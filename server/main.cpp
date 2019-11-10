//
// Created by piotr@janczura.pl on 2019.04.13
//

#include <iostream>

#include <QCoreApplication>

#include "common/db/Db.h"
#include "common/exception/general.h"

#include "ConfigFile.h"
#include "FakeEvent.h"

int main(int argc, char **argv) {
    try {

        QCoreApplication app(argc, argv);
        server::ConfigFile *config = server::ConfigFile::instance();
        cm::db::Db::init(
                config->getDbHost()
                , config->getDbPort()
                , config->getDbType()
                , config->getDbName()
                , config->getDbUser()
                , config->getDbPass());

        server::FakeEvent::instance().start();

    //    model::LogTable logTable;
    //    model::LogTable::Map all = logTable.getAll();

        std::cout << "server" << std::endl;
        return app.exec();

    } catch (ex::General &ex) {
        std::cerr << (ex.type() + " | " + ex.msg()).toStdString();
    } catch (std::exception &ex) {
        std::cerr << ex.what();
    } catch (...) {
        std::cerr << "Unknown exception";
    }
}


// @task server socket
