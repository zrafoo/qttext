#ifndef FINDANDREPLACEMODAL_H
#define FINDANDREPLACEMODAL_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>

class FindAndReplaceModal : public QDialog
{
    Q_OBJECT
public:
    FindAndReplaceModal(QWidget *parent = 0);
    QString getFind() const;
    QString getReplace() const;
private:
    QLineEdit *le1;
    QLineEdit *le2;
signals:
    void ok();
};

#endif // FINDANDREPLACEMODAL_H
