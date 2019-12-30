//
// Created by piotr@janczura.pl on 2019.12.22
//

#ifndef CLIENT_CONTROLLER_MAIN_H
#define CLIENT_CONTROLLER_MAIN_H

#include <QObject>
#include <QDateTime>

#include "common/def.h"
#include "client/view/MainWindow.h"

namespace cl::controller {

class Main : public QObject {
Q_OBJECT
public:

    static Main& instance();
    ~Main() override = default;

public slots:

    void log(cm::AutoId logId, const QDateTime &timestamp, cm::LogPriority logPriority, const cm::Message &message);

private: // methods
    Main();

private: // attributes
    cl::view::MainWindow mainWindow;

public: // lock
    Main(const Main &) = delete;
    Main(Main &&) = delete;
    Main &operator = (const Main&) = delete;
    Main &operator = (Main &&) = delete;
};

}



#endif //CLIENT_CONTROLLER_MAIN_H
