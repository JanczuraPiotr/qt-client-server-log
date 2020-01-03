//
// Created by piotr@janczura.pl on 2020.01.03
//

#ifndef QT_CLIENT_SERVER_LOG_LOGS_H
#define QT_CLIENT_SERVER_LOG_LOGS_H

#include <QWidget>
#include <QWidget>
#include <QMap>
#include <QCloseEvent>
#include <map>
#include "common/def.h"

// @task Jeżeli dla wyświetlenia okna były potrzebne logi z dłuższego okresu niż przewidziano do trzymania lokalnie należy te logi usunąć

namespace cl::view::window {
class Logs : public QWidget {
    Q_OBJECT
public:
    typedef QSharedPointer<Logs> ptr;
    typedef std::map<cm::Key, ptr> map;
    static ptr create(const QString &title, const cm::Key &key, QWidget *pointer = nullptr);

    ~Logs() override;

signals:
    void closedWindow(const cm::Key windowKey);

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    explicit Logs(const QString &title, const cm::Key &key, QWidget *parent = nullptr);
    cm::Key key;

};

}



#endif //QT_CLIENT_SERVER_LOG_LOGS_H
