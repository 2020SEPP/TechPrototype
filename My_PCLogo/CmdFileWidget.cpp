#include "CmdFileWidget.h"
#include <QDebug>
#include <QFileDevice>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QHBoxLayout>
CmdFileWidget::CmdFileWidget(QWidget *parent) : QWidget(parent) {
    WIN_W = window.getW();
    WIN_H = window.getH();
    QPixmap pixmap = QPixmap(":/images/image/paint2.png").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);
    this->setStyleSheet("QWidget{"
                        "border-image:url(:/images/image/paint2.png);"
                        "}");
    canvas = new Canvas(this, 0, 0, WIN_W * 2 / 3, WIN_H);
    canvas->setGeometry(0, 0, WIN_W * 2 / 3, WIN_H);
    canvas->setStyleSheet("border: 2px solid darkgray; background-color: #ffffff");
    editor = new CodEditor(this);
    editor->setStyleSheet("QWidget{"
                          "border-image:url(:/images/image/paint1.png);"
                          "}");
    editor->setGeometry(WIN_W * 2 / 3, WIN_H / 18, WIN_W, WIN_H * 17 / 18);
    import = new QPushButton(this);
    save = new QPushButton(this);
    run = new QPushButton(this);
    debug = new QPushButton(this);
    exit = new QPushButton(this);
    import->setText("导入");
    save->setText("保存");
    run->setText("运行");
    debug->setText("调试");
    exit->setText("退出");
    import->setGeometry(WIN_W * 10 / 15, 0, WIN_W / 15, WIN_H / 18);
    save->setGeometry(WIN_W * 11 / 15, 0, WIN_W / 15, WIN_H / 18);
    run->setGeometry(WIN_W * 12 / 15, 0, WIN_W / 15, WIN_H / 18);
    debug->setGeometry(WIN_W * 13 / 15, 0, WIN_W / 15, WIN_H / 18);
    exit->setGeometry(WIN_W * 14 / 15, 0, WIN_W / 15, WIN_H / 18);
    import->setIcon(QPixmap(":images/image/icon/file-import.png"));
    save->setIcon(QPixmap(":images/image/icon/file-save.png"));
    run->setIcon(QPixmap(":images/image/icon/run.png"));
    debug->setIcon(QPixmap(":images/image/icon/debug.png"));
    exit->setIcon(QPixmap(":images/image/icon/exit.png"));
    import->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    save->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    run->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    debug->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    exit->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
    connect(import, SIGNAL(clicked()), this, SLOT(Import()));
    connect(save, SIGNAL(clicked()), this, SLOT(Save()));
    connect(run, SIGNAL(clicked()), this, SLOT(Run()));
    connect(debug, SIGNAL(clicked()), this, SLOT(Debug()));
    connect(exit, SIGNAL(clicked()), this, SLOT(Exit()));
    connect(editor, SIGNAL(Mark()), this, SLOT(MarkChanged()));
}

// SLOTS
void CmdFileWidget::Import() {
    QString name = QFileDialog::getOpenFileName(this, tr("选择文件"), " ", tr("LOGO(*.logo)"));
    QFile file(name);
    if (!file.open(QFile::ReadOnly)) {
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

void CmdFileWidget::Save() {
    if (Curr_file.isEmpty()) {
        saveAs();
    } else {
        saveFile(Curr_file);
    }
}

bool CmdFileWidget::saveAs() {
    QString filename = QFileDialog::getSaveFileName(this, tr("选择保存文件路径"), tr("untitled.logo"));
    if (filename.isEmpty())
        return false;
    if (!filename.endsWith(".logo"))
        filename += ".logo";
    return saveFile(filename);
}

bool CmdFileWidget::saveFile(QString filename) {
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

void CmdFileWidget::Run() {
    debug->setText("调试");
    QString content = editor->getAllContent();
    canvas->reset();
    QStringList lines = content.split("\r\n");
    for (int i = 0; i < lines.size(); ++i) {
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

void CmdFileWidget::Debug() {
    points = editor->getPoints();
    debug->setText("继续");
    QString content = editor->getAllContent();
    int i = point;
    int last_point = point;
    if (point == -1) {
        i = 0;
        canvas->reset();
    }
    QStringList lines = content.split("\r\n");
    for (; i < lines.size(); ++i) {
        if (points.contains(i) && i != last_point) {
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
    if (points.indexOf(point) == points.size() - 1) {
        point = -1;
        debug->setText("调试");
    }
    return;
}

void CmdFileWidget::MarkChanged() {
    points.clear();
    point = -1;
    debug->setText("调试");
}

void CmdFileWidget::Exit() {
    emit CloseCmdFile(2);
}
