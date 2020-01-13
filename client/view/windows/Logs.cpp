//
// Created by piotr@janczura.pl on 2020.01.03
//

#include "Logs.h"

#include <QDebug>
#include <QtWidgets/QGridLayout>

namespace cl::view::window {

Logs::Logs(const QString &title, const cm::Key &key, QWidget *parent)
    : QWidget(parent)
    , key(key)
    , logsTable(this)
{
    // @work powtórzenie
    const int MARGIN = 50;
    const int WIDTH = 400;
    setFixedSize(
            MARGIN +
            cl::view::table::Logs::COL_ID_HEIGHT +
            cl::view::table::Logs::COL_DATE_HEIGHT +
            cl::view::table::Logs::COL_PRIORITY_HEIGHT +
            cl::view::table::Logs::COL_MESSAGE_HEIGHT

            , WIDTH);
    // @work powtórzenie
    logsTable.setFixedSize(
            MARGIN +
            cl::view::table::Logs::COL_ID_HEIGHT +
            cl::view::table::Logs::COL_DATE_HEIGHT +
            cl::view::table::Logs::COL_PRIORITY_HEIGHT +
            cl::view::table::Logs::COL_MESSAGE_HEIGHT

            , WIDTH);

    setWindowTitle(title);

    QGridLayout *layout = new QGridLayout();


    layout->setColumnStretch(1, 1);
    layout->addWidget(&logsTable, 0, 0);
    layout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(layout);
}

Logs::~Logs()
{
    qDebug() << " destruktor okna :" << key;
}

void Logs::addLog(cl::model::LogRecord::ptr logRecord)
{
    logsTable.log(logRecord);
}

Logs::ptr Logs::create(const QString &title, const cm::Key &key, QWidget *parent)
{
    return ptr(new Logs(title, key, parent));
}

void Logs::closeEvent(QCloseEvent *event)
{
    event->accept();
    emit closedWindow(key);
}

}