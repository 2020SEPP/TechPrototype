#include "searchbar.h"
#include <QtDebug>
#include <QKeyEvent>

Searchbar::Searchbar(QWidget *p, int w, int h) {
    this->setParent(p);
    QHBoxLayout *mainLayout = new QHBoxLayout;
    searchBtn = new QPushButton;
    cancelBtn = new QPushButton;
    searchBtn->setFixedSize(w, h);
    searchBtn->setCursor(Qt::PointingHandCursor);
    searchBtn->setStyleSheet("QPushButton{border-image:url(:/images/image/f2.png);"
                             "background:transparent;cursor:pointer;}");
    cancelBtn->setFixedSize(w, h);
    cancelBtn->setCursor(Qt::PointingHandCursor);
    cancelBtn->setStyleSheet("QPushButton{border-image:url(:/images/image/error.png);"
                             "background:transparent;cursor:pointer;}");
    setPlaceholderText(tr("搜索"));
    mainLayout->addWidget(searchBtn);
    mainLayout->addStretch();
    mainLayout->addWidget(cancelBtn);
    mainLayout->setContentsMargins(w / 3, 0, w / 3, 0);
    setTextMargins(80, 0, 0, 0);
    QFont font;
    font.setPixelSize(25);
    setFont(font);
    setLayout(mainLayout);
    setStyleSheet("height:" + QString::number(h - 10) +
                  "px;border:none solid #eaeaea;");
    this->setAttribute(Qt::WA_MacShowFocusRect, 0);
    connect(searchBtn, SIGNAL(clicked()), this, SLOT(buttonclicked()));
    connect(cancelBtn, SIGNAL(clicked()), this, SLOT(cancelclicked()));
    cancelBtn->hide();
}

void Searchbar::buttonclicked() {
    searching = true;
    cancelBtn->show();
    QString name = this->text();
    emit Search(name);
}

void Searchbar::cancelclicked() {
    searching = false;
    cancelBtn->hide();
    this->setText("");
    emit Search("");
}

void Searchbar::keyPressEvent(QKeyEvent *ev) {
    if (ev->key() == Qt::Key_Return) {
        searching = true;
        cancelBtn->show();
        QString name = this->text();
        emit Search(name);
        return;
    }
    QLineEdit::keyPressEvent(ev);
}
