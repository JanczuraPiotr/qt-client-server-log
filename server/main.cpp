//
// Created by piotr@janczura.pl on 2019.04.13
//

// @task ujednolicić definicję plików nagłówkowych
// @task logowanie podłączenia i rozłączenia z klientem


#include <iostream>

#include <QCoreApplication>
#include <QObject>

#include "common/db/Db.h"
#include "common/exception/general.h"

#include "server/app/ConfigFile.h"
#include "server/service/NetConnection.h"
#include "server/service/FakeEvent.h"
#include "server/service/Main.h"

namespace ss = sv::service; // @task chyba lepszą nazwą jest controller

int main(int argc, char **argv) {
    try {

        QCoreApplication app(argc, argv);
        sv::ConfigFile *config = sv::ConfigFile::instance();
        cm::db::Db::init(
                config->getDbHost()
                , config->getDbPort()
                , config->getDbType()
                , config->getDbName()
                , config->getDbUser()
                , config->getDbPass());

        // @task przekierować FakeEvent na Main a netConnection powiadamiać z Main
        auto &fakeEvent = sv::FakeEvent::instance();
        auto &netConnection = sv::service::NetConnection::instance();
        auto &main = sv::service::Main::instance();

        QObject::connect(&fakeEvent, &sv::FakeEvent::insertedLog, &netConnection, &ss::NetConnection::insertedLog);
        QObject::connect(&netConnection, &ss::NetConnection::getLogsBetween, &main, &ss::Main::getLogsBetween);
        QObject::connect(&main, &ss::Main::messageToClient, &netConnection, &ss::NetConnection::messageToClient);

        fakeEvent.start();
        netConnection.start();

        return app.exec();

    } catch (cm::ex::General &ex) {
        std::cerr << (ex.type() + " | " + ex.msg()).toStdString();
    } catch (std::exception &ex) {
        std::cerr << ex.what();
    } catch (...) {
        std::cerr << "Unknown exception";
    }
}

// potem:
//
// po podłączeniu klienta powiadom go o najstarszym zapamiętanym logu i ich ilości
// powiadamiaj klienta o usuniętych logach