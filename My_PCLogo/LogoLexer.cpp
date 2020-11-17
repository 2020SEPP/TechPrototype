#include "LogoLexer.h"

LogoLexer::LogoLexer(QObject *parent) : QsciLexerCustom(parent)
{
//    this->setDefaultColor("#CF8D41");
	styleStack = QList<int>();
	resetStyle ();

	declareStyle(Default,
			QColor(0x0, 0x0, 0x0),
			QColor("white"),
			QFont("Liberation Mono", 10));
	declareStyle(CommentLine,
			QColor(0x0, 0x80, 0x0),
			QColor("white"),
			QFont("Liberation Mono", 10));
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
	QString source;
	int len;

	if (!this->editor())
		return;

	resetStyle();

	char *chars = new char[(end - start) + 1];
	this->editor()->SendScintilla(QsciScintilla::SCI_GETTEXTRANGE, start, end, chars);
	source = QString(chars);
	delete [] chars;

	len = end - start;

// 	qDebug() << "source =" << source;

	startStyling(start, 0x1f);
	setStyling(len, getStyle());
}

bool LogoLexer::pushStyle(int style)
{
	bool pushed = false;

	if (style >= getStyle()) {
		styleStack << style;
		pushed = true;
// 		qDebug() << __FUNCTION__ << description(style);
	}
	return pushed;
}

bool LogoLexer::popStyle()
{
	int style;
	bool popped = false;
	if (styleStack.size() > 1) {
		style = styleStack.takeLast() ;
		popped = true;
// 		qDebug() << __FUNCTION__ << description(style);
	}
	return popped;
}

int LogoLexer::getStyle()
{
	int style;
	style = styleStack.at(styleStack.size()-1) ;
	return style;
}

bool LogoLexer::hasStyle(int style)
{
	return styleStack.contains(style);
}

void LogoLexer::resetStyle()
{
	styleStack.clear();
	styleStack << Default;
}

