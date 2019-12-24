//
// Created by piotr@janczura.pl on 2019.12.24
//

#ifndef SERVER_VIEW_LOGSTABLE_H
#define SERVER_VIEW_LOGSTABLE_H


#include <QtWidgets/QTableView>
#include <QObject>

namespace cl::view {


class LogsTable : public QTableView {
    Q_OBJECT
public:
    LogsTable(QWidget *parent);

private: // methods
    void initColumns();

};

}

#endif //SERVER_VIEW_LOGSTABLE_H
