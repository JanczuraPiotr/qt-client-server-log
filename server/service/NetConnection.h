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

    typedef std::map<cm::TCPPort, QWebSocket *> SocketList;
    typedef std::vector<cm::TCPPort> LogsListeners;

private: // methods

    explicit NetConnection();
    QString initialMessage();
    void stopPushingLogs(cm::TCPPort clientsPort);
    void startPushingLogs(cm::TCPPort clientsPort);


public :
    signals:

    void getLogsAfter(const QDateTime &borderMoment, cm::TCPPort clientsPort);
    void getLogsBefore(const QDateTime &borderMoment, cm::TCPPort clientsPort);
    void getLogsBetween(const QDateTime &borderEarlier, const QDateTime &borderLatter, cm::TCPPort clientsPort);

public slots: // for external signals
    void messageToClient(const QString &msg, cm::TCPPort clientsPort);
    void broadcastToNet(const QString &msg);
    void broadcastLogToNet(const QString &msg);
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
    // Wszyscy klienci podłączeni do socketServer
    SocketList socketsClients;
    // Klienci oczekujący na powiadomienie o każdym nowym logu.
    // Każdy nowy klient domyślnie dodawany jest do listy.
    LogsListeners logsListeners;

};

}


#endif //SERVICE_NETCONNECTION_H
