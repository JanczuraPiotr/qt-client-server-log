//
// Created by piotr@janczura.pl on 2019.04.13
//

#include <iostream>

#include <QCoreApplication>
#include <QObject>

#include "common/db/Db.h"
#include "common/exception/general.h"

#include "server/app/ConfigFile.h"
#include "server/service/NetConnection.h"
#include "server/service/FakeEvent.h"
#include "server/service/Main.h"

namespace ss = sv::service;

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
        QObject::connect(&netConnection, &ss::NetConnection::getLogsAfter, &main, &ss::Main::getLogsAfter);
        QObject::connect(&netConnection, &ss::NetConnection::getLogsBefore, &main, &ss::Main::getLogsBefore);
        QObject::connect(&netConnection, &ss::NetConnection::getLogsBetween, &main, &ss::Main::getLogsBetween);
        QObject::connect(&netConnection, &ss::NetConnection::stopPushingLogs, &main, &ss::Main::stopPushingLogs);
        QObject::connect(&netConnection, &ss::NetConnection::startPushingLogs, &main, &ss::Main::startPushingLogs);

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