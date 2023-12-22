#ifndef FINDMODAL_H
#define FINDMODAL_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>

class FindModal : public QDialog {
Q_OBJECT
public:
    FindModal(QWidget *parent = 0);
    QString getData();
private:
    QLineEdit *le1;
signals:
    void ok();
};

#endif // FINDMODAL_H
