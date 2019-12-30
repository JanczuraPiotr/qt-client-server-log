//
// Created by piotr@janczura.pl on 2019.12.30
//

#ifndef QT_CLIENT_SERVER_LOG_LOGSBEFORE_H
#define QT_CLIENT_SERVER_LOG_LOGSBEFORE_H

#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

namespace cl::view::dialog {

class LogsBefore : public QDialog {
Q_OBJECT
public:
    explicit LogsBefore(QWidget *parent = nullptr);

private: // methods
    void layout();

private: // attributes
    QLabel info;
    QPushButton okButton;
    QPushButton cancelButton;
};
}


#endif //QT_CLIENT_SERVER_LOG_LOGSBEFORE_H
