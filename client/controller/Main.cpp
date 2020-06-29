//
// Created by piotr@janczura.pl on 2019.12.22
//

#include "Main.h"

#include <QDebug>
#include <QApplication>
#include <QThread>

#include "common/algorithm/String.h"
#include "common/algorithm/Key.h"
#include "model/LogCollection.h"
#include "client/view/windows/Logs.h"

namespace cl::controller {

namespace win = cl::view::window;
namespace alg = cm::alg;

Main& Main::instance()
{
    static Main main;
    return main;
}

Main::Main()
    : mainWindow(reinterpret_cast<Main&>(*this))
    , logsWindows()
    , connectionType(Qt::ConnectionType::AutoConnection)
{
    mainWindow.show();
    connect(&mainWindow, &cl::view::MainWindow::closeMainWindow, this, &Main::closeMainWindow);
}

Main::~Main()
{
    closeAllWindows();
    if (mainWindow.isVisible()) {
        mainWindow.close();
    }
}

void Main::closeAllWindows()
{
    for (auto &it : logsWindows) {
        it.second->close();
        logsWindows.erase(it.first);
    }
}

void Main::closeMainWindow()
{
    closeAllWindows();
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
                           cm::alg::String::dateTimeInNetCommand(earlier) + "|" +
                           cm::alg::String::dateTimeInNetCommand(latter));
    emit netCommand(command);
}

void Main::closedWindow(const cm::Key &key)
{
    std::ignore = key;
    logsWindows.erase(key);
}

void Main::logsBetween(const QDateTime &earlier, const QDateTime &latter, cl::model::LogCollection::ptr logCollection)
{
    if (logCollection->size() > 0) {
        // @task komunikat na wypadek pustej odpowiedzi gdy nie jest wyświetlane okno z logami

        cm::Key key(alg::Key::create(
                earlier.toString(cm::DATE_TIME_TEMPLATE.c_str())
                , latter.toString(cm::DATE_TIME_TEMPLATE.c_str())));
        auto logsIT = logsWindows.find(key);
        if ( logsIT != logsWindows.end()) {
            logsIT->second->showNormal();
        } else {
            auto logsWindow = win::Logs::create(key, key);
            logsWindow->resize(300, 400);
            logsWindow->show();
            logsWindows.insert(std::make_pair(key, logsWindow));
            for (auto it = logCollection->getBegin(); it != logCollection->getEnd(); ++it) {
                logsWindow->addLog(it->second);
            }
            connect(logsWindow.data(), &win::Logs::closedWindow, this, &Main::closedWindow, connectionType);
        }
    }
}


}
