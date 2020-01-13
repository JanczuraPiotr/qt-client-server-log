//
// Created by piotr@janczura.pl on 2019.12.22
//

#ifndef CLIENT_CONTROLLER_MAIN
#define CLIENT_CONTROLLER_MAIN

#include <QObject>
#include <QDateTime>

#include "common/def.h"
#include "client/view/MainWindow.h"
#include "client/view/windows/Logs.h"
#include "client/model/LogCollection.h"

namespace cl::controller {

class Main : public QObject {
    friend class cl::view::MainWindow;
    Q_OBJECT
public:

    static Main& instance();
    ~Main() override;

public: signals:
    void netCommand(const cm::NetCommand &command);

public slots:
    void closeMainWindow();
    void closedWindow(const cm::Key &key);
    void log(cm::AutoId logId, const QDateTime &timestamp, cm::LogPriority logPriority, const cm::Message &message);
    void logsBetween(const QDateTime &earlier, const QDateTime &latter, cl::model::LogCollection::ptr logCollection);

private: // methods
    Main();
    void closeAllWindows();
    void loadLogsBetween(const cm::DateTime &earlier, const cm::DateTime &latter);

private: // attributes
    cl::view::MainWindow mainWindow;
    cl::view::window::Logs::map logsWindows;
    Qt::ConnectionType connectionType;

public: // lock
    Main(const Main &) = delete;
    Main(Main &&) = delete;
    Main &operator = (const Main&) = delete;
    Main &operator = (Main &&) = delete;
};

}



#endif
