#include "highlighter.h"

Highlighter::Highlighter(QTextDocument *parent) : QSyntaxHighlighter(parent) {
    QColor color;
    isVisible = true;

    color.setNamedColor("#0000ff");
    singleLineCommentFormat.setForeground(color);
    multiLineCommentFormat.setForeground(color);

    color.setNamedColor("#ff00ff");
    quotationFormat.setForeground(color);

    color.setNamedColor("#ff0000");
    functionFormat.setFontItalic(true);
    functionFormat.setForeground(color);

    color.setNamedColor("#338e5B");
    keywordFormat.setForeground(color);
    keywordFormat.setFontWeight(QFont::Bold);

    color.setNamedColor("#a020f0");
    PreprocDirectiveFormat.setForeground(color);

    commentStartExpression = QRegExp("/\\*");
    commentEndExpression = QRegExp("\\*/");

    c89();
}

void Highlighter::setIsVisible(bool f) {
    isVisible = f;
    rehighlight();
}

void Highlighter::standart() {

    HighlightingRule rule;

    rule.pattern = QRegExp("\\b[A-Za-z0-9_]+(?=\\()");
    rule.format = &functionFormat;
    highlightingRules.append(rule);

    rule.pattern = QRegExp("//[^\n]*");
    rule.format = &singleLineCommentFormat;
    highlightingRules.append(rule);

    rule.pattern = QRegExp("\".*\"");
    rule.format = &quotationFormat;
    highlightingRules.append(rule);

    rule.pattern = QRegExp("\'.*\'");
    rule.format = &quotationFormat;
    highlightingRules.append(rule);

    rule.pattern = QRegExp("<.*>");
    rule.format = &quotationFormat;
    highlightingRules.append(rule);
}

void Highlighter::setStyle(QStringList &style) {
    QColor color;
    color.setNamedColor(style.at(0));
    singleLineCommentFormat.setForeground(color);
    multiLineCommentFormat.setForeground(color);

    color.setNamedColor(style.at(1));
    quotationFormat.setForeground(color);

    color.setNamedColor(style.at(2));
    functionFormat.setForeground(color);

    color.setNamedColor(style.at(3));
    keywordFormat.setForeground(color);

    color.setNamedColor(style.at(4));
    PreprocDirectiveFormat.setForeground(color);

    rehighlight();
}

