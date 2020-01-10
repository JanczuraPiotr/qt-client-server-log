//
// Created by piotr@janczura.pl on 2019.12.24
//

#include "MainWindow.h"

#include <QDebug>
#include <QThread>
#include <QCoreApplication>

#include "client/controller/Main.h"
#include "client/view/dialogs/LogsBetween.h"
#include "client/view/table/Logs.h"
#include "client/view/windows/Logs.h"
#include "common/algorithm/Key.h"

namespace cl::view {

namespace win = cl::view::window;
namespace alg = cm::algorithm;
namespace dlg = cl::view::dialog;

MainWindow::MainWindow(cl::controller::Main &owner)
    : QMainWindow()
    , owner(owner)
    , logsBetweenAction([=](){ return QAction(tr("Logi prze&filtrowane"), this);}())
    , logsTable(this)
    , connectionType(Qt::ConnectionType::AutoConnection)
{
    // @work powtórzenie
    const int MARGIN = 50;
    const int WIDTH = 400;

    setFixedSize(
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
    menuBar()->addAction(&logsBetweenAction);
    connect(&logsBetweenAction, &QAction::triggered, this, &MainWindow::showLogsBetween);
}

void MainWindow::log(cl::model::LogRecord::ptr logRecord)
{
    logsTable.log(logRecord);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    std::ignore = event;
    // @work przenieść do cl::controller::Main
//    event->accept();
//    for (auto &it : logsWindows) {
//        it.second->close();
//        logsWindows.erase(it.first);
//    }
}

void MainWindow::closedWindow(const cm::Key &key)
{
    std::ignore = key;
    // @work przenieść do cl::controller::Main
//    logsWindows.erase(key);
}

void MainWindow::showLogsBetween()
{
    dlg::LogsBetween dialogBetween(this);
    if (dialogBetween.exec()) {
        owner.loadLogsBetween(dialogBetween.getBorderEarlier(), dialogBetween.getBorderLatter());
    }
}

}
