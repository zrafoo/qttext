#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QTextDocumentWriter>
#include <QFileDialog>
#include <QFontDialog>
#include <QColorDialog>
#include <QDebug>
#include <QStatusBar>
#include <QHBoxLayout>
#include <QSplitter>
#include <QTime>
#include <QToolBar>
#include <QToolButton>
#include <QDir>
#include <iostream>
#include <QDateTime>
#include <QSettings>
#include "highlighter.h"
#include "editarea.h"
#include "findmodal.h"
#include "findandreplacemodal.h"
#include "stylemodal.h"
#include "aboutmodal.h"

class Textedit : public QMainWindow
{
    Q_OBJECT
public:
    Textedit(QWidget *parent = 0);
    ~Textedit();
private:
    void setupFileActions();
    void setupEditActions();
    void setupTextActions();
    void setupViewActions();
    void setupHelpAction();
    void setupStatusBar();
    void loadStyles();
    void setCurrentFileName(const QString &);
    bool load(const QString& f);
    void ini();
    EditArea* textEdit;
    QString fileName;
    QToolBar *tb;
    QLabel* cursorPosition,
        *lastSaved,
        *lastChanged,
        *stringAmount,
        *wordAmount,
        *charAmount,
        *documentSize;

    QAction *saveAction,
    *undoAction,
    *redoAction,
    *cutAction,
    *copyAction,
    *pasteAction,
    *selectAllAction,
    *findAction,
    *findAndReplaceAction,
    *wordWrapAction,
    *stringNumberAction,
    *highlightStringAction,
    *statusBarAction,
    *toolBarAction,
    *syntaxHighlightAction;

    FindModal *m1;
    FindAndReplaceModal *m2;

    Highlighter *highlighter;

    QMenu *allStyles;
    QActionGroup  *ag1;

    QMap<QString, QStringList> stylesColors;
    QStringList currentStyle;
    QString currentStyleName;
    QString backgroundColor;
protected:
    void closeEvent(QCloseEvent * event);
private slots:
    void fileNew();
    bool fileSave();
    bool fileSaveAs();
    void fileOpen();
    bool maybeSave();
    void tryClose();
    void findText();
    void findAndReplaceText();
    void ChangeFonT();
    void toggleLineWrapMode(bool f);
    void changeBackground();
    void changeLineBackground();
    void cursorPosLabel();
    void lastSavedUpdate();
    void lastChangedUpdate();
    void toggleStatusBar(bool f);
    void updateSize();
    void updateStrings();
    void updateChars();
    void updateWords();
    void selectWord();
    void selectLine();
    void context(QContextMenuEvent *);
    void deleteText();
    void toggleToolBar(bool f);
    void findAccept();
    void findAndReplaceAccept();
    void toggleSyntaxHighlight(bool f);
    void changeStyle();
    void loadStyle();
    void setStyle();
    void about();
signals:

public slots:

};

#endif // TEXTEDIT_H
