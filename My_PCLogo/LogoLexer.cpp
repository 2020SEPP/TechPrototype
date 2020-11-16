#include "LogoLexer.h"

LogoLexer::LogoLexer(QObject *parent) : QsciLexerCustom(parent)
{
    this->setDefaultColor("#CF8D41");
}

const char* LogoLexer::language() const
{
    return "Logo";
}

const char* LogoLexer::lexer() const
{
    return "logo";
}

const char* LogoLexer::keywords(int set) const
{
    if (set == 6)
    {
        return "fd bk rt lt"
               "pu pd"
               "setxy setpc setbg"
               "stampoval"
               "repeat";
    }

    return "";
}

QString LogoLexer::description(int style) const
{
    switch (style) {
    case Default:
        return tr("Default");
    case Number:
        return tr("Number");
    case Instruction:
        return tr("Instruction");
    case CommentLine:
        return tr("Command line");
    case CommentBlock:
        return tr("Comment block");
    case Operator:
        return tr("Operator");
    case Keyword:
        return tr("Keyword");
    case Error:
        return tr("Error");
    default:
        break;
    }

    return QString();
}

void LogoLexer::styleText(int start, int end)
{
    this->startStyling(start);

    end++;
    return;
}
