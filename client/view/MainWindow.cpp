//
// Created by piotr@janczura.pl on 2019.12.24
//

#include "MainWindow.h"

#include <QDebug>
#include <QThread>
#include <QApplication>

#include "client/controller/Main.h"
#include "client/view/dialogs/LogsBetween.h"
#include "client/view/table/Logs.h"
#include "client/view/windows/Logs.h"

namespace cl::view {

namespace win = cl::view::window;
namespace dlg = cl::view::dialog;

MainWindow::MainWindow(cl::controller::Main &owner)
    : QMainWindow()
    , owner(owner)
    , logsBetweenAction([=](){ return QAction(tr("Logi prze&filtrowane"), this);}())
    , logsTable(this)
{
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
    event->accept();
    emit closeMainWindow();
}

void MainWindow::showLogsBetween()
{
    dlg::LogsBetween dialogBetween(this);
    // @task jeżeli wybrany okres jest już wyświetlony - odnaleźć okno i wyświetlić je jako pierwsze
    if (dialogBetween.exec()) {
        owner.loadLogsBetween(dialogBetween.getBorderEarlier(), dialogBetween.getBorderLatter());
    }
}

}
