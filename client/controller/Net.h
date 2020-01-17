//
// Created by piotr@janczura.pl on 2019.11.20
//

#ifndef CLIENT_CONSTROLLER_NET
#define CLIENT_CONSTROLLER_NET

#include <QObject>
#include <QDateTime>
#include <QtWebSockets>
#include <QString>

#include "client/model/LogCollection.h"
#include "common/def.h"

namespace cl::controller {

class Net : public QObject {
    Q_OBJECT
public:
    explicit Net(const QString &url, cm::TCPPort serverIPPort);
    virtual ~Net();

public: signals:
    void log(cm::AutoId logId, const QDateTime &timestamp, cm::LogPriority logPriority, const cm::Message &message);
    void logsBetween(const QDateTime &earlier, const QDateTime &latter, cl::model::LogCollection::ptr logCollection);

public slots:
    void netCommand(const cm::NetCommand &command);

private slots: // for internal signals
    void onConnected();
    void onDisconnected();
    void onTextMessageReceived(const cm::NetInput &netInput);

private: // methods
    void openSocket();

private: // attributes
    QString url_;
    cm::TCPPort serverIPPort_;
    QWebSocket socket_;
    cm::NetProtocol netProtocol;// @work uruchomić możliwość wyboru protokołu
    bool connected_;
    int tries_;
    QDateTime lastConnectionAttempt_;

};

}



#endif //QT_CLIENT_SERVER_LOG_NET_H
