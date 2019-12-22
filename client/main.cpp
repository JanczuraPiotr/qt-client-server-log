//
// Created by piotr@janczura.pl on 2019.04.13
//

#include <QCoreApplication>
#include <iostream>
#include <QDebug>
#include <server/app/ConfigFile.h>
#include <client/controller/Main.h>

#include "common/exception/general.h"
#include "client/controller/Net.h"

// @task dodać mechanizm usuwania starych logów zgromadzonych w kolekcji
// @task main.cpp powinien być zastąpiony przez service::Main

namespace cc = cl::controller;

int main(int argc, char **argv) {
    std::ignore = argc;
    std::ignore = argv;

    try {
        QCoreApplication app(argc, argv);

        sv::ConfigFile *configFile = sv::ConfigFile::instance(); // TODO client powinien mieć swój plik konfiguracyjny
        cl::controller::Net net(configFile->getServerUrl(), configFile->getServerPort());

        auto &main = cc::Main::instance();

        QObject::connect(&net, &cc::Net::log, &main, &cc::Main::log);

        return app.exec();

    } catch (cm::ex::General &ex) {
        std::cerr << (ex.type() + " | " + ex.msg()).toStdString();
    } catch (std::exception &ex) {
        std::cerr << ex.what();
    } catch (...) {
        std::cerr << "Unknown exception";
    }
}
