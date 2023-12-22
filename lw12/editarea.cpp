#include "editarea.h"

EditArea::EditArea(QWidget *parent) : QPlainTextEdit(parent) {
    lineNumberArea = new LineNumberArea(this);
    lineColor = QColor(227, 227, 227);

    isLineAreaVisible = true;
    isLineVisible = true;

    connect(this, SIGNAL(blockCountChanged(int)), this, SLOT(updateLineNumberAreaWidth(int)));
    connect(this, SIGNAL(updateRequest(QRect,int)), this, SLOT(updateLineNumberArea(QRect,int)));
    connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(highlightCurrentLine()));
    connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(test()));

    updateLineNumberAreaWidth(0);
    highlightCurrentLine();
}

QColor EditArea::getLineColor() {
    return lineColor;
}

void EditArea::contextMenuEvent(QContextMenuEvent *event) {
    emit context(event);
}

void EditArea::test() {
}

QString EditArea::getCursorPosition() {
    auto cursor = textCursor();
    const QTextBlock block = cursor.block();
    return QString::number(block.blockNumber() + 1) + ":" +
            QString::number(cursor.positionInBlock() + 1);
}

void EditArea::lineNumberAreaPaintEvent(QPaintEvent *event) {
    QPainter painter(lineNumberArea);
    painter.fillRect(event->rect(), Qt::lightGray);


    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = (int) blockBoundingGeometry(block).translated(contentOffset()).top();
    int bottom = top + (int) blockBoundingRect(block).height();

    while (block.isValid() && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);
            painter.setPen(Qt::black);
            painter.drawText(0, top, lineNumberArea->width(), fontMetrics().height(),
                             Qt::AlignRight, number);
        }

        block = block.next();
        top = bottom;
        bottom = top + (int) blockBoundingRect(block).height();
        ++blockNumber;
    }
}

int EditArea::lineNumberAreaWidth() {
    int digits = 1;
    int max = qMax(1, blockCount());
    while (max >= 10) {
        max /= 10;
        ++digits;
    }

    int space = 3 + fontMetrics().width(QLatin1Char('9')) * digits;

    return space;
}

void EditArea::resizeEvent(QResizeEvent *e)
{
    QPlainTextEdit::resizeEvent(e);

    QRect cr = contentsRect();
    lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
}

void EditArea::updateLineNumberAreaWidth(int ) {
    if (!isLineAreaVisible) {
        setViewportMargins(0, 0, 0, 0);
        return;
    }
    setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
}

void EditArea::setLineBackground(QColor color) {
    lineColor = color;
    highlightCurrentLine();
}

void EditArea::toggleNumbers(bool f) {
    isLineAreaVisible = f;
    lineNumberArea->setHidden(!isLineAreaVisible);
    updateLineNumberAreaWidth(0);
}

void EditArea::toggleLineVisible(bool f) {
    isLineVisible = f;
    highlightCurrentLine();
}

void EditArea::updateLineNumberArea(const QRect &rect, int dy) {
    if (dy)
        lineNumberArea->scroll(0, dy);
    else
        lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());

    if (rect.contains(viewport()->rect()))
        updateLineNumberAreaWidth(0);
}

void EditArea::highlightCurrentLine() {
    QList<QTextEdit::ExtraSelection> extraSelections;

    if (!isReadOnly()) {
        QTextEdit::ExtraSelection selection;
        if (isLineVisible) {
            selection.format.setBackground(lineColor);
            selection.format.setProperty(QTextFormat::FullWidthSelection, true);
            selection.cursor = textCursor();
            selection.cursor.clearSelection();
        }
        extraSelections.append(selection);
    }

    setExtraSelections(extraSelections);
}




LineNumberArea::LineNumberArea(EditArea *_editArea) : QWidget(_editArea) {
    editArea = _editArea;
}

QSize LineNumberArea::sizeHint() const {
    return QSize(editArea->lineNumberAreaWidth(), 0);
}

void LineNumberArea::paintEvent(QPaintEvent *event) {
    editArea->lineNumberAreaPaintEvent(event);
}
