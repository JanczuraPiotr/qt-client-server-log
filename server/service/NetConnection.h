//
// Created by piotr@janczura.pl on 2019.11.12
//

#ifndef SERVICE_NETCONNECTION_H
#define SERVICE_NETCONNECTION_H

#include <QObject>
#include <QtWebSockets>
//#include <QMap>
#include <QDateTime>

#include "common/def.h"

namespace sv::service {

class NetConnection : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(NetConnection)
public:

    static NetConnection &instance();
    ~NetConnection() override;

    void start();


private: // typedef

    typedef QMap<cm::TCPPort, QWebSocket *> SocketList;

private: // methods

    explicit NetConnection();
    QString initialMessage();

public :
    signals:

    void getLogsAfter(const QDateTime &borderMoment, cm::TCPPort clientsPort);
    void getLogsBefore(const QDateTime &borderMoment, cm::TCPPort clientsPort);
    void getLogsBetween(const QDateTime &borderEarlier, const QDateTime &borderLatter, cm::TCPPort clientsPort);
    void stopPushingLogs(cm::TCPPort clientsPort);
    void startPushingLogs(cm::TCPPort clientsPort);

public slots: // for external signals
    void broadcastToNet(const QString &msg);
    void insertedLog(
            cm::AutoId id
            , const QDateTime &dateTime
            , cm::LogPriority logPriority
            , const cm::Message &message);

private slots: // for internal signals
    void onNewConnection();
    void processMessage(const QString &message);
    void socketDisconnected();

private:

    QWebSocketServer *socketServer;
    SocketList socketsClients;

};

}


#endif //SERVICE_NETCONNECTION_H
