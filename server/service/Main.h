//
// Created by piotr@janczura.pl on 2019.12.17
//

#ifndef SERVER_SERVICE_MAIN
#define SERVER_SERVICE_MAIN

#include <QObject>

#include "common/def.h"

namespace sv::service {
    
class Main : public QObject {
    Q_OBJECT
public:
    static Main& instance();
    ~Main() override = default;

public slots:
    void getLogsBetween(const QDateTime &limitEarlier, const QDateTime &limitLatter, cm::TCPPort clientsPort);

signals:
    void messageToClient(const QString &logs, cm::TCPPort clientsPort);

private: // methods
    Main();

public: // lock
    Main(const Main &) = delete;
    Main(Main &&) = delete;
    Main &operator = (const Main&) = delete;
    Main &operator = (Main &&) = delete;
};

}


#endif
