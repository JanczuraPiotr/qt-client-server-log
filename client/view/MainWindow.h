//
// Created by piotr@janczura.pl on 2019.12.24
//

#ifndef CLIENT_VIEW_MAINWINDOW_H
#define CLIENT_VIEW_MAINWINDOW_H

#include <QMenuBar>
#include <QAction>
#include <QMainWindow>
#include <QObject>
#include <client/model/LogRecord.h>

#include "LogsTable.h"
#include "common/def.h"

namespace cl::view {

class LogsTable;

class MainWindow : public QMainWindow {
    //Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override = default;

    void log(cl::model::LogRecord::ptr logRecord);

private: // methods
    void initMenus();
    void showLogsBefore();
    void showLogsAfter();
    void showLogsBetween();

private: // attributes
    QAction *logsAfterAction;
    QAction *logsBeforeAction;
    QAction *logsBetweenAction;

    LogsTable logsTable;

private:
    MainWindow(const MainWindow& ) = delete;

};
}


#endif //CLIENT_VIEW_MAINWINDOW_H
