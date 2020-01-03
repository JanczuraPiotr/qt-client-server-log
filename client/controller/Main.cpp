//
// Created by piotr@janczura.pl on 2019.12.22
//

#include "Main.h"

#include <QDebug>
#include <QCoreApplication>

#include "model/LogCollection.h"

namespace cl::controller {

Main& Main::instance()
{
    static Main main;
    return main;
}

Main::Main()
    : mainWindow()
{
    mainWindow.show();
}

void Main::log(cm::AutoId logId, const QDateTime &timestamp, cm::LogPriority logPriority, const cm::Message &message)
{
    cl::model::LogCollection logCollection;
    cl::model::LogRecord::ptr logRecord = logCollection.insert(logId, timestamp, logPriority, message);
    mainWindow.log(logRecord);
}

}
