#ifndef WINNER_H
#define WINNER_H

#include <QWidget>
#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>

class Winner : public QDialog
{
    Q_OBJECT
public:
    explicit Winner(QWidget *parent = nullptr);
    QPushButton *input_but;
    QLineEdit *name_line;
signals:
    void sig_sendname(QString);
    //    函数功能：发送姓名信号
    //    函数流程：
public slots:
    void slot_sendname();
    //    函数功能：连接but槽
    //    函数流程：
};

#endif // WINNER_H
