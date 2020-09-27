#ifndef RANKDIALOG_H
#define RANKDIALOG_H

#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSettings>

class Rankdialog : public QDialog
{
    Q_OBJECT
public:
    explicit Rankdialog(QWidget *parent = nullptr);
    QLabel *lowrecordtimelabel;
    QLabel *midrecordtimelabel;
    QLabel *highrecordtimelabel;
    QLabel *lowrecordnamelabel;
    QLabel *midrecordnamelabel;
    QLabel *highrecordnamelabel;

    void readsettings();
    //    函数功能：读取排行榜
    //    函数流程：
    void init_rankrecord();
    //    函数功能：排行榜初始化
    //    函数流程：
signals:

public slots:
    void slot_reset();
    //    函数功能：重置排行榜
    //    函数流程：
};

#endif // RANKDIALOG_H
