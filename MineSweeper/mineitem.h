#ifndef MINEITEM_H
#define MINEITEM_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPushButton>
#include <QGraphicsSceneMouseEvent>
#include <QMessageBox>
#include <QSound>
#include <QDebug>

class MineItem : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit MineItem(int x,int y,QPixmap pixmap,QGraphicsPixmapItem *parent = nullptr);
    int m_X;                //容器中的行数
    int m_Y;                //容器中的列数
    bool m_isMine;          //是否为雷
    bool m_isOpened;        //是否打开
    int m_aroundMineNum;    //周围雷数
    int m_pinkMineNum;      //标记雷数
    int m_rMouseKeyNum;     //鼠标右键点击次数
    int m_lMouseKeyNum;     //鼠标左键点击次数
    bool m_isrightMouse;    //鼠标左键是否点击

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    //    函数功能：鼠标右键点击事件
    //    函数流程：
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    //    函数功能：鼠标左键点击事件
    //    函数流程：
signals:
    void sig_restartGame();
    //    函数功能：重新开始游戏
    //    函数流程：
    void sig_resetMineNum(int t_signedMineNum);
    //    函数功能：雷数
    //    函数流程：

public slots:
};

#endif // MINEITEM_H
