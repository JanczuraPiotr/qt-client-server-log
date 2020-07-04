//
// Created by piotr@janczura.pl on 2019.12.24
//

#include "Logs.h"
#include <QDebug>

namespace cl::view {

cl::view::table::Logs::Logs(QWidget *parent)
    : QTableView(parent)
    , model(QStandardItemModel())
{
    initColumns();
}

void cl::view::table::Logs::initColumns()
{
    // @task Tworzenie nagłówka przenieść do metody statycznej klasy LogsRecord - dla zachowania spójności między kolejnością nazw pól rekordu a kolejnością wartości pól rekordu
//    data = new QStandardItemModel();
    QStandardItem *id = new QStandardItem(tr("ID"));
    model.setHorizontalHeaderItem(COL_ID_IX, id);
    QStandardItem *time = new QStandardItem(tr("Czas"));
    model.setHorizontalHeaderItem(COL_DATE_IX, time);
    QStandardItem *priorytet = new QStandardItem(tr("Priorytet"));
    model.setHorizontalHeaderItem(COL_PRIORITY_IX, priorytet);
    QStandardItem *message = new QStandardItem(tr("Treść"));
    model.setHorizontalHeaderItem(COL_MESSAGE_IX, message);
    setModel(&model);
    setColumnWidth(COL_ID_IX, COL_ID_HEIGHT);
    setColumnWidth(COL_DATE_IX, COL_DATE_HEIGHT);
    setColumnWidth(COL_PRIORITY_IX, COL_PRIORITY_HEIGHT);
    setColumnWidth(COL_MESSAGE_IX, COL_MESSAGE_HEIGHT);
}

void cl::view::table::Logs::log(cl::model::LogRecord::ptr logRecord)
{
    auto item = model.invisibleRootItem();
    item->insertRow(0, logRecord->textRow());
}


}