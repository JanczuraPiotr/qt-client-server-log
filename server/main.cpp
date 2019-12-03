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

        auto &fakeEvent = sv::FakeEvent::instance();
        auto &netConnection = sv::service::NetConnection::instance();

        QObject::connect(&fakeEvent
                , &sv::FakeEvent::insertedLog
                , &netConnection
                , &sv::service::NetConnection::insertedLog);

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