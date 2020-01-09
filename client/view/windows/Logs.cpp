//
// Created by piotr@janczura.pl on 2020.01.03
//

#include "Logs.h"

#include <QDebug>

namespace cl::view::window {

Logs::Logs(const QString &title, const cm::Key &key, QWidget *parent)
    : QWidget(parent)
    , key(key)
    , logsTable()
{
    // @work tworzenie okna z przefiltrowanymi logami
    std::ignore = title;
    setWindowTitle(title);
    //setCentralWidget(&logsTable);
}

Logs::~Logs()
{
    qDebug() << " destruktor okna :" << key;
}

Logs::ptr Logs::create(const QString &title, const cm::Key &key, QWidget *parent)
{
    return ptr(new Logs(title, key, parent));
}

//void Logs::closeEvent(QCloseEvent *event)
//{
//    event->accept();
//    emit closedWindow(key);
//}

}