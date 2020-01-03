//
// Created by piotr@janczura.pl on 2019.12.24
//

#include "MainWindow.h"

#include <QDebug>
#include <QThread>
#include <QCoreApplication>

#include "client/view/dialogs/LogsBefore.h"
#include "client/view/dialogs/LogsBetween.h"
#include "client/view/dialogs/LogsAfter.h"
#include "client/view/table/Logs.h"
#include "client/view/windows/Logs.h"
#include "common/algorithm/Key.h"

namespace cl::view {

MainWindow::MainWindow()
    : QMainWindow()
    , logsAfterAction([=](){ return QAction(tr("Logi p&o dacie"), this);}())
    , logsBeforeAction([=](){ return QAction(tr("Logi prze&d datą"), this);}())
    , logsBetweenAction([=](){ return QAction(tr("Logi po&między datami"), this);}())
    , logsTable(this)
    , logsWindows()
    , connectionType(Qt::ConnectionType::AutoConnection)
{
    const int MARGIN = 50;
    const int WIDTH = 400;

    resize(
            MARGIN +
            cl::view::table::Logs::COL_ID_HEIGHT +
            cl::view::table::Logs::COL_DATE_HEIGHT +
            cl::view::table::Logs::COL_PRIORITY_HEIGHT +
            cl::view::table::Logs::COL_MESSAGE_HEIGHT

            , WIDTH);

    initMenus();
    setWindowTitle(tr("Przegląd logów"));

    setCentralWidget(&logsTable);
}

MainWindow::~MainWindow()
{
    qDebug() << __FILE__ << __LINE__;
}

void MainWindow::initMenus()
{
    menuBar()->addAction(&logsBeforeAction);
    connect(&logsBeforeAction, &QAction::triggered, this, &MainWindow::showLogsBefore);

    menuBar()->addAction(&logsAfterAction);
    connect(&logsAfterAction, &QAction::triggered, this, &MainWindow::showLogsAfter);

    menuBar()->addAction(&logsBetweenAction);
    connect(&logsBetweenAction, &QAction::triggered, this, &MainWindow::showLogsBetween);
}

void MainWindow::log(cl::model::LogRecord::ptr logRecord)
{
    logsTable.log(logRecord);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    event->accept();
    for (auto &it : logsWindows) {
        it.second->close();
        logsWindows.erase(it.first);
    }
}

void MainWindow::closedWindow(const cm::Key &key)
{
    logsWindows.erase(key);
}

void MainWindow::showLogsBefore()
{
    namespace win = cl::view::window;
    namespace alg = cm::algorithm;
    namespace dlg = cl::view::dialog;

    dlg::LogsBefore dialogBefore(this);
    if (dialogBefore.exec()) {
        cm::Key key(alg::Key::create("", dialogBefore.getBorderMoment()));
        auto logsIT = logsWindows.find(key);
        if ( logsIT != logsWindows.end()) {
            logsIT->second->showNormal();
        } else {
            auto logsWindow = win::Logs::create(key, key);
            logsWindow->resize(300,400);
            logsWindow->show();
            logsWindows.insert(std::make_pair(key, logsWindow));
            connect(logsWindow.data(), &win::Logs::closedWindow, this, &MainWindow::closedWindow, connectionType);
        }
    }
}

void MainWindow::showLogsAfter()
{
    namespace win = cl::view::window;
    namespace alg = cm::algorithm;
    namespace dlg = cl::view::dialog;

    cl::view::dialog::LogsAfter dialogAfter(this);
    if (dialogAfter.exec()) {
        cm::Key key(alg::Key::create(dialogAfter.getBorderMoment(), ""));
        auto logsIT = logsWindows.find(key);
        if ( logsIT != logsWindows.end()) {
            logsIT->second->showNormal();
        } else {
            auto logsWindow = win::Logs::create(key, key);
            logsWindow->resize(300, 400);
            logsWindow->show();
            logsWindows.insert(std::make_pair(key, logsWindow));
            connect(logsWindow.data(), &win::Logs::closedWindow, this, &MainWindow::closedWindow, connectionType);
        }
    }
}

void MainWindow::showLogsBetween()
{
    namespace win = cl::view::window;
    namespace alg = cm::algorithm;
    namespace dlg = cl::view::dialog;

    dlg::LogsBetween dialogBetween(this);
    if (dialogBetween.exec()) {
        cm::Key key(alg::Key::create(dialogBetween.getBorderEarlier(), dialogBetween.getBorderLatter()));
        auto logsIT = logsWindows.find(key);
        if ( logsIT != logsWindows.end()) {
            logsIT->second->showNormal();
        } else {
            auto logsWindow = win::Logs::create(key, key);
            logsWindow->resize(300, 400);
            logsWindow->show();
            logsWindows.insert(std::make_pair(key, logsWindow));
            connect(logsWindow.data(), &win::Logs::closedWindow, this, &MainWindow::closedWindow, connectionType);
        }
    }
}

}
