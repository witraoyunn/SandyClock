#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
//    move(1920 - this->size().width() - 6, 1080 - this->size().height() - 55);
    ui->textBrowser->setAttribute(Qt::WA_TransparentForMouseEvents);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setShowTxt(const QString &str)
{
    ui->textBrowser->setText(str);
}

void Dialog::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        emit haspressed();
        close();
    }
}
