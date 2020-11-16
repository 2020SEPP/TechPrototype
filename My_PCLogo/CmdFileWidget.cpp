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
    editor->setGeometry(WIN_W*2/3, 0, WIN_W, WIN_H*5/6);

    import = new QPushButton(this);
    run = new QPushButton(this);

    import->setText("导入");
    run->setText("运行");

    import->setGeometry(WIN_W*19/27, WIN_H*16/18, WIN_W*3/27, WIN_H/18);
    run->setGeometry(WIN_W*23/27, WIN_H*16/18, WIN_W*3/27, WIN_H/18);


    connect(import, SIGNAL(clicked()), this, SLOT(Import()));
    connect(run, SIGNAL(clicked()), this, SLOT(Run()));
}

// SLOTS
void CmdFileWidget::Import()
{
    qDebug() << "import";

    QString name = QFileDialog::getOpenFileName(this,tr("选择文件")," ",tr("LOGO(*.logo)"));
    QFile file(name);

    if (!file.open(QFile::ReadOnly))
    {
        QMessageBox::warning(this, tr("Application"), tr("Cannot read file %1:\n%2.")
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

void CmdFileWidget::Run()
{
    qDebug() << "run";

    QString content = editor->getAllContent();

    qDebug() << content;

    canvas->reset();

    QStringList lines = content.split("\r\n");

    for (int i = 0; i < lines.size(); ++i)
    {
        QString line = lines.at(i);


        if (line != tr(""))
        {
            canvas->parse_line(line);
        }
    }

    return;
}
