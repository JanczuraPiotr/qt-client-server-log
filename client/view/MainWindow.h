//
// Created by piotr@janczura.pl on 2019.12.24
//

#ifndef CLIENT_VIEW_MAINWINDOW
#define CLIENT_VIEW_MAINWINDOW

#include <QMenuBar>
#include <QAction>
#include <QMainWindow>
#include <QObject>

#include "client/model/LogRecord.h"
#include "client/view/table/Logs.h"
#include "common/def.h"

namespace cl::controller {
    class Main;
}

// @task zamknij wszystkie okna po zamknięciu okna aplikacji
namespace cl::view {

class Logs;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(cl::controller::Main &owner);
    ~MainWindow() override;

    void log(cl::model::LogRecord::ptr logRecord);
    void closeEvent(QCloseEvent *event) override;

public slots:
    void closedWindow(const cm::Key &key);

private: // methods
    void initMenus();
    void showLogsBetween();

private: // attributes
    cl::controller::Main &owner;
    QAction logsBetweenAction;

    cl::view::table::Logs logsTable;

    Qt::ConnectionType connectionType;

private:
    MainWindow(const MainWindow& ) = delete;

};
}


#endif
