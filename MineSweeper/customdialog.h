#ifndef CUSTOMDIALOG_H
#define CUSTOMDIALOG_H

#include <QWidget>
#include <QSpinBox>
#include <QLabel>
#include <QHBoxLayout>
#include <QString>
#include <QPushButton>
#include <QGridLayout>
#include <QDialog>
#include <QSettings>

class Customdialog : public QDialog
{
    Q_OBJECT
public:
    explicit Customdialog(QWidget *parent = nullptr);
    QSpinBox *Rowbox;
    QSpinBox *colsbox;
    QSpinBox *minenumbox;
    void readsettings();    //读自定义游戏设置文件
    void writesettings();   //写自定义游戏设置文件
signals:
    void signal_sendCustomset(int,int,int);
//    函数功能：发送自定义Dialog数据
//    函数流程：
public slots:
    void slot_accpetok();
//    函数功能：接收确定按钮信号
//    函数流程：
};

#endif // CUSTOMDIALOG_H
