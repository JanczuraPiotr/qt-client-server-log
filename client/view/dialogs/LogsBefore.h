//
// Created by piotr@janczura.pl on 2019.12.30
//

#ifndef CLIENT_DIALOG_LOGSBEFORE
#define CLIENT_DIALOG_LOGSBEFORE

#include <QtWidgets/QDialog>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

namespace cl::view::dialog {

class LogsBefore : public QDialog {
Q_OBJECT
public:
    explicit LogsBefore(QWidget *parent = nullptr);

    QString getBorderMoment();

private: // methods
    void layout();

private: // attributes
    QLabel labelMoment;
    QDateTimeEdit borderMoment;
    QPushButton okButton;
    QPushButton cancelButton;
};
}


#endif
