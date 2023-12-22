#include "textedit.h"

Textedit::Textedit(QWidget *parent) :
    QMainWindow(parent) {
    m1 = 0;
    m2 = 0;

    setToolButtonStyle(Qt::ToolButtonFollowStyle);
    textEdit = new EditArea(this);
    tb = new QToolBar(this);


    highlighter = new Highlighter(textEdit->document());

    addToolBar(tb);
    setupFileActions();
    setupEditActions();
    setupTextActions();
    setupViewActions();
    setupStatusBar();
    setupHelpAction();
    loadStyles();
    setCentralWidget(textEdit);
    textEdit->setFocus();


    QMenu *tbm = new QMenu;
    tbm->addAction(findAction);
    tbm->addAction(findAndReplaceAction);
    QToolButton *qtb = new QToolButton();
    qtb->setDefaultAction(findAction);
    qtb->setMenu(tbm);
    qtb->setPopupMode(QToolButton::MenuButtonPopup);
    connect(qtb, SIGNAL(triggered(QAction*)), qtb, SLOT(setDefaultAction(QAction*)));
    tb->addWidget(qtb);
    ini();

    connect(textEdit->document(), SIGNAL(modificationChanged(bool)),
            this, SLOT(setWindowModified(bool)));
    connect(textEdit->document(), SIGNAL(modificationChanged(bool)),
            saveAction, SLOT(setEnabled(bool)));
    connect(textEdit->document(), SIGNAL(undoAvailable(bool)),
            undoAction, SLOT(setEnabled(bool)));
    connect(textEdit->document(), SIGNAL(redoAvailable(bool)),
            redoAction, SLOT(setEnabled(bool)));
    connect(textEdit, SIGNAL(cursorPositionChanged()), this, SLOT(cursorPosLabel()));
    connect(textEdit, SIGNAL(textChanged()), this, SLOT(lastChangedUpdate()));
    connect(textEdit, SIGNAL(textChanged()), this, SLOT(updateStrings()));
    connect(textEdit, SIGNAL(textChanged()), this, SLOT(updateWords()));
    connect(textEdit, SIGNAL(textChanged()), this, SLOT(updateChars()));

    connect(textEdit, SIGNAL(context(QContextMenuEvent*)),
                             this, SLOT(context(QContextMenuEvent*)));

    setWindowModified(textEdit->document()->isModified());
    saveAction->setEnabled(textEdit->document()->isModified());
    undoAction->setEnabled(textEdit->document()->isUndoAvailable());
    redoAction->setEnabled(textEdit->document()->isRedoAvailable());

    connect(undoAction, SIGNAL(triggered()), textEdit, SLOT(undo()));
    connect(redoAction, SIGNAL(triggered()), textEdit, SLOT(redo()));



}

void Textedit::setupFileActions() {
    QMenu* menu = new QMenu(QString::fromUtf8("Файл"), this);
    menuBar()->addMenu(menu);

    QAction* a;


    a = new QAction(QIcon(":images/new-file.png"), QString::fromUtf8("Новый"), this);
    a->setPriority(QAction::LowPriority);
    a->setShortcut(QKeySequence::New);
    connect(a, SIGNAL(triggered()), this, SLOT(fileNew()));
    tb->addAction(a);
    menu->addAction(a);

    a = new QAction(QIcon(":images/open-file.png"), QString::fromUtf8("Открыть"), this);
    a->setShortcut(QKeySequence::Open);
    connect(a, SIGNAL(triggered()), this, SLOT(fileOpen()));
    tb->addAction(a);
    menu->addAction(a);

    saveAction = new QAction(QIcon(":images/save-file.png"), QString::fromUtf8("Сохранить"), this);
    saveAction->setShortcut(QKeySequence::Save);
    connect(saveAction, SIGNAL(triggered()), this, SLOT(fileSave()));
    saveAction->setEnabled(false);
    tb->addAction(saveAction);
    menu->addAction(saveAction);

    a = new QAction(QString::fromUtf8("Сохранить как"), this);
    a->setPriority(QAction::LowPriority);
    connect(a, SIGNAL(triggered()), this, SLOT(fileSaveAs()));
    menu->addAction(a);

    a = new QAction(QString::fromUtf8("Выход"), this);
    a->setShortcut(Qt::CTRL + Qt::Key_Q);
    connect(a, SIGNAL(triggered()), this, SLOT(tryClose()));
    menu->addAction(a);
}

