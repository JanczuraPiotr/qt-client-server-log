//
// Created by piotr@janczura.pl on 2019.12.24
//

#include "LogsTable.h"
#include <QStandardItemModel>
#include <QStandardItem>

namespace cl::view {

LogsTable::LogsTable(QWidget *parent)
    : QTableView(parent)
{
    initColumns();
}

void LogsTable::initColumns() {
    QStandardItemModel *mod = new QStandardItemModel();
    QStandardItem *id = new QStandardItem(tr("ID"));
    mod->setHorizontalHeaderItem(0, id);
    QStandardItem *time = new QStandardItem(tr("Czas"));
    mod->setHorizontalHeaderItem(1, time);
    QStandardItem *priorytet = new QStandardItem(tr("Priorytet"));
    mod->setHorizontalHeaderItem(2, priorytet);
    QStandardItem *message = new QStandardItem(tr("Treść"));
    mod->setHorizontalHeaderItem(3, message);
    setModel(mod);

}
}