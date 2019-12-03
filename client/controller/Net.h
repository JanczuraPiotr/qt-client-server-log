//
// Created by piotr@janczura.pl on 2019.11.20
//

#ifndef QT_CLIENT_SERVER_LOG_NET_H
#define QT_CLIENT_SERVER_LOG_NET_H

#include <QObject>
#include <QDateTime>
#include <QtWebSockets>
#include <QString>

#include "common/def.h"

namespace cl::controller {

class Net : public QObject {
    Q_OBJECT
public:
    explicit Net(const QString &url, cm::TCPPort serverIPPort);
    virtual ~Net();

private slots: // for internal signals
    void onConnected();
    void onDisconnected();
    void onTextMessageReceived(const QString &msg);

private: // methods
    void openSocket();

private: // attributes
    QString url_;
    cm::TCPPort serverIPPort_;
    QWebSocket socket_;
    bool connected_;
    int tries_;
    QDateTime lastConnectionAttempt_;

};

}



#endif //QT_CLIENT_SERVER_LOG_NET_H