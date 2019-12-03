//
// Created by piotr@janczura.pl on 2019.11.11
//

#ifndef SERVER_SIGNALBUS_H
#define SERVER_SIGNALBUS_H


#include <QMap>
#include <QObject>
#include <QPair>
#include <QMetaMethod>
#include <QDebug>
#include <QVector>


namespace sv {


class SignalBus : public QObject {
    Q_OBJECT
public:
    static const bool BLOCKING_CONNECTION = true;
    static const bool NONBLOCKING_CONNECTION = false;

    static SignalBus &instance();
    ~SignalBus() override = default;

    void registerSender(const QString &signalName, QObject *sender, const char *senderSignalName);
    void registerListener(const QString &signalName, QObject *receiver, const char *slotName);

    void unregisterSender(const QString &signalName, QObject *sender);
    void unregisterListener(const QString &signalName, QObject *receiver);

    void dynamicConnection(
            QObject* source
            , const char* signalName
            , QObject* dest
            , const char* slotName
            , bool blocking = NONBLOCKING_CONNECTION);

private: // typedef

    // key : listener
    // val : listener method name
    typedef QPair<QObject*, const char*>    Listener;
    typedef QVector<Listener>               Listeners;
    // key : sender
    // val : sender signal name
    typedef QPair<QObject*, const char*>    Sender;
    typedef QVector<Sender>                 Senders;
    // key : signal name
    // val : signalsSenders
    typedef QMap<QString, Senders>          SignalsSenders;
    // key : signal name
    // val : listeners
    typedef QMap<QString, Listeners>        SignalsListeners;
    // first : sender
    // second : listener
    typedef QPair<QObject *, QObject*>      Connection;
    typedef QMap<QString, QVector<Connection> >  Connections;

private: // methods

    void saveSender(const QString &signalName, QObject *sender, const char *senderSignalName);
    void saveListener(const QString &signalName, QObject *listener, const char *slotName);
    void connectSender(const QString &signalName, QObject *listener, const char *slotName);
    void connectListeners(const QString &signalName, QObject *sender, const char *senderSignalName);
    bool possibleConnection(const QString &signalName, QObject *sender, QObject *listener);
    int searchSignalsSenders(const QString &signalName, QObject *sender);
    int searchSignalsListeners(const QString &signalName, QObject *listener);

    QMetaMethod fetchIndexOfMethod(QObject* obj, const char* name);

private: // attributes

    SignalsSenders      signalsSenders;
    SignalsListeners    signalsListeners;
    Connections         connections;

private: // Lock

    SignalBus();
};

}


#endif //SERVER_SIGNALBUS_H