void Highlighter::c89() {
    highlightingRules.clear();
    HighlightingRule rule;
    QStringList keywordPatterns;
    keywordPatterns << "\\bauto\\b" << "\\bbreak\\b" << "\\bcase\\b"
                        << "\\bchar\\b" << "\\bconst\\b" << "\\bcontinue\\b"
                        << "\\bdefault\\b" << "\\bdo\\b" << "\\bdouble\\b"
                        << "\\belse\\b" << "\\benum\\b" << "\\bextern\\b"
                        << "\\bfloat\\b" << "\\bfor\\b" << "\\bgoto\\b"
                        << "\\bif\\b" << "\\bint\\b" << "\\blong\\b"
                        << "\\bregister\\b" << "\\breturn\\b" << "\\bshort\\b"
                        << "\\bsigned\\b" << "\\bsizeof\\b" << "\\bstatic\\b"
                        << "\\bstruct\\b" << "\\bswitch\\b" << "\\btypedef\\b"
                        << "\\bunion\\b" << "\\bvolatile\\b" << "\\bwhile\\b"
                        << "\\bunsigned\\b" << "\\bvoid\\b" << "\\bvolatile\\b";
    foreach (const QString &pattern, keywordPatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = &keywordFormat;
        highlightingRules.append(rule);
    }

    QStringList directivePatterns;
    directivePatterns << "#include" << "#define" << "#elif" <<
                         "#else" << "#endif" << "#error" <<
                         "#if" << "#ifdef" << "#ifndef" << "#line" <<
                         "#pragma" << "#undef" << "#using";
    foreach (const QString &pattern, directivePatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = &PreprocDirectiveFormat;
        highlightingRules.append(rule);
    }
    standart();
    rehighlight();
}
void Highlighter::cpp9803(){
    highlightingRules.clear();
    HighlightingRule rule;
    QStringList keywordPatterns;
    keywordPatterns << "\\bauto\\b" << "\\bbreak\\b" << "\\bcase\\b"
                    << "\\bchar\\b" << "\\bconst\\b" << "\\bcontinue\\b"
                    << "\\bdefault\\b" << "\\bdo\\b" << "\\bdouble\\b"
                    << "\\belse\\b" << "\\benum\\b" << "\\bextern\\b"
                    << "\\bfloat\\b" << "\\bfor\\b" << "\\bgoto\\b"
                    << "\\bif\\b" << "\\bint\\b" << "\\blong\\b"
                    << "\\bregister\\b" << "\\breturn\\b" << "\\bshort\\b"
                    << "\\bsigned\\b" << "\\bsizeof\\b" << "\\bstatic\\b"
                    << "\\bstruct\\b" << "\\bswitch\\b" << "\\btypedef\\b"
                    << "\\bunion\\b" << "\\bvolatile\\b" << "\\bwhile\\b"
                    << "\\bunsigned\\b" << "\\bvoid\\b" << "\\bvolatile\\b"
                    << "\\band\\b" << "\\band_eq\\b" << "\\basm\\b" <<
                       "\\bbitand\\b" << "\\bbitor\\b" << "\\bbool\\b" <<
                       "\\bcatcg\\b" << "\\bclass\\b" << "\\bcompl\\b" <<
                       "\\bconst_cast\\b" << "\\bdelete\\b" << "\\dynamic_cast\\b" <<
                       "\\bexplicit\\b" << "\\bexport\\b" << "\\bfalse\\b" <<
                       "\\bfriend\\b" << "\\bmutable\\b" << "\\bnamespace\\b"
   << "\\bnew\\b"  << "\\bnot\\b" << "\\bnot_eq\\b" << "\\bor\\b" << "\\bor_rq\\b" <<
                       "\\bprivate\\b" << "\\bprotected\\b" << "\\bpublic\\b" <<
                       "\\breinterpret_cast\\b" << "\\bstatic_cast\\b"  <<
                       "\\btemplate\\b" << "\\bthis\\b" << "\\bthrow\\b" <<
                       "\\btrue\\b" << "\\btry\\b" << "\\btypeid\\b" <<
                       "\\btypename\\b" << "\\busing\\b" << "\\bvirtual\\b" <<
                       "\\bwchar_t\\b" << "\\bxor\\b" << "\\bxor_eq\\b";

    foreach (const QString &pattern, keywordPatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = &keywordFormat;
        highlightingRules.append(rule);
    }
    QStringList directivePatterns;
    directivePatterns << "#include" << "#define" << "#elif" <<
                         "#else" << "#endif" << "#error" <<
                         "#if" << "#ifdef" << "#ifndef" << "#line" <<
                         "#pragma" << "#undef" << "#using";
    foreach (const QString &pattern, directivePatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = &PreprocDirectiveFormat;
        highlightingRules.append(rule);
    }
    standart();
    rehighlight();
}


void Highlighter::cpp1114() {
    highlightingRules.clear();
    HighlightingRule rule;
    QStringList keywordPatterns;
    keywordPatterns << "\\bauto\\b" << "\\bbreak\\b" << "\\bcase\\b"
                    << "\\bchar\\b" << "\\bconst\\b" << "\\bcontinue\\b"
                    << "\\bdefault\\b" << "\\bdo\\b" << "\\bdouble\\b"
                    << "\\belse\\b" << "\\benum\\b" << "\\bextern\\b"
                    << "\\bfloat\\b" << "\\bfor\\b" << "\\bgoto\\b"
                    << "\\bif\\b" << "\\bint\\b" << "\\blong\\b"
                    << "\\bregister\\b" << "\\breturn\\b" << "\\bshort\\b"
                    << "\\bsigned\\b" << "\\bsizeof\\b" << "\\bstatic\\b"
                    << "\\bstruct\\b" << "\\bswitch\\b" << "\\btypedef\\b"
                    << "\\bunion\\b" << "\\bvolatile\\b" << "\\bwhile\\b"
                    << "\\bunsigned\\b" << "\\bvoid\\b" << "\\bvolatile\\b"
                    << "\\band\\b" << "\\band_eq\\b" << "\\basm\\b" <<
                       "\\bbitand\\b" << "\\bbitor\\b" << "\\bbool\\b" <<
                       "\\bcatcg\\b" << "\\bclass\\b" << "\\bcompl\\b" <<
                       "\\bconst_cast\\b" << "\\bdelete\\b" << "\\dynamic_cast\\b" <<
                       "\\bexplicit\\b" << "\\bexport\\b" << "\\bfalse\\b" <<
                       "\\bfriend\\b" << "\\bmutable\\b" << "\\bnamespace\\b"
   << "\\bnew\\b"  << "\\bnot\\b" << "\\bnot_eq\\b" << "\\bor\\b" << "\\bor_rq\\b" <<
                       "\\bprivate\\b" << "\\bprotected\\b" << "\\bpublic\\b" <<
                       "\\breinterpret_cast\\b" << "\\bstatic_cast\\b"  <<
                       "\\btemplate\\b" << "\\bthis\\b" << "\\bthrow\\b" <<
                       "\\btrue\\b" << "\\btry\\b" << "\\btypeid\\b" <<
                       "\\btypename\\b" << "\\busing\\b" << "\\bvirtual\\b" <<
                       "\\bwchar_t\\b" << "\\bxor\\b" << "\\bxor_eq\\b"<<
                       "\\balignas\\b" << "\\balignof\\b" << "\\bchar16_t\\b" <<
                       "\\bchar32_t\\b" << "\\balignas\\b" << "\\bconstexpr\\b" <<
                       "\\bdecltype\\b" << "\\bnoexcept\\b" << "\\bnullptr\\b" <<
                       "\\bstatic_assert\\b" << "\\bthread_local\\b" << "\\bfinal\\b" <<
                       "\\boverride\\b";

    foreach (const QString &pattern, keywordPatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = &keywordFormat;
        highlightingRules.append(rule);
    }
    QStringList directivePatterns;
    directivePatterns << "#include" << "#define" << "#elif" <<
                         "#else" << "#endif" << "#error" <<
                         "#if" << "#ifdef" << "#ifndef" << "#line" <<
                         "#pragma" << "#undef" << "#using";
    foreach (const QString &pattern, directivePatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = &PreprocDirectiveFormat;
        highlightingRules.append(rule);
    }
    standart();
    rehighlight();
}