void Textedit::setupViewActions() {
    QMenu* menu = new QMenu(QString::fromUtf8("Вид"), this);
    menuBar()->addMenu(menu);

    QAction* a;

    a = new QAction(QString::fromUtf8("Цвет фона"), this);
    connect(a, SIGNAL(triggered()), this, SLOT(changeBackground()));
    menu->addAction(a);

    a = new QAction(QString::fromUtf8("Цвет текущей строки"), this);
    connect(a, SIGNAL(triggered()), this, SLOT(changeLineBackground()));
    menu->addAction(a);

    stringNumberAction = new QAction(QString::fromUtf8("Нумерация строк"), this);
    stringNumberAction ->setCheckable(true);
    stringNumberAction ->setChecked(true);
    connect(stringNumberAction, SIGNAL(toggled(bool)), textEdit, SLOT(toggleNumbers(bool)));
    menu->addAction(stringNumberAction);

    highlightStringAction = new QAction(QString::fromUtf8("Подсветка строки"), this);
    highlightStringAction->setCheckable(true);
    highlightStringAction->setChecked(true);
    connect(highlightStringAction, SIGNAL(toggled(bool)), textEdit, SLOT(toggleLineVisible(bool)));
    menu->addAction(highlightStringAction);

    statusBarAction = new QAction(QString::fromUtf8("Cтрока состояния"), this);
    statusBarAction->setCheckable(true);
    statusBarAction->setChecked(true);
    connect(statusBarAction, SIGNAL(toggled(bool)), this, SLOT(toggleStatusBar(bool)));
    menu->addAction(statusBarAction);

    toolBarAction = new QAction(QString::fromUtf8("Панель иснтрументов"), this);
    toolBarAction->setCheckable(true);
    toolBarAction->setChecked(true);
    connect(toolBarAction, SIGNAL(toggled(bool)), this, SLOT(toggleToolBar(bool)));
    menu->addAction(toolBarAction);

    syntaxHighlightAction = new QAction(QString::fromUtf8("Подсветка синтаксиса"), this);
    syntaxHighlightAction->setCheckable(true);
    syntaxHighlightAction->setChecked(true);
    connect(syntaxHighlightAction, SIGNAL(toggled(bool)), this, SLOT(toggleSyntaxHighlight(bool)));
    menu->addAction(syntaxHighlightAction);


    QMenu *syntax = new QMenu(QString::fromUtf8("Переключить синтаксис"), menu);
    QActionGroup  *ag = new QActionGroup(syntax);

    a = new QAction(QString::fromUtf8("Cи89"), this);
    connect(a, SIGNAL(triggered()), highlighter, SLOT(c89()));
    ag->addAction(a);
    a->setCheckable(true);
    a->setChecked(true);

    a = new QAction(QString::fromUtf8("Cи++98/03"), this);
    connect(a, SIGNAL(triggered()), highlighter, SLOT(cpp9803()));
    ag->addAction(a);
    a->setCheckable(true);

    a = new QAction(QString::fromUtf8("Cи++11/14"), this);
    connect(a, SIGNAL(triggered()), highlighter, SLOT(cpp1114()));
    ag->addAction(a);
    a->setCheckable(true);

    a = new QAction(QString::fromUtf8("Cи++17"), this);
    connect(a, SIGNAL(triggered()), highlighter, SLOT(cpp17()));
    ag->addAction(a);
    a->setCheckable(true);

    a = new QAction(QString::fromUtf8("Cи++20"), this);
    connect(a, SIGNAL(triggered()), highlighter, SLOT(cpp20()));
    ag->addAction(a);
    a->setCheckable(true);

    ag->setExclusive(true);

    syntax->addActions(ag->actions());
    menu->addMenu(syntax);

    QMenu *styles = new QMenu(QString::fromUtf8("Изменить/выбрать стиль"), menu);

    a = new QAction(QString::fromUtf8("Изменить"), this);
    connect(a, SIGNAL(triggered()), this, SLOT(changeStyle()));
    styles->addAction(a);

    a = new QAction(QString::fromUtf8("Загрузить"), this);
    connect(a, SIGNAL(triggered()), this, SLOT(loadStyle()));
    styles->addAction(a);

    allStyles = new QMenu(QString::fromUtf8("Доступные стили"), styles);
    ag1 = new QActionGroup(allStyles);

    a = new QAction("Default", this);
    a->setObjectName("Default");
    stylesColors["Default"] = {"#0000ff", "#ff00ff", "#ff0000", "#338e5B", "#a020f0"};
    currentStyle = {"#0000ff", "#ff00ff", "#ff0000", "#338e5B", "#a020f0"};
    currentStyleName = "Default";
    connect(a, SIGNAL(triggered()), this, SLOT(setStyle()));
    a->setCheckable(true);
    a->setChecked(true);
    ag1->addAction(a);

    ag1->setExclusive(true);
    allStyles->addActions(ag1->actions());
    styles->addMenu(allStyles);
    menu->addMenu(styles);

}

