#include "stylemodal.h"

StyleModal::StyleModal(QWidget *parent, QStringList style) : QDialog(parent) {
    QLabel *l1 = new QLabel(QString::fromUtf8("Комментрии: "));
    QLabel *l2 = new QLabel(QString::fromUtf8("Строки: "));
    QLabel *l3 = new QLabel(QString::fromUtf8("Функции: "));
    QLabel *l4 = new QLabel(QString::fromUtf8("Ключевые слова: "));
    QLabel *l5 = new QLabel(QString::fromUtf8("Директивы: "));
    comment = new QLineEdit;
    comment->setText(style.at(0));
    comment->setObjectName("1");
    connect(comment, SIGNAL(textChanged(QString)), this, SLOT(onChange(QString)));

    quotation = new QLineEdit;
    quotation->setText(style.at(1));
    quotation->setObjectName("2");
    connect(quotation, SIGNAL(textChanged(QString)), this, SLOT(onChange(QString)));

    function = new QLineEdit;
    function->setText(style.at(2));
    function->setObjectName("3");
    connect(function, SIGNAL(textChanged(QString)), this, SLOT(onChange(QString)));

    keyword = new QLineEdit;
    keyword->setText(style.at(3));
    keyword->setObjectName("4");
    connect(keyword, SIGNAL(textChanged(QString)), this, SLOT(onChange(QString)));

    directive = new QLineEdit;
    directive->setText(style.at(4));
    directive->setObjectName("5");
    connect(directive, SIGNAL(textChanged(QString)), this, SLOT(onChange(QString)));

    b1 = new QPushButton("");
    b1->setObjectName("1");
    b1->setStyleSheet(QString("background: %1; border: none;").arg(style.at(0)));
    connect(b1, SIGNAL(clicked()), this, SLOT(changeColor()));

    b2 = new QPushButton("");
    b2->setObjectName("2");
    b2->setStyleSheet(QString("background: %1; border: none;").arg(style.at(1)));
    connect(b2, SIGNAL(clicked()), this, SLOT(changeColor()));

    b3 = new QPushButton("");
    b3->setObjectName("3");
    b3->setStyleSheet(QString("background: %1; border: none;").arg(style.at(2)));
    connect(b3, SIGNAL(clicked()), this, SLOT(changeColor()));

    b4 = new QPushButton("");
    b4->setObjectName("4");
    b4->setStyleSheet(QString("background: %1; border: none;").arg(style.at(3)));
    connect(b4, SIGNAL(clicked()), this, SLOT(changeColor()));

    b5 = new QPushButton("");
    b5->setObjectName("5");
    b5->setStyleSheet(QString("background: %1; border: none;").arg(style.at(4)));
    connect(b5, SIGNAL(clicked()), this, SLOT(changeColor()));


    QGridLayout *lay = new QGridLayout;

    QPushButton *ok = new QPushButton(QString::fromUtf8("Принять"));
    QPushButton *cancel = new QPushButton(QString::fromUtf8("Отмена"));
    connect(ok, SIGNAL(clicked()), this, SLOT(onOk()));
    connect(cancel, SIGNAL(clicked()), this, SLOT(reject()));

    lay->addWidget(l1, 0, 0);
    lay->addWidget(comment, 0, 1);
    lay->addWidget(b1, 0, 2);
    lay->addWidget(l2, 1, 0);
    lay->addWidget(quotation, 1, 1);
    lay->addWidget(b2, 1, 2);
    lay->addWidget(l3, 2, 0);
    lay->addWidget(function, 2, 1);
    lay->addWidget(b3, 2, 2);
    lay->addWidget(l4, 3, 0);
    lay->addWidget(keyword, 3, 1);
    lay->addWidget(b4,3, 2);
    lay->addWidget(l5, 4, 0);
    lay->addWidget(directive, 4, 1);
    lay->addWidget(b5, 4, 2);
    lay->addWidget(ok, 5, 0);
    lay->addWidget(cancel, 5, 1);

    setLayout(lay);
}

void StyleModal::changeColor() {
    QColor color = QColorDialog::getColor();
    if (color.isValid()) {
        switch(QObject::sender()->objectName().toInt()) {
            case 1:
                comment->setText(color.name());
                b1->setStyleSheet(QString("background: %1; border: none;").arg(color.name()));
                break;
            case 2:
                quotation->setText(color.name());
                b2->setStyleSheet(QString("background: %1; border: none;").arg(color.name()));
                break;
            case 3:
                function->setText(color.name());
                b3->setStyleSheet(QString("background: %1; border: none;").arg(color.name()));
                break;
            case 4:
                keyword->setText(color.name());
                b4->setStyleSheet(QString("background: %1; border: none;").arg(color.name()));
                break;
            case 5:
                directive->setText(color.name());
                b5->setStyleSheet(QString("background: %1; border: none;").arg(color.name()));
                break;
        }
    }
}

void StyleModal::onOk() {
    QString t1 = comment->text(), t2 = quotation->text(), t3 = function->text(),
            t4 = keyword->text(), t5 = directive->text();
    QRegExp r("^#([A-Fa-f0-9]{6}|[A-Fa-f0-9]{3})$");
    if (!r.exactMatch(t1) || !r.exactMatch(t2) ||
            !r.exactMatch(t3) || !r.exactMatch(t4) || !r.exactMatch(t5) ) {
        QMessageBox::information(this, "Wrond data", "Must be in hex format");
        return;
    }
    emit accept();

}

void StyleModal::onChange(QString color) {
    QRegExp r("^#([A-Fa-f0-9]{6}|[A-Fa-f0-9]{3})$");
    if (r.exactMatch(color)) {
        switch(QObject::sender()->objectName().toInt()) {
            case 1:
                b1->setStyleSheet(QString("background: %1; border: none;").arg(color));
                break;
            case 2:
                b2->setStyleSheet(QString("background: %1; border: none;").arg(color));
                break;
            case 3:
                b3->setStyleSheet(QString("background: %1; border: none;").arg(color));
                break;
            case 4:
                b4->setStyleSheet(QString("background: %1; border: none;").arg(color));
                break;
            case 5:
                b5->setStyleSheet(QString("background: %1; border: none;").arg(color));
                break;
        }
    }
}

QStringList StyleModal::getData() {
    QStringList ret;
    ret << comment->text() << quotation->text() << function->text() <<
           keyword->text() << directive -> text();
    return ret;
}
