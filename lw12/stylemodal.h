#ifndef STYLEMODAL_H
#define STYLEMODAL_H

#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QColorDialog>
#include <QDebug>
//
class StyleModal : public QDialog {
    Q_OBJECT
public:
    StyleModal(QWidget *parent = 0, QStringList style = {});
    QStringList getData();
private:
    QLineEdit *comment;
    QLineEdit *quotation;
    QLineEdit *function;
    QLineEdit *keyword ;
    QLineEdit *directive;
    QPushButton *b1,
        *b2,
        *b3,
        *b4,
        *b5;
  private slots:
    void onOk();
    void changeColor();
    void onChange(QString);
};

#endif // STYLEMODAL_H
