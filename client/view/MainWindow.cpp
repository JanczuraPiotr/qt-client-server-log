//
// Created by piotr@janczura.pl on 2019.12.24
//

#include "MainWindow.h"

#include <QAction>
#include <QMenuBar>
#include <QDebug>

namespace cl::view {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , logsTable(this)
{
    resize(500, 400);
    createMenus();
    setWindowTitle(tr("Przegląd logów"));

    setCentralWidget(&logsTable);
}

void MainWindow::createMenus()
{
    logsBeforeAction = new QAction(tr("Logi prze&d datą"), this);
    menuBar()->addAction(logsBeforeAction);
    connect(logsBeforeAction, &QAction::triggered, this, &MainWindow::showLogsBefore);

    logsAfterAction  = new QAction(tr("Logi p&o dacie"), this);
    menuBar()->addAction(logsAfterAction);
    connect(logsAfterAction, &QAction::triggered, this, &MainWindow::showLogsAfter);

    logsBetweenAction  = new QAction(tr("Logi po&między datami"), this);
    menuBar()->addAction(logsBetweenAction);
    connect(logsBetweenAction, &QAction::triggered, this, &MainWindow::showLogsBetween);
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
