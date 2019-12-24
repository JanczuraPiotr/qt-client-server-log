//
// Created by piotr@janczura.pl on 2019.12.24
//

#ifndef CLIENT_VIEW_MAINWINDOW_H
#define CLIENT_VIEW_MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include "LogsTable.h"

namespace cl::view {


class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private: // methods
    void createMenus();
    void showLogsBefore();
    void showLogsAfter();
    void showLogsBetween();

private: // attributes
    QAction *logsBetweenAction;
    QAction *logsAfterAction;
    QAction *logsBeforeAction;

    LogsTable logsTable;
};
}


#endif //CLIENT_VIEW_MAINWINDOW_H
