//
// Created by piotr@janczura.pl on 2019.11.12
//

#ifndef SERVICE_NETCONNECTION_H
#define SERVICE_NETCONNECTION_H

#include <QObject>
#include <QtWebSockets>
#include <QMap>
#include "common/def.h"

namespace server::service {

class NetConnection : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(NetConnection)
public:

    static NetConnection &instance();
    ~NetConnection() override;

    void start();

public slots:

void insertedLog(
        cm::AutoId id
        , const QDateTime &dateTime
        , cm::LogPriority logPriority
        , const cm::Message &message);

private: // typedef

    typedef QMap<cm::TCPPort, QWebSocket *> SocketList;

private: // methods

    explicit NetConnection();
    QString initialMessage();

public slots:
    // for external signals
    void broadcastToNet(const QString &msg);

private slots:
    // for internal signals
    void onNewConnection();
    void processMessage(const QString &message);
    void socketDisconnected();

private:

    QWebSocketServer *socketServer;
    SocketList socketsClients;

};

}


#endif //SERVICE_NETCONNECTION_H
