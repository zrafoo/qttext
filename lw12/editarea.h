#ifndef EDITAREA_H
#define EDITAREA_H

#include <QPlainTextEdit>
#include <QPainter>
#include <QTextBlock>
#include <QDebug>
#include <QLabel>

class EditArea : public QPlainTextEdit {
    Q_OBJECT
public:
    EditArea(QWidget *parent = 0);
    void lineNumberAreaPaintEvent(QPaintEvent *);
    int lineNumberAreaWidth();
    void setLineBackground(QColor);
    QColor getLineColor();
    QString getCursorPosition();

protected:
    void resizeEvent(QResizeEvent *);
    void contextMenuEvent(QContextMenuEvent *event);

public slots:
    void toggleLineVisible(bool);

private slots:
    void updateLineNumberAreaWidth(int);
    void highlightCurrentLine();
    void updateLineNumberArea(const QRect &, int);
    void toggleNumbers(bool);
    void test();

private:
    QWidget* lineNumberArea;
    QColor lineColor;
    bool isLineAreaVisible;
    bool isLineVisible;

signals:
    void context(QContextMenuEvent*);
};

class LineNumberArea : public QWidget {
public:
    LineNumberArea(EditArea *_editArea = 0);
    QSize sizeHint() const;

protected:
    void paintEvent(QPaintEvent *);

private:
    EditArea *editArea;
};

#endif // EDITAREA_H
