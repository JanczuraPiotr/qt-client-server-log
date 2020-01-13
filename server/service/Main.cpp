//
// Created by piotr@janczura.pl on 2019.12.17
//

#include "Main.h"

#include <QDebug>

#include "common/algorithm/String.h"
#include "server/model/LogCollection.h"
#include "server/output/Log.h"

namespace sv::service {

Main& Main::instance() {
    static Main main;
    return main;
}


Main::Main()
{
}

void Main::getLogsBetween(const QDateTime &limitEarlier, const QDateTime &limitLatter, cm::TCPPort clientsPort)
{
    model::LogCollection logCollection;
    auto logs = logCollection.getLogsBetween(limitEarlier, limitLatter);
    sv::output::Log output;
    // @task wszystkie odpowiedzi opakować w jsona w którym pod kluczem "data" będą właściwe dane.
    auto jsonString = "{\"data\":" + output.map(logs) + "}";
    emit messageToClient("getLogsBetween|"
        + cm::algorithm::String::dateTimeInNetCommand(limitEarlier) + "|"
        + cm::algorithm::String::dateTimeInNetCommand(limitLatter)
        + jsonString
        , clientsPort);
}


}