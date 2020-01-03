//
// Created by piotr@janczura.pl on 2019.12.30
//

#ifndef CLIENT_DIALOG_LOGSAFTER_H
#define CLIENT_DIALOG_LOGSAFTER_H

#include <QtWidgets/QDialog>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>

namespace cl::view::dialog {

class LogsAfter : public QDialog {
    Q_OBJECT
public:
    explicit LogsAfter(QWidget *parent = nullptr);

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



#endif //CLIENT_DIALOG_LOGSAFTER_H
