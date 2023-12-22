#include "aboutmodal.h"

AboutModal::AboutModal(QWidget *parent) : QDialog(parent) {
    QGridLayout *l = new QGridLayout();

    QLabel *name = new QLabel(QString::fromUtf8("Rostislav"));

    QLabel *photo = new QLabel(this);
    QPixmap pixmap(":images/phonk.png");
    photo->setPixmap(pixmap);

    QLabel *buildData = new QLabel(QString::fromUtf8("Дата сборки: ") + __DATE__ + " " __TIME__);
    QLabel *buildQtVersion = new QLabel(QString::fromUtf8("Версия qt при сборки: 4.8.7"));
    QLabel *execQtVersion = new QLabel(QString::fromUtf8("Версия qt при запуске: ") + qVersion());

    QPushButton *closeBtn = new QPushButton(QString::fromUtf8("Закрыть"));
    connect(closeBtn, SIGNAL(clicked()), this, SLOT(reject()));

    l->addWidget(name, 0, 0);
    l->addWidget(photo, 1, 0);
    l->addWidget(buildData, 2, 0);
    l->addWidget(buildQtVersion, 3, 0);
    l->addWidget(execQtVersion, 4, 0);
    l->addWidget(closeBtn, 5, 0);

    setLayout(l);
}
