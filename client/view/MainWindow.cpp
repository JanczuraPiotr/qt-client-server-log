//
// Created by piotr@janczura.pl on 2019.12.24
//

#include "MainWindow.h"

#include <QDebug>

namespace cl::view {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , logsAfterAction([=](){ return new QAction(tr("Logi p&o dacie"), this);}())
    , logsBeforeAction([=](){ return new QAction(tr("Logi po&między datami"), this);}())
    , logsBetweenAction([=](){ return new QAction(tr("Logi prze&d datą"), this);}())
    , logsTable(this)
{
    resize(500, 400);
    initMenus();
    setWindowTitle(tr("Przegląd logów"));

    setCentralWidget(&logsTable);
}

void MainWindow::initMenus()
{
    menuBar()->addAction(logsBeforeAction);
    connect(logsBeforeAction, &QAction::triggered, this, &MainWindow::showLogsBefore);

    menuBar()->addAction(logsAfterAction);
    connect(logsAfterAction, &QAction::triggered, this, &MainWindow::showLogsAfter);

    menuBar()->addAction(logsBetweenAction);
    connect(logsBetweenAction, &QAction::triggered, this, &MainWindow::showLogsBetween);
}

void MainWindow::log(cl::model::LogRecord::ptr logRecord)
{
    logsTable.log(logRecord);
}

void MainWindow::showLogsBefore()
{
    qDebug() << "MainWindow::showLogsBefore()";
}

void MainWindow::showLogsAfter()
{
    qDebug() << "MainWindow::showLogsAfter()";
}

void MainWindow::showLogsBetween()
{
    qDebug() << "MainWindow::showLogsBetween()";
}



}
