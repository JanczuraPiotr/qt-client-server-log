//
// Created by piotr@janczura.pl on 2019.11.11
//

#include "SignalBus.h"


namespace sv {


SignalBus::SignalBus()
        : signalsSenders()
        , signalsListeners()
        , connections()
{
}

SignalBus &SignalBus::instance()
{
    static SignalBus s;
    return s;
}

void SignalBus::registerSender(const QString &signalName, QObject *sender, const char *senderSignalName)
{
    saveSender(signalName, sender, senderSignalName);
    connectListeners(signalName, sender, senderSignalName);
}

void SignalBus::registerListener(const QString &signalName, QObject *receiver, const char *slotName)
{
    saveListener(signalName, receiver, slotName);
    connectSender(signalName, receiver, slotName);
}

void SignalBus::saveSender(const QString &signalName, QObject *sender, const char *senderSignalName)
{
    auto it = signalsSenders.find(signalName);
    if (it != signalsSenders.end()) {
        Sender newSender(sender, senderSignalName);
        if (searchSignalsSenders(signalName, sender) == -1) {
            it.value().push_back(newSender);
        }
    } else {
        auto newIt = signalsSenders.insert(signalName, Listeners());
        newIt.value().push_back(Sender(sender, senderSignalName));
    }

}

void SignalBus::saveListener(const QString &signalName, QObject *listener, const char *slotName)
{
    auto it = signalsListeners.find(signalName);
    if (it != signalsListeners.end()) {
        Listener newListener(listener, slotName);
        if (searchSignalsListeners(signalName, listener) == -1) {
            it.value().push_back(newListener);
        }
    } else {
        auto newIt = signalsListeners.insert(signalName, Listeners());
        newIt.value().push_back(Listener(listener, slotName));
    }
}

void SignalBus::connectListeners(const QString &signalName, QObject *sender, const char *senderSignalName)
{
    auto signalListenersIt = signalsListeners.find(signalName);
    if (signalListenersIt != signalsListeners.end()) {
        Listeners listeners = signalListenersIt.value();
        for (auto &listenersIt : listeners) {
            if (possibleConnection(signalName, sender, listenersIt.first)) {
                dynamicConnection(sender, senderSignalName, listenersIt.first, listenersIt.second);
            }
        }
    }
}

void SignalBus::connectSender(const QString &signalName, QObject *listener, const char *slotName)
{
    auto sendersIt = signalsSenders.find(signalName);
    if (sendersIt != signalsSenders.end()) {
        auto senders= sendersIt.value();
        for (int i = 0; i < senders.size(); ++i) {
            if (possibleConnection(signalName, senders.value(i).first, listener)) {
                dynamicConnection(senders.value(i).first, senders.value(i).second, listener, slotName);
            }
        }
    }
}

bool SignalBus::possibleConnection(const QString &signalName, QObject *sender, QObject *listener)
{
    auto connIt = connections.find(signalName);

    if (connIt != connections.end()) {
        for (auto &item : connIt.value() ) {
            if (item.first == sender && item.second == listener) {
                return false;
            }
        }
        Connection newConnection(sender, listener);
        connIt.value().push_back(newConnection);
        return true;
    } else{
        auto connIt = connections.insert(signalName, QVector<Connection>());
        Connection newConnection(sender, listener);
        connIt.value().push_back(newConnection);
        return true;
    }
}

int SignalBus::searchSignalsListeners(const QString &signalName, QObject *listener)
{
    auto signalsListenersIt = signalsListeners.find(signalName);
    if (signalsListenersIt != signalsListeners.end()) {
        auto listeners = signalsListenersIt.value();
        for (int i = 0; i < listeners.size(); ++i) {
            if (listeners[i].first == listener) {
                return i;
            }
        }
    }
    return -1;
}

int SignalBus::searchSignalsSenders(const QString &signalName, QObject *sender)
{
    auto signalsSendersIt = signalsSenders.find(signalName);
    if (signalsSendersIt != signalsSenders.end()) {
        auto senders = signalsSendersIt.value();
        for (int i = 0; i < senders.size(); ++i) {
            if (senders[i].first == sender) {
                return i;
            }
        }
    }
    return -1;
}

void SignalBus::unregisterSender(const QString &signalName, QObject *sender)
{
    auto senderIx = searchSignalsSenders(signalName, sender);
    if (senderIx != -1) {
        signalsSenders[signalName].remove(senderIx);
        auto item = connections[signalName].begin();
        while (item != connections[signalName].end()) {
            if (item->first == sender) {
                item = connections[signalName].erase(item);
            }
        }
        if (connections[signalName].empty()){
            connections.remove(signalName);
        }
    }
}

void SignalBus::unregisterListener(const QString &signalName, QObject *listener)
{
    auto listenerIx = searchSignalsListeners(signalName, listener);
    if (listenerIx != -1) {
        signalsListeners[signalName].remove(listenerIx);
        auto v = connections[signalName];
        auto item = connections[signalName].begin();
        while (item != connections[signalName].end()) {
            if (item->second == listener) {
                item = connections[signalName].erase(item);
            }
        }
        if (connections[signalName].empty()){
            connections.remove(signalName);
        }
    }
}

QMetaMethod SignalBus::fetchIndexOfMethod(QObject* obj, const char* name)
{
    const QMetaObject* meta_object = obj->metaObject();
    QByteArray normalized_name = QMetaObject::normalizedSignature(name);
    int index = meta_object->indexOfMethod(normalized_name);
    Q_ASSERT(index != -1);
    return meta_object->method(index);
}

void SignalBus::dynamicConnection(
        QObject* source,
        const char* signalName,
        QObject* dest,
        const char* slotName,
        bool blocking)
{
    if (blocking) {
        QObject::connect(source, fetchIndexOfMethod(source, signalName),
                         dest, fetchIndexOfMethod(dest, slotName)
                , Qt::BlockingQueuedConnection);
    } else {
        QObject::connect(source, fetchIndexOfMethod(source, signalName),
                         dest, fetchIndexOfMethod(dest, slotName));
    }
}



}