void Textedit::setupStatusBar() {
    cursorPosition = new QLabel(" 1:1 ");
    lastSaved = new QLabel(QString::fromUtf8(" П. сохранение: "));
    lastChanged = new  QLabel(QString::fromUtf8(" П. изменение: "));
    stringAmount = new QLabel(QString::fromUtf8(" Строк: "));
    wordAmount = new QLabel(QString::fromUtf8(" Cлов: "));
    charAmount = new QLabel(QString::fromUtf8(" Символов: "));
    documentSize = new QLabel(QString::fromUtf8(" Размер: "));

    statusBar()->addWidget(cursorPosition);

    QSplitter * s1 = new QSplitter;
    QSplitter * s2 = new QSplitter;
    QSplitter * s3 = new QSplitter;

    QSplitter * s21 = new QSplitter;
    QSplitter * s22 = new QSplitter;
    s21->addWidget(lastSaved);
    s22->addWidget(lastChanged);

    s1->addWidget(cursorPosition);

    s2->addWidget(s21);
    s2->addWidget(s22);

    s3->addWidget(stringAmount);
    s3->addWidget(wordAmount);
    s3->addWidget(charAmount);
    s3->addWidget(documentSize);

    statusBar()->addWidget(s1);
    statusBar()->addWidget(s2);
    statusBar()->addWidget(s3);
}

void Textedit::changeStyle() {
    StyleModal *m = new StyleModal(this, currentStyle);
    if (m->exec() == QDialog::Accepted) {
        QStringList style = m->getData();
        if (currentStyleName == "Default") {
            currentStyleName = "Default" + QString::number(QDateTime::currentMSecsSinceEpoch());
            QAction *a;
            a = new QAction(currentStyleName, this);
            a->setCheckable(true);
            connect(a, SIGNAL(triggered()), this, SLOT(setStyle()));
            a->setObjectName(currentStyleName);
            ag1->addAction(a);
            allStyles->addActions(ag1->actions());
            a->setChecked(true);
    //        qDebug() << colors;
        }
        QString styleString = style.join(";");
        styleString += ";";
        currentStyle = style;
        highlighter->setStyle(currentStyle);
        stylesColors[currentStyleName] = style;
        QFile file("styles/" + currentStyleName + ".txt");
        file.open(QIODevice::WriteOnly);
        file.write(styleString.toLocal8Bit().constData());
        file.close();
    }
    delete m;
}

void Textedit::loadStyle() {
    QString fn = QFileDialog::getOpenFileName(this, tr("Open File..."),
                                              QString(), tr("txt (*.txt);;All Files (*)"));
    if (!fn.isEmpty()) {
        if (!QFile::exists(fn))
            return;
        QFile file(fn);
        if (!file.open(QFile::ReadOnly | QFile::Text)) {
            QMessageBox::warning(this, "warning", "Cannot open file" + file.errorString());
            return;
        }

        QByteArray data = file.readAll();
        QString str = QString::fromLocal8Bit(data);
        QStringList colors = str.split(QRegExp(";"), QString::SkipEmptyParts);
        colors = colors.filter(QRegExp("^#([A-Fa-f0-9]{6}|[A-Fa-f0-9]{3})$"));
        if (colors.length() != 5) {
            QMessageBox::warning(this, "warning", "wrong data");
            return;

        }
        QRegExp r("^#([A-Fa-f0-9]{6}|[A-Fa-f0-9]{3})$");
        for (int i = 0; i < colors.length(); i++) {
            if(!r.exactMatch(colors[i])) {
                QMessageBox::warning(this, "warning", "wrong data");
                return;
            }
        }

        QFileInfo fileInfo(file.fileName());
        QAction *a;
        a = new QAction(fileInfo.baseName(), this);
        a->setCheckable(true);
        connect(a, SIGNAL(triggered()), this, SLOT(setStyle()));
        a->setObjectName(fileInfo.baseName());

        ag1->addAction(a);
        allStyles->addActions(ag1->actions());

        a->setChecked(true);
        stylesColors[fileInfo.baseName()] = colors;
        currentStyle = colors;
        currentStyleName = fileInfo.baseName();
        highlighter->setStyle(colors);
    }
}