void Highlighter::cpp17() {
    highlightingRules.clear();
    HighlightingRule rule;
    QStringList keywordPatterns;
    keywordPatterns << "\\bauto\\b" << "\\bbreak\\b" << "\\bcase\\b"
                    << "\\bchar\\b" << "\\bconst\\b" << "\\bcontinue\\b"
                    << "\\bdefault\\b" << "\\bdo\\b" << "\\bdouble\\b"
                    << "\\belse\\b" << "\\benum\\b" << "\\bextern\\b"
                    << "\\bfloat\\b" << "\\bfor\\b" << "\\bgoto\\b"
                    << "\\bif\\b" << "\\bint\\b" << "\\blong\\b"
                    << "\\bregister\\b" << "\\breturn\\b" << "\\bshort\\b"
                    << "\\bsigned\\b" << "\\bsizeof\\b" << "\\bstatic\\b"
                    << "\\bstruct\\b" << "\\bswitch\\b" << "\\btypedef\\b"
                    << "\\bunion\\b" << "\\bvolatile\\b" << "\\bwhile\\b"
                    << "\\bunsigned\\b" << "\\bvoid\\b" << "\\bvolatile\\b"
                    << "\\band\\b" << "\\band_eq\\b" << "\\basm\\b" <<
                       "\\bbitand\\b" << "\\bbitor\\b" << "\\bbool\\b" <<
                       "\\bcatcg\\b" << "\\bclass\\b" << "\\bcompl\\b" <<
                       "\\bconst_cast\\b" << "\\bdelete\\b" << "\\dynamic_cast\\b" <<
                       "\\bexplicit\\b" << "\\bexport\\b" << "\\bfalse\\b" <<
                       "\\bfriend\\b" << "\\bmutable\\b" << "\\bnamespace\\b"
   << "\\bnew\\b"  << "\\bnot\\b" << "\\bnot_eq\\b" << "\\bor\\b" << "\\bor_rq\\b" <<
                       "\\bprivate\\b" << "\\bprotected\\b" << "\\bpublic\\b" <<
                       "\\breinterpret_cast\\b" << "\\bstatic_cast\\b"  <<
                       "\\btemplate\\b" << "\\bthis\\b" << "\\bthrow\\b" <<
                       "\\btrue\\b" << "\\btry\\b" << "\\btypeid\\b" <<
                       "\\btypename\\b" << "\\busing\\b" << "\\bvirtual\\b" <<
                       "\\bwchar_t\\b" << "\\bxor\\b" << "\\bxor_eq\\b"<<
                       "\\balignas\\b" << "\\balignof\\b" << "\\bchar16_t\\b" <<
                       "\\bchar32_t\\b" << "\\balignas\\b" << "\\bconstexpr\\b" <<
                       "\\bdecltype\\b" << "\\bnoexcept\\b" << "\\bnullptr\\b" <<
                       "\\bstatic_assert\\b" << "\\bthread_local\\b";

    foreach (const QString &pattern, keywordPatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = &keywordFormat;
        highlightingRules.append(rule);
    }
    QStringList directivePatterns;
    directivePatterns << "#include" << "#define" << "#elif" <<
                         "#else" << "#endif" << "#error" <<
                         "#if" << "#ifdef" << "#ifndef" << "#line" <<
                         "#pragma" << "#undef" << "#using";
    foreach (const QString &pattern, directivePatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = &PreprocDirectiveFormat;
        highlightingRules.append(rule);
    }
    standart();
    rehighlight();
}

