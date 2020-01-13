//
// Created by piotr@janczura.pl on 2020.01.03
//

#ifndef CLIENT_WINDOW_LOGS
#define CLIENT_WINDOW_LOGS

#include <QWidget>
#include <QMap>
#include <QCloseEvent>
#include <map>

#include "common/def.h"
#include "client/view/table/Logs.h"


// @task Jeżeli dla wyświetlenia okna były potrzebne logi z dłuższego okresu niż przewidziano do trzymania lokalnie należy te logi usunąć

namespace cl::view::window {
class Logs : public QWidget {
    Q_OBJECT
public:
    typedef QSharedPointer<Logs> ptr;
    typedef std::map<cm::Key, ptr> map;
    static ptr create(const QString &title, const cm::Key &key, QWidget *pointer = nullptr);

    ~Logs() override;
    void addLog(cl::model::LogRecord::ptr logRecord);

signals:
    void closedWindow(const cm::Key windowKey);

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    explicit Logs(const QString &title, const cm::Key &key, QWidget *parent = nullptr);
    cm::Key key;
    cl::view::table::Logs logsTable;


};

}


#endif