void Textedit::setStyle() {
    currentStyle = stylesColors[QObject::sender()->objectName()];
    currentStyleName = QObject::sender()->objectName();
    highlighter->setStyle(stylesColors[QObject::sender()->objectName()]);
}

void Textedit::toggleSyntaxHighlight(bool f) {
    highlighter->setIsVisible(f);
}

void Textedit::cursorPosLabel() {
    cursorPosition->setText(textEdit->getCursorPosition());
}


void Textedit::selectWord() {
    QTextCursor cursor = textEdit->textCursor();
    cursor.select(QTextCursor::WordUnderCursor);
    textEdit->setTextCursor(cursor);
}

void Textedit::selectLine() {
    QTextCursor cursor = textEdit->textCursor();
    cursor.movePosition(QTextCursor::StartOfBlock);
    cursor.movePosition(QTextCursor::EndOfBlock, QTextCursor::KeepAnchor);
    textEdit->setTextCursor(cursor);
}

void Textedit::context(QContextMenuEvent *event) {
    Q_UNUSED(event)
    QMenu *menu = new QMenu;
    menu->addAction(undoAction);
    menu->addAction(redoAction);

    QAction* a;

    if (!textEdit->textCursor().hasSelection()) {
        a = new QAction(QString::fromUtf8("Выделить слово"), this);
        connect(a, SIGNAL(triggered()), this, SLOT(selectWord()));
        menu->addAction(a);

        a = new QAction(QString::fromUtf8("Выделить строку"), this);
        connect(a, SIGNAL(triggered()), this, SLOT(selectLine()));
        menu->addAction(a);
    }

    if (textEdit->textCursor().hasSelection()) {
        menu->addAction(copyAction);
        menu->addAction(cutAction);

        a = new QAction(tr("&Delete"), this);
        connect(a, SIGNAL(triggered()), this, SLOT(deleteText()));
        menu->addAction(a);
    }
    menu->addAction(pasteAction);
    menu->addAction(selectAllAction);

    menu->popup(QCursor::pos());

}

void Textedit::loadStyles() {
    QDir *dir = new QDir("styles");
    dir->setFilter(QDir::Files | QDir::NoDot | QDir::NoDotDot);
    QFileInfoList list = dir->entryInfoList();
    for (int i = 0; i < list.size(); i++) {
        QFileInfo fileInfo = list.at(i);
        if(!(fileInfo.suffix() == "txt")) {
            continue;
        }
        QFile file(fileInfo.absoluteFilePath());
        if (!file.open(QFile::ReadOnly | QFile::Text)) {
            QMessageBox::warning(this, "warning", "Cannot open file" + file.errorString());
            continue;
        }

        QByteArray data = file.readAll();
        QString str = QString::fromLocal8Bit(data);
        QStringList colors = str.split(QRegExp(";"), QString::SkipEmptyParts);
        colors = colors.filter(QRegExp("^#([A-Fa-f0-9]{6}|[A-Fa-f0-9]{3})$"));

        QAction *a;
        a = new QAction(fileInfo.baseName(), this);
        a->setCheckable(true);
        connect(a, SIGNAL(triggered()), this, SLOT(setStyle()));
        a->setObjectName(fileInfo.baseName());
        ag1->addAction(a);
        allStyles->addActions(ag1->actions());

        stylesColors[fileInfo.baseName()] = colors;
    }
}

void Textedit::toggleStatusBar(bool f) {
    statusBar()->setVisible(f);
}

void Textedit::updateStrings() {
    stringAmount->setText(QString::fromUtf8(" Строк: ") + QString::number(textEdit->blockCount()) + " ");
}

void Textedit::updateChars() {
    charAmount->setText(QString::fromUtf8(" Символов: ") + QString::number(textEdit->toPlainText().length()) + " ") ;
}

void Textedit::updateWords() {
    wordAmount->setText(QString::fromUtf8(" Cлов: ") + QString::number(textEdit->toPlainText()
                          .split(QRegExp("(\\s|\\n|\\r)+"),
                                 QString::SkipEmptyParts).count()) + " ") ;
}

