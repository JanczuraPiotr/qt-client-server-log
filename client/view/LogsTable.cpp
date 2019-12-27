//
// Created by piotr@janczura.pl on 2019.12.24
//

#include "LogsTable.h"
#include <QStandardItem>
#include <QDebug>

namespace cl::view {

LogsTable::LogsTable(QWidget *parent)
    : QTableView(parent)
{
    initColumns();
}

void LogsTable::initColumns()
{
    // @task Tworzenie nagłówka przenieść do metody statycznej klasy LogsRecord - dla zachowania spójności między kolejnością nazw pól rekordu a kolejnością wartości pól rekordu
    model = new QStandardItemModel();
    QStandardItem *id = new QStandardItem(tr("ID"));
    model->setHorizontalHeaderItem(0, id);
    QStandardItem *time = new QStandardItem(tr("Czas"));
    model->setHorizontalHeaderItem(1, time);
    QStandardItem *priorytet = new QStandardItem(tr("Priorytet"));
    model->setHorizontalHeaderItem(2, priorytet);
    QStandardItem *message = new QStandardItem(tr("Treść"));
    model->setHorizontalHeaderItem(3, message);
    setModel(model);
}

void LogsTable::log(cl::model::LogRecord::ptr logRecord)
{
    // @task nowe logi dopisywane na pierwszym wierszu tabeli
    auto item = model->invisibleRootItem();
    item->appendRow(logRecord->textRow());
}


}