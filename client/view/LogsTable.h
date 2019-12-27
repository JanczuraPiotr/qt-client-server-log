//
// Created by piotr@janczura.pl on 2019.12.24
//

#ifndef SERVER_VIEW_LOGSTABLE_H
#define SERVER_VIEW_LOGSTABLE_H

#include <QStandardItemModel>
#include <QtWidgets/QTableView>
#include <QObject>

#include "common/def.h"
#include "client/model/LogRecord.h"

namespace cl::view {


class LogsTable : public QTableView {
    Q_OBJECT
public:
    explicit LogsTable(QWidget *parent);

    void log(cl::model::LogRecord::ptr logRecord);

private: // methods
    void initColumns();

private: // attributes
    QStandardItemModel *model;

};

}

#endif //SERVER_VIEW_LOGSTABLE_H