void Textedit::toggleToolBar(bool f) {
    tb->setVisible(f);
}

void Textedit::fileNew() {
    if (maybeSave()) {
        textEdit->clear();
        setCurrentFileName(QString());
        saveAction->setEnabled(false);
        lastSaved->setText(QString::fromUtf8(" П. сохранение: "));
        lastChanged->setText(QString::fromUtf8(" П. изменение: "));
        documentSize->setText(QString::fromUtf8(" Размер: "));
        wordAmount->setText(QString::fromUtf8(" Cлов: "));
        charAmount->setText(QString::fromUtf8(" Символов: "));
        stringAmount->setText(QString::fromUtf8(" Строк: "));
    }
}

void Textedit::fileOpen() {
    if(!maybeSave())
        return;
    QString fn = QFileDialog::getOpenFileName(this, tr("Open File..."),
                 QString(), tr("Header (*.h);; Source (*.c *.cpp);;Text files (*.txt);;All Files (*)"));
    if (!fn.isEmpty())
        load(fn);
}


bool Textedit::load(const QString &f)
{
    if (!QFile::exists(f))
        return false;
    QFile file(f);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "warning", "Cannot open file" + file.errorString());
        return false;
    }

    QByteArray data = file.readAll();
    textEdit->setPlainText(QString::fromLocal8Bit(data));

    lastSaved->setText(QString::fromUtf8(" П. сохранение: "));
    lastChanged->setText(QString::fromUtf8(" П. изменение: "));
    setCurrentFileName(f);
    updateSize();
    updateWords();
    updateChars();
    updateStrings();
    return true;
}

void Textedit::lastSavedUpdate() {
    QTime ct = QTime::currentTime();
    lastSaved->setText(QString::fromUtf8(" П. сохранение: ") + ct.toString(Qt::TextDate) + "   ");

}

void Textedit::lastChangedUpdate() {
    QTime ct = QTime::currentTime();
    lastChanged->setText(QString::fromUtf8(" П. изменение: ") + ct.toString(Qt::TextDate) + "   ");
}

bool Textedit::maybeSave() {
    if (!textEdit->document()->isModified())
        return true;

    QMessageBox::StandardButton ret;
    ret = QMessageBox::warning(this, tr("Application"),
                               QString::fromUtf8("Документ был модифицирован.\nСохранить изменения?"),
                               QMessageBox::Save | QMessageBox::Discard
                               | QMessageBox::Cancel);
    if (ret == QMessageBox::Save)
        return fileSave();
    else if (ret == QMessageBox::Cancel)
        return false;
    return true;
}

bool Textedit::fileSave() {
    if (fileName.isEmpty())
        return fileSaveAs();

    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    bool success = file.write(textEdit->toPlainText().toLocal8Bit().constData());
    file.close();
    if (success) {
        textEdit->document()->setModified(false);
        lastSavedUpdate();
        updateSize();
    }
    return success;
}

bool Textedit::fileSaveAs() {
    QString fn = QFileDialog::getSaveFileName(this, tr("Save as..."),

                      QString(), tr("Header (*.h);; Source (*.c *.cpp);;Text files (*.txt);;All Files (*)"));

    if (fn.isEmpty())
        return false;

    setCurrentFileName(fn);
    return fileSave();
}

void Textedit::updateSize() {
    QFileInfo file(fileName);
    documentSize-> setText(QString::fromUtf8(" Размер: ") + QString::number(file.size() / 1024.) + " kb ");
 }

void Textedit::deleteText() {
    textEdit->textCursor().removeSelectedText();
}

void Textedit::setCurrentFileName(const QString &fileName)
{
    this->fileName = fileName;
    textEdit->document()->setModified(false);

    QString shownName;
    if (fileName.isEmpty())
        shownName = "untitled.txt";
    else
        shownName = QFileInfo(fileName).fileName();

    if(shownName.size() > 32) {
        shownName.resize(32);
        shownName   += "...";
    }

    setWindowTitle(tr("%1[*]").arg(shownName));
    setWindowModified(false);
}

