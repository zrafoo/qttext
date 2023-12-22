#include "findandreplacemodal.h"

FindAndReplaceModal::FindAndReplaceModal(QWidget *parent) : QDialog(parent) {
    QLabel *l1 = new QLabel(QString::fromUtf8("Найти: "));
    QLabel *l2 = new QLabel(QString::fromUtf8("Заменить на: "));
    le1 = new QLineEdit;
    le2 = new QLineEdit;

    QGridLayout *lay = new QGridLayout;

    QPushButton *ok = new QPushButton(QString::fromUtf8("Принять"));
    QPushButton *cancel = new QPushButton(QString::fromUtf8("Отмена"));
    connect(ok, SIGNAL(clicked()), this, SIGNAL(ok()));
    connect(cancel, SIGNAL(clicked()), this, SLOT(reject()));

    lay->addWidget(l1, 0, 0);
    lay->addWidget(le1, 0, 1);
    lay->addWidget(l2, 1, 0);
    lay->addWidget(le2, 1, 1);
    lay->addWidget(ok, 2, 0);
    lay->addWidget(cancel, 2, 1);

    setLayout(lay);
}

QString FindAndReplaceModal::getFind() const {
    return le1->text();
}

QString FindAndReplaceModal::getReplace() const {
    return le2->text();
}
