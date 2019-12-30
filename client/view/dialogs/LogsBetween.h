//
// Created by piotr@janczura.pl on 2019.12.30
//

#ifndef QT_CLIENT_SERVER_LOG_LOGSBETWEEN_H
#define QT_CLIENT_SERVER_LOG_LOGSBETWEEN_H

#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>


namespace cl::view::dialog {

class LogsBetween : public QDialog{
Q_OBJECT
public:
    explicit LogsBetween(QWidget *parent = nullptr);

private: // methods
    void layout();

private: // attributes
    QLabel info;
    QPushButton okButton;
    QPushButton cancelButton;

};
}


#endif //QT_CLIENT_SERVER_LOG_LOGSBETWEEN_H
