#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QDateTime>
#include <dialog.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_set_clicked();   //设置按钮点击事件的槽函数
    void slot_updateTime();             //定时器出发的槽函数，更新全局的当前时间变量

    void on_pushButton_close_clicked();

private:
    Ui::Widget *ui;
    QTimer qtimer;          //定时期
    QDateTime m_SetTime;    //设置的时间
    QDateTime m_NowTime;    //当前的时间
    QString m_strTips;
    Dialog m_pDialog;

};

#endif // WIDGET_H
