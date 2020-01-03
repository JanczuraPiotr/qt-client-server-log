//
// Created by piotr@janczura.pl on 2019.12.24
//

#ifndef SERVER_VIEW_LOGSTABLE_H
#define SERVER_VIEW_LOGSTABLE_H

#include <QStandardItemModel>
#include <QStandardItem>
#include <QtWidgets/QTableView>
#include <QObject>

#include "common/def.h"
#include "client/model/LogRecord.h"

namespace cl::view::table {

class Logs : public QTableView {
    Q_OBJECT
public:
    static const int COL_ID_IX = 0;
    static const int COL_ID_HEIGHT = 70;
    static const int COL_DATE_IX = 1;
    static const int COL_DATE_HEIGHT = 150;
    static const int COL_PRIORITY_IX = 2;
    static const int COL_PRIORITY_HEIGHT = 100;
    static const int COL_MESSAGE_IX = 3;
    static const int COL_MESSAGE_HEIGHT  = 300;

public:
    explicit Logs(QWidget *parent = nullptr);

    void log(model::LogRecord::ptr logRecord);

private: // methods
    void initColumns();

private: // attributes
    QStandardItemModel model;

};

}


#endif //SERVER_VIEW_LOGSTABLE_H