void Textedit::setupEditActions() {
    QMenu *menu = new QMenu(QString::fromUtf8("Правка") , this);
    menuBar()->addMenu(menu);

    undoAction = new QAction(QIcon(":images/undo.png"), QString::fromUtf8("Отменить"), this);
    undoAction->setShortcut(QKeySequence::Undo);
    tb->addAction(undoAction);
    menu->addAction(undoAction);

    redoAction = new QAction(QIcon(":images/redo.png"), QString::fromUtf8("Повторить"), this);
    redoAction->setPriority(QAction::LowPriority);
    redoAction->setShortcut(QKeySequence::Redo);
    tb->addAction(redoAction);
    menu->addAction(redoAction);

    cutAction = new QAction(QIcon(":images/cut.png"), QString::fromUtf8("Вырезать"), this);
    cutAction->setPriority(QAction::LowPriority);
    cutAction->setShortcut(QKeySequence::Cut);
    tb->addAction(cutAction);
    menu->addAction(cutAction);

    copyAction = new QAction(QIcon(":images/copy.png"), QString::fromUtf8("Копировать"), this);
    copyAction->setPriority(QAction::LowPriority);
    copyAction->setShortcut(QKeySequence::Copy);
    tb->addAction(copyAction);
    menu->addAction(copyAction);

    pasteAction = new QAction(QIcon(":images/paste.png"), QString::fromUtf8("Вставить"), this);

    pasteAction->setPriority(QAction::LowPriority);
    pasteAction->setShortcut(QKeySequence::Paste);
    tb->addAction(pasteAction);
    menu->addAction(pasteAction);

    selectAllAction = new QAction(QString::fromUtf8("Выделить все"), this);
    selectAllAction->setPriority(QAction::LowPriority);
    selectAllAction->setShortcut(QKeySequence::SelectAll);
    menu->addAction(selectAllAction);

    findAction = new QAction(QIcon(":images/find.png"), QString::fromUtf8("Найти"), this);
    menu->addAction(findAction);

    findAndReplaceAction = new QAction(QIcon(":images/replace.png"), QString::fromUtf8("Найти и заменить"), this);
    menu->addAction(findAndReplaceAction);

    cutAction->setEnabled(false);
    copyAction->setEnabled(false);

    connect(cutAction, SIGNAL(triggered()), textEdit, SLOT(cut()));
    connect(copyAction, SIGNAL(triggered()), textEdit, SLOT(copy()));
    connect(pasteAction, SIGNAL(triggered()), textEdit, SLOT(paste()));
    connect(selectAllAction, SIGNAL(triggered()), textEdit, SLOT(selectAll()));
    connect(findAction, SIGNAL(triggered()), this, SLOT(findText()));
    connect(findAndReplaceAction, SIGNAL(triggered()), this, SLOT(findAndReplaceText()));

    connect(textEdit, SIGNAL(copyAvailable(bool)), cutAction, SLOT(setEnabled(bool)));
    connect(textEdit, SIGNAL(copyAvailable(bool)), copyAction, SLOT(setEnabled(bool)));
}

void Textedit::setupHelpAction() {
    QMenu *menu = new QMenu(QString::fromUtf8("Справка"), this);
    menuBar()->addMenu(menu);

    QAction* a;
    a = new QAction(QString::fromUtf8("О программе"), this);
    connect(a, SIGNAL(triggered()), this, SLOT(about()));
    menu->addAction(a);
}

void Textedit::about() {
    AboutModal *d = new AboutModal(this);
    d->exec();
    delete d;
}

void Textedit::setupTextActions() {
    QMenu *menu = new QMenu(QString::fromUtf8("Формат"), this);
    menuBar()->addMenu(menu);

    QAction* a;

    wordWrapAction = new QAction(QString::fromUtf8("Перенос по словам"), this);
    wordWrapAction->setCheckable(true);
    wordWrapAction->setChecked(true);
    connect(wordWrapAction, SIGNAL(toggled(bool)), this, SLOT(toggleLineWrapMode(bool)));
    menu->addAction(wordWrapAction);

    a = new QAction(QString::fromUtf8("Выбор шрифта"), this);
    connect(a, SIGNAL(triggered()), this, SLOT(ChangeFonT()));
    menu->addAction(a);

}

void Textedit::ChangeFonT() {
    textEdit->setFont(QFontDialog::getFont(0, textEdit->font()));
}

void Textedit::findAndReplaceAccept() {
    if(!textEdit->find(m2->getFind())) {
        QMessageBox::information(this, "", QString::fromUtf8("Ничего не найдено или найлено последнее"));
        return;
    }
    QTextCursor cursor = textEdit->textCursor();
    textEdit->setTextCursor(cursor);

    cursor.insertText(m2->getReplace());
    cursor.movePosition(QTextCursor::PreviousCharacter, QTextCursor::KeepAnchor, m2->getReplace().size());
    textEdit->setTextCursor(cursor);
}

