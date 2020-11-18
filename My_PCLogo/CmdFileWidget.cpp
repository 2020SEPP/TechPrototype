#include "CmdFileWidget.h"
#include <QDebug>
#include <QFileDevice>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

CmdFileWidget::CmdFileWidget(QWidget *parent) : QWidget(parent)
{
    WIN_W = window.getW();
    WIN_H = window.getH();

    canvas = new Canvas(this, 0, 0, WIN_W*2/3, WIN_H);
    canvas->setGeometry(0, 0, WIN_W*2/3, WIN_H);
    canvas->setStyleSheet("border: 2px solid darkgray; background-color: #ffffff");

    editor = new CodEditor(this);
    editor->setGeometry(WIN_W*2/3, WIN_H/18, WIN_W, WIN_H*17/18);

    import = new QPushButton(this);
    save = new QPushButton(this);
    run = new QPushButton(this);
    debug = new QPushButton(this);

    import->setText("导入");
    save->setText("保存");
    run->setText("运行");
    debug->setText("调试");

    import->setGeometry(WIN_W*37/54, 0, WIN_W*2/27, WIN_H/18);
    save->setGeometry(WIN_W*41/54, 0, WIN_W*2/27, WIN_H/18);
    run->setGeometry(WIN_W*45/54, 0, WIN_W*2/27, WIN_H/18);
    debug->setGeometry(WIN_W*49/54, 0, WIN_W*2/27, WIN_H/18);

    import->setStyleSheet("QPushButton{border-image: url(:/images/image/button.png);border-radius:2px;}");
    save->setStyleSheet("QPushButton{border-image: url(:/images/image/button.png);border-radius:2px;}");
    run->setStyleSheet("QPushButton{border-image: url(:/images/image/button.png);border-radius:2px;}");
    debug->setStyleSheet("QPushButton{border-image: url(:/images/image/button.png);border-radius:2px;}");

    import->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    save->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    run->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    debug->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

    import->setFlat(false);
    save->setFlat(false);
    run->setFlat(false);
    debug->setFlat(false);

    connect(import, SIGNAL(clicked()), this, SLOT(Import()));
    connect(save, SIGNAL(clicked()), this, SLOT(Save()));
    connect(run, SIGNAL(clicked()), this, SLOT(Run()));
    connect(debug, SIGNAL(clicked()), this, SLOT(Debug()));

    connect(editor, SIGNAL(Mark()), this, SLOT(MarkChanged()));
}

// SLOTS
void CmdFileWidget::Import()
{
    QString name = QFileDialog::getOpenFileName(this,tr("选择文件")," ",tr("LOGO(*.logo)"));
    QFile file(name);

    if (!file.open(QFile::ReadOnly))
    {
        QMessageBox::warning(this, tr("Application"), tr("导入文件 %1 失败 :\n%2.")
                             .arg(name)
                             .arg(file.errorString()));
        return;
    }

    Curr_file = name;

    QTextStream in(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    editor->setContent(in.readAll());
    QApplication::restoreOverrideCursor();

    file.close();
}

void CmdFileWidget::Save()
{
    if (Curr_file.isEmpty())
    {
        saveAs();
    } else
    {
        saveFile(Curr_file);
    }
}

bool CmdFileWidget::saveAs()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("选择保存文件路径"), tr("untitled.logo"));
    if (filename.isEmpty())
        return false;

    if (!filename.endsWith(".logo"))
        filename += ".logo";

    return saveFile(filename);
}

bool CmdFileWidget::saveFile(QString filename)
{
    QFile file(filename);
    if (!file.open(QFile::WriteOnly)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("保存文件 %1 失败:\n%2.")
                             .arg(filename)
                             .arg(file.errorString()));
        return false;
    }

    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << editor->getAllContent();
    QApplication::restoreOverrideCursor();

    Curr_file = filename;

    QMessageBox::warning(this, tr("Application"),
                         tr("保存文件 %1 成功.")
                         .arg(filename));
    return true;
}

void CmdFileWidget::Run()
{
    debug->setText("调试");
    QString content = editor->getAllContent();
//    qDebug() << content;

    canvas->reset();

    QStringList lines = content.split("\r\n");

    for (int i = 0; i < lines.size(); ++i)
    {
        QString line = lines.at(i);

        if (line.trimmed() == tr(""))
            continue;

        int index = line.indexOf("//");
        if (index >= 0)
            line = line.left(index);

        canvas->parse_line(line);
    }

    return;
}

void CmdFileWidget::Debug()
{
    points = editor->getPoints();
    debug->setText("继续");

    QString content = editor->getAllContent();

    int i = point;
    int last_point = point;

    if (point == -1)
    {
        i = 0;
        canvas->reset();
    }

    QStringList lines = content.split("\r\n");

    for (; i < lines.size(); ++i)
    {
        if (points.contains(i) && i != last_point)
        {
            point = i;
            break;
        }

        QString line = lines.at(i);

        if (line.trimmed() == tr(""))
            continue;

        int index = line.indexOf("//");
        if (index >= 0)
            line = line.left(index);

        canvas->parse_line(line);
    }

    if (points.indexOf(point) == points.size() - 1)
    {
        point = -1;
        debug->setText("调试");
    }

    return;
}

void CmdFileWidget::MarkChanged()
{
    points.clear();
    point = -1;
    debug->setText("调试");
}
