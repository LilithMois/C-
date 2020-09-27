#ifndef MINESCENE_H
#define MINESCENE_H

#include <QObject>
#include <QVector>
#include <QGraphicsScene>
#include <QLabel>
#include <QPoint>
#include <QTime>
#include <time.h>
#include <QCommonStyle>
#include "mineitem.h"

class MineScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MineScene(QObject *parent = nullptr);
    QVector< QVector< MineItem *> > m_itemVec;      //二维Vector容器
    int m_scenerow;                                 //当前场景的行数
    int m_scenecol;                                 //当前场景的列数
    int m_minesum;                                  //当前场景的雷数
    int m_Crrentleve;                               //当前场景的难度级别

    int m_signedMineNum;                            //右键标记的雷数
    int m_rightMineNum;                             //右键标记的正确的雷数
    int m_isGameOver;                               //游戏是否结束
    bool m_GameStart;                               //游戏开始
    int m_remainNoMines;                            //剩余非雷数
    bool m_soundOpen;                               //声音的开关
    void initscene();
    //    函数功能：初始化场景
    //    函数流程：
    void countAroundMines(MineItem *item);
    //    函数功能：布雷
    //    函数流程：
    void openAroundMines(MineItem *item);
    //    函数功能：对被打开的item计数处理
    //    函数流程：
    void openAllItems();
    //    函数功能：打开所有方块
    //    函数流程：
    void expendWater(MineItem *t_item);
    //    函数功能：方块扩散
    //    函数流程：

signals:
    void sig_succesPassGame(QString);
    //    函数功能：通关，转发name
    //    函数流程：
    void sig_scenenewGame();
    //    函数功能：新游戏
    //    函数流程：
    void sig_scenedisplayMineNum(int);
    //    函数功能：剩余雷数
    //    函数流程：

public slots:
};

#endif // MINESCENE_H
