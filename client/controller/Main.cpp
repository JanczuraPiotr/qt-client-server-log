//
// Created by piotr@janczura.pl on 2019.12.22
//

#include "Main.h"

#include <QDebug>
#include <QCoreApplication>
#include <QThread>

#include "common/algorithm/String.h"
#include "common/algorithm/Key.h"
#include "model/LogCollection.h"

namespace cl::controller {

namespace win = cl::view::window;
namespace alg = cm::algorithm;
//namespace dlg = cl::view::dialog;

Main& Main::instance()
{
    static Main main;
    return main;
}

Main::Main()
    : mainWindow(reinterpret_cast<Main&>(*this))
    , logsWindows()
{
    mainWindow.show();
}

void Main::log(cm::AutoId logId, const QDateTime &timestamp, cm::LogPriority logPriority, const cm::Message &message)
{
    auto logCollection = cl::model::LogCollection::makeShared();
    cl::model::LogRecord::ptr logRecord = logCollection->insert(logId, timestamp, logPriority, message);
    mainWindow.log(logRecord);
}

void Main::loadLogsBetween(const cm::DateTime &earlier, const cm::DateTime &latter)
{
    cm::NetCommand command("getLogsBetween|" +
            cm::algorithm::String::dateTimeInNetCommand(earlier) + "|" +
            cm::algorithm::String::dateTimeInNetCommand(latter));
    qDebug() << "Main -> netCommand => " <<command;
    emit netCommand(command);
}

void Main::logsBetween(const QDateTime &earlier, const QDateTime &latter, cl::model::LogCollection::ptr logCollection)
{
    qDebug() << __FILE__ << __LINE__ << earlier;
    qDebug() << __FILE__ << __LINE__ << latter;
    qDebug() << __FILE__ << __LINE__ << logCollection->size();

    if (logCollection->size() > 0) {
        qDebug() << __FILE__ << __LINE__;

        cm::Key key(alg::Key::create(
                earlier.toString(cm::DATE_TIME_TEMPLATE.c_str())
                , latter.toString(cm::DATE_TIME_TEMPLATE.c_str())));
        auto logsIT = logsWindows.find(key);
        if ( logsIT != logsWindows.end()) {
            qDebug() << __FILE__ << __LINE__;
            logsIT->second->showNormal();
        } else {
            qDebug() << __FILE__ << __LINE__;
            auto logsWindow = win::Logs::create(key, key);
            logsWindow->resize(300, 400);
            logsWindow->show();
            logsWindows.insert(std::make_pair(key, logsWindow));
            for (auto it = logCollection->getBegin(); it != logCollection->getEnd(); ++it) {
                logsWindow->addLog(it->second);
            }


            // @work przywrócić zamykanie wszystkich okien po zamknięciu aplikacji
            //connect(logsWindow.data(), &win::Logs::closedWindow, this, &MainWindow::closedWindow, connectionType);
        }
    }
}


}
