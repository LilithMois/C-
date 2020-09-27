#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>
#include <QLabel>
#include <QSound>
#include <QSettings>
#include <QString>
#include <QAction>
#include <QWidget>
#include <QGraphicsView>
#include <QInputDialog>
#include <QLCDNumber>
#include <QTimer>
#include <QColorDialog>
#include <QHBoxLayout>
#include <QTextStream>
#include <QMessageBox>
#include <QSpinBox>
#include "rankdialog.h"
#include "common.h"
#include "minescene.h"
#include "mineitem.h"
#include "customdialog.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QAction *newaction;//新游戏
    QAction *lowaction;//低级
    QAction *midaction;//中级
    QAction *highaction;//高级
    QAction *customaction;//自定义
    QAction *rankaction;//排行榜
    QAction *soundaction;//音效
    QAction *exitaction;//退出
    QAction *aboutaction;//关于

    QWidget *central;//主程序界面
    QGraphicsView *mineView;//主程序视图
    MineScene *minescene;//主程序场景
    QLCDNumber *mine_lcd;//LCD雷数
    QLCDNumber *time_lcd;//LCD时间
    QPushButton *smile_but;//笑脸

    int m_time;
    QTimer *m_timer;

    void create_action();
//    函数功能：创建行为
//    函数流程：
    void create_menu();
//    函数功能：创建窗口
//    函数流程：
    //创建主窗口，创建控件，创建子布局，创建总布局
    void readsettings();
//    函数功能：读取设置
//    函数流程：
    void writesettings();
//    函数功能：写入设置
//    函数流程：
public slots:
    void slot_new();
//    函数功能：新游戏
//    函数流程：
    void slot_level(QAction *);
//    函数功能：等级行为组
//    函数流程：
    void slot_cutsom(int,int,int);
//    函数功能：接收自定义数据
//    函数流程：
    void slot_sound();
//    函数功能：声音
//    函数流程：
    void slot_rank();
//    函数功能：排行榜
//    函数流程：
    void slot_about();
//    函数功能：关于
//    函数流程：
    void slot_updaterank(QString);
//    函数功能：更新排行榜
//    函数流程：
    void slot_displayMineNum(int);
//    函数功能：显示雷数
//    函数流程：
    void slot_displayTime();
//    函数功能：显示时间
//    函数流程：



};

#endif // MAINWINDOW_H