void Highlighter::cpp20() {
    highlightingRules.clear();
    HighlightingRule rule;
    QStringList keywordPatterns;
    keywordPatterns << "\\bauto\\b" << "\\bbreak\\b" << "\\bcase\\b"
                    << "\\bchar\\b" << "\\bconst\\b" << "\\bcontinue\\b"
                    << "\\bdefault\\b" << "\\bdo\\b" << "\\bdouble\\b"
                    << "\\belse\\b" << "\\benum\\b" << "\\bextern\\b"
                    << "\\bfloat\\b" << "\\bfor\\b" << "\\bgoto\\b"
                    << "\\bif\\b" << "\\bint\\b" << "\\blong\\b"
                    << "\\bregister\\b" << "\\breturn\\b" << "\\bshort\\b"
                    << "\\bsigned\\b" << "\\bsizeof\\b" << "\\bstatic\\b"
                    << "\\bstruct\\b" << "\\bswitch\\b" << "\\btypedef\\b"
                    << "\\bunion\\b" << "\\bvolatile\\b" << "\\bwhile\\b"
                    << "\\bunsigned\\b" << "\\bvoid\\b" << "\\bvolatile\\b"
                    << "\\band\\b" << "\\band_eq\\b" << "\\basm\\b" <<
                       "\\bbitand\\b" << "\\bbitor\\b" << "\\bbool\\b" <<
                       "\\bcatcg\\b" << "\\bclass\\b" << "\\bcompl\\b" <<
                       "\\bconst_cast\\b" << "\\bdelete\\b" << "\\dynamic_cast\\b" <<
                       "\\bexplicit\\b" << "\\bexport\\b" << "\\bfalse\\b" <<
                       "\\bfriend\\b" << "\\bmutable\\b" << "\\bnamespace\\b"
   << "\\bnew\\b"  << "\\bnot\\b" << "\\bnot_eq\\b" << "\\bor\\b" << "\\bor_rq\\b" <<
                       "\\bprivate\\b" << "\\bprotected\\b" << "\\bpublic\\b" <<
                       "\\breinterpret_cast\\b" << "\\bstatic_cast\\b"  <<
                       "\\btemplate\\b" << "\\bthis\\b" << "\\bthrow\\b" <<
                       "\\btrue\\b" << "\\btry\\b" << "\\btypeid\\b" <<
                       "\\btypename\\b" << "\\busing\\b" << "\\bvirtual\\b" <<
                       "\\bwchar_t\\b" << "\\bxor\\b" << "\\bxor_eq\\b"<<
                       "\\balignas\\b" << "\\balignof\\b" << "\\bchar16_t\\b" <<
                       "\\bchar32_t\\b" << "\\balignas\\b" << "\\bconstexpr\\b" <<
                       "\\bdecltype\\b" << "\\bnoexcept\\b" << "\\bnullptr\\b" <<
                       "\\bstatic_assert\\b" << "\\bthread_local\\b" << "\\bchar8_t\\b" <<
                       "\\bconcept\\b" << "\\bconst_eval\\b" << "\\bconstinit\\b" <<
                       "\\bco_await\\b" << "\\bco_return\\b" << "\\bco_yeild\\b" <<
                       "\\brequires\\b" << "\\bthread_local\\b";

    foreach (const QString &pattern, keywordPatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = &keywordFormat;
        highlightingRules.append(rule);
    }
    QStringList directivePatterns;
    directivePatterns << "#include" << "#define" << "#elif" <<
                         "#else" << "#endif" << "#error" <<
                         "#if" << "#ifdef" << "#ifndef" << "#line" <<
                         "#pragma" << "#undef" << "#using" << "#export" <<
                         "#import" << "#module";
    foreach (const QString &pattern, directivePatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = &PreprocDirectiveFormat;
        highlightingRules.append(rule);
    }
    standart();
    rehighlight();
}

void Highlighter::highlightBlock(const QString &text) {
    if (!isVisible) {
        return;
    }
    foreach (const HighlightingRule &rule, highlightingRules) {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while (index >= 0) {
            int length = expression.matchedLength();
            setFormat(index, length, *rule.format);
            index = expression.indexIn(text, index + length);
        }
    }
    setCurrentBlockState(0);

    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = commentStartExpression.indexIn(text);

    while (startIndex >= 0) {
        int endIndex = commentEndExpression.indexIn(text, startIndex);
        int commentLength;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex
                            + commentEndExpression.matchedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = commentStartExpression.indexIn(text, startIndex + commentLength);
    }
}

