//
// Created by piotr@janczura.pl on 2019.12.22
//

#include "Main.h"

#include <QDebug>

#include "model/LogCollection.h"

namespace cl::controller {

Main& Main::instance()
{
    static Main main;
    return main;
}

Main::Main()
{

}

void Main::log(cm::AutoId logId, const QDateTime &timestamp, cm::LogPriority logPriority, const cm::Message &message)
{
    cl::model::LogCollection logCollection;
    logCollection.insert(
            logId
            , timestamp
            , logPriority
            , message
            );
    // @task powiadomić kontrolkę o nowym logu
}

}
