#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //去除窗口的框体和设置始终显示最前方
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
//    move(QPoint(1920,1080) - QPoint(this->width(), this->height()) - QPoint(8,50));
    //关联相应的槽函数
    connect(&qtimer, SIGNAL(timeout()), this, SLOT(slot_updateTime()));
    connect(&m_pDialog, SIGNAL(haspressed()), this, SLOT(show()));
    //启动定时器
    qtimer.start(1000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_set_clicked()
{
    m_SetTime = QDateTime::currentDateTime().addSecs(ui->lineEdit_sec->text().toUInt());
    m_strTips = ui->lineEdit_tip->text();
    ui->lineEdit_tip->clear();
    ui->lineEdit_sec->clear();
    hide();
}

void Widget::slot_updateTime()
{
    m_NowTime = QDateTime::currentDateTime();
    if(!m_SetTime.isValid())
    {
        return;
    }
    if(m_NowTime > m_SetTime)
    {
        qtimer.stop();
        m_pDialog.show();
        m_pDialog.setShowTxt(m_strTips);
        qDebug()<<"time over";
    }
}

void Widget::on_pushButton_close_clicked()
{
    close();
}
