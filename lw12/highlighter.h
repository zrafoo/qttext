#ifndef HIGHLIGHTER_H
#define HIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QHash>
#include <QTextCharFormat>
#include <QDebug>

class QTextDocument;

class Highlighter : public QSyntaxHighlighter {
    Q_OBJECT
public:
    Highlighter(QTextDocument* parent = 0);
    void setIsVisible(bool f);
    void setStyle(QStringList &style);
protected:
    void highlightBlock(const QString &text);
private:
    bool isVisible;
    struct HighlightingRule {
        QRegExp pattern;
        QTextCharFormat *format;
    };
    QVector<HighlightingRule> highlightingRules;
    QRegExp commentStartExpression;
    QRegExp commentEndExpression;
    QTextCharFormat keywordFormat;
    QTextCharFormat PreprocDirectiveFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat functionFormat;
    void standart();
public slots:
    void c89();
    void cpp9803();
    void cpp1114();
    void cpp17();
    void cpp20();
};

#endif // HIGHLIGHTER_H