void Textedit::findAndReplaceText() {

    if (!m2) {
        m2 = new FindAndReplaceModal(this);
        connect(m2, SIGNAL(ok()), SLOT(findAndReplaceAccept()));
    }
    m2->show();
}

void Textedit::findText() {
    if (!m1) {
        m1 = new FindModal(this);
        connect(m1, SIGNAL(ok()), this, SLOT(findAccept()));
    }
    m1->show();
}

void Textedit::findAccept() {
    if(!textEdit->find(m1->getData())) {
        QMessageBox::information(this, "404", QString::fromUtf8("Ничего не найдено или найлено последнее"));
    }
}


void Textedit::toggleLineWrapMode(bool f) {
    textEdit->setLineWrapMode(f ? QPlainTextEdit::WidgetWidth : QPlainTextEdit::NoWrap);
}

void Textedit::changeBackground() {
    QColor color = QColorDialog::getColor();
    if (color.isValid()) {
        int r, g, b;
        color.getRgb(&r, &g, &b);
        backgroundColor = QString("background-color: rgb(%1, %2, %3);").arg(r).arg(g).arg(b);
        textEdit->setStyleSheet(
                    tr("background-color: rgb(%1, %2, %3);").arg(r).arg(g).arg(b));

    }
}

void Textedit::changeLineBackground() {
    QColor color = QColorDialog::getColor();
    if (color.isValid()) {
        textEdit->setLineBackground(color);
    }
}

void Textedit::closeEvent(QCloseEvent *event) {


    if(!maybeSave()) {
          event->ignore();
    }
}

void Textedit::tryClose() {
    close();
}

void Textedit::ini() {
    QSettings settings("lab12_lezhninq", QSettings::IniFormat);
    QString fileName = settings.value("fileName", QString()).toString();
    if (!QFile::exists(fileName))
        setCurrentFileName(QString());
    else
        load(fileName);

    bool wordWrap = settings.value("wordWrap", true).toBool(),
            stringNumber = settings.value("stringNumber", true).toBool(),
            highlightString = settings.value("highlightString", true).toBool(),
            statusBar = settings.value("statusBar", true).toBool(),
            toolBar = settings.value("toolBar", true).toBool(),
            syntaxHighlight = settings.value("syntaxHighlight", true).toBool();


    wordWrapAction->setChecked(wordWrap);
    stringNumberAction->setChecked(stringNumber);
    highlightStringAction->setChecked(highlightString);
    statusBarAction->setChecked(statusBar);
    toolBarAction->setChecked(toolBar);
    syntaxHighlightAction->setChecked(syntaxHighlight);

    QString font = settings.value("font", "").toString();
    if (font != "") {
        QFont fontt;
        fontt.fromString(font);
        textEdit->setFont(fontt);
    }

    QString lineColor = settings.value("currentLineColor", "#e3e3e3").toString();
    QColor color;
    color.setNamedColor(lineColor);
    textEdit->setLineBackground(color);

    QString bgColor = settings.value("bgcolor", "background-color: rgb(255, 255, 255);").toString();
    textEdit->setStyleSheet(bgColor);

    int cursorPosit = settings.value("cursorPosition", 0).toInt();
    QTextCursor cursor = textEdit->textCursor();
    if (cursorPosit > textEdit->toPlainText().length()) {
        cursorPosit = textEdit->toPlainText().length();
    }
    cursor.setPosition(cursorPosit);
    textEdit->setTextCursor(cursor);
}

Textedit::~Textedit() {
    QSettings settings("lab12_lezhninq", QSettings::IniFormat);
    settings.setValue("fileName", fileName);
    settings.setValue("wordWrap", wordWrapAction->isChecked());
    settings.setValue("stringNumber", stringNumberAction->isChecked());
    settings.setValue("highlightString", highlightStringAction->isChecked());
    settings.setValue("statusBar", statusBarAction->isChecked());
    settings.setValue("toolBar", toolBarAction->isChecked());
    settings.setValue("syntaxHighlight", syntaxHighlightAction->isChecked());
    settings.setValue ("font", textEdit->font().toString());
    settings.setValue("bgcolor", backgroundColor);
    settings.setValue("currentLineColor", textEdit->getLineColor().name());
    settings.setValue("cursorPosition", textEdit->textCursor().position());
}



