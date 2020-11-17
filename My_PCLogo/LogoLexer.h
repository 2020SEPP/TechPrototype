#ifndef MYLEXER_H
#define MYLEXER_H

#include <QString>
#include <QMap>
#include <QList>
#include "Qsci/qscilexercustom.h"
#include "Qsci/qscistyle.h"
#include "Qsci/qsciscintilla.h"

class LogoLexer : public QsciLexerCustom
{
public:
    enum {
        //! The default.
        Default = 0,

        //! A number.
        Number = 1,

        //! A string.
        Instruction = 2,

        //! A line comment.
        CommentLine = 3,

        //! A block comment.
        CommentBlock = 4,

        //! An operator.
        Operator = 5,

        //! A Logo keyword.
        Keyword = 6,

        //! A parsing error.
        Error = 7,
        };
public:
    LogoLexer(QObject *parent = nullptr);
    virtual ~LogoLexer() {}

public:
    const char *language() const;
    const char *lexer() const;
    const char *keywords(int) const;
    QString description(int) const;
    void styleText(int, int);

    bool pushStyle(int style);
    bool popStyle();
    int getStyle();
    bool hasStyle(int);
    void resetStyle();

private:
    QMap<int,QString> styleNames;
    #define declareStyle(style,color, paper, font) styleNames[style] = tr(#style); \
            setColor(color, style); \
            setPaper(paper, style); \
            setFont(font, style);
    QList<int> styleStack;

private:
    LogoLexer(const LogoLexer &);
    LogoLexer &operator=(const LogoLexer &);
};

#endif // MYLEXER_H
