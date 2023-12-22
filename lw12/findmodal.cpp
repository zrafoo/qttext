#include "findmodal.h"

FindModal::FindModal(QWidget *parent) : QDialog(parent) {
    QLabel *l1 = new QLabel(QString::fromUtf8("Найти: "));
    le1 = new QLineEdit;

    QGridLayout *lay = new QGridLayout;

    QPushButton *ok = new QPushButton(QString::fromUtf8("Принять"));
    QPushButton *cancel = new QPushButton(QString::fromUtf8("Отмена"));
    connect(ok, SIGNAL(clicked()), this, SIGNAL(ok()));
    connect(cancel, SIGNAL(clicked()), this, SLOT(reject()));

    lay->addWidget(l1, 0, 0);
    lay->addWidget(le1, 0, 1);
    lay->addWidget(ok, 1, 0);
    lay->addWidget(cancel, 1, 1);

    setLayout(lay);
}

QString FindModal::getData() {
    return le1->text();
}
