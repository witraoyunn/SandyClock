#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMouseEvent>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void setShowTxt(const QString &str);

private:
    Ui::Dialog *ui;
    void mousePressEvent(QMouseEvent *event);

signals:
    void haspressed();
};

#endif // DIALOG_H
