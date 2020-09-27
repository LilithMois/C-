#include "minescene.h"
#include "common.h"
#include "mainwindow.h"
#include "winner.h"

QPoint t_around[8]=
{
    QPoint(-1,-1),
    QPoint(-1,0),
    QPoint(-1,1),
    QPoint(0,-1),
    QPoint(0,1),
    QPoint(1,-1),
    QPoint(1,0),
    QPoint(1,1)
};

MineScene::MineScene(QObject *parent) : QGraphicsScene(parent)
{
    this->m_isGameOver = false;
    m_signedMineNum = 0;
    m_rightMineNum = 0;
    m_soundOpen = true;
}
void MineScene::initscene()
{
    this->m_remainNoMines = m_scenerow * m_scenecol - m_minesum;
    qDebug()<<"all offmine"<<m_remainNoMines<<endl;

    for(int i = 0; i < m_scenerow; i++)
    {
        QVector<MineItem *> t_vec;
        for(int j = 0;j < m_scenecol; j++)
        {
            MineItem *t_item = new MineItem(i,j,QPixmap("://images/cover1.png"));
            t_item->setPos(j * Common::MAPWIDYH,i * Common::MAPHEIGHT);
            this->addItem(t_item);
            t_vec.append(t_item);
        }
        this->m_itemVec.append(t_vec);
    }


    srand(time(NULL));
    for(int i = 0; i < m_minesum; i++)
    {
        int t_rows = rand()%m_scenerow;
        int t_cols = rand()%m_scenecol;
        if(!this->m_itemVec[t_rows][t_cols]->m_isMine)
        {
            this->m_itemVec[t_rows][t_cols]->m_isMine = true;
            this->countAroundMines(this->m_itemVec[t_rows][t_cols]);
        }
        else
            i--;
    }
    for(int i = 0;i < m_scenerow; i++)
    {
        for(int j = 0;j < m_scenecol; j++)
        {
            this->connect(this->m_itemVec[i][j],SIGNAL(sig_restartGame()),this,SIGNAL(sig_scenenewGame()));
            this->connect(this->m_itemVec[i][j],SIGNAL(sig_resetMineNum(int)),this,SIGNAL(sig_scenedisplayMineNum(int)));//连接LED显示雷数
        }
    }
}


void MineScene::countAroundMines(MineItem *item)//布雷
{
    if(NULL == item || !item->m_isMine)
        return;
    for(int i = 0;i < 8; i++)
    {
        int t_x = item->m_X + t_around[i].x();
        int t_y = item->m_Y + t_around[i].y();

        if(t_x < 0 || t_x >= this->m_scenerow || t_y < 0 || t_y >= this->m_scenecol)
            continue;
        if(m_itemVec[t_x][t_y]->m_isMine)
            continue;
        m_itemVec[t_x][t_y]->m_aroundMineNum++;
        m_itemVec[t_x][t_y]->m_pinkMineNum++;
    }
}

void MineScene::openAllItems()
{
    if(this->m_isGameOver)
        return;
    for(int i = 0;i < m_scenerow;i++)
    {
        for(int j = 0;j < m_scenecol; j++)
        {
            m_itemVec[i][j]->m_isOpened = true;
            if(m_itemVec[i][j]->m_isMine)
                m_itemVec[i][j]->setPixmap(QPixmap("://images/CXK1.png"));
            else
            {
                QString path = tr("://images/mine0_") + QString::number(m_itemVec[i][j]->m_aroundMineNum) + tr(".png");
                m_itemVec[i][j]->setPixmap(path);
            }
        }
    }

}


void MineScene::expendWater(MineItem *item)
{
    if(NULL == item || item->m_isMine)
        return;

    for(int i = 0; i < 8;i++)
    {
        int t_x = item->m_X + t_around[i].x();
        int t_y = item->m_Y + t_around[i].y();

        if(t_x < 0 || t_x >= m_scenerow || t_y < 0 || t_y >= m_scenecol)
            continue;

        else if(m_itemVec[t_x][t_y]->m_isMine || m_itemVec[t_x][t_y]->m_isOpened)
            continue;
        else if(m_itemVec[t_x][t_y]->m_rMouseKeyNum > 0)
            continue;

        m_itemVec[t_x][t_y]->m_isOpened = true;
        this->m_remainNoMines--;

        int itemnum = m_itemVec[t_x][t_y]->m_aroundMineNum;

        if(0 == itemnum)
        {
            expendWater(m_itemVec[t_x][t_y]);
        }

        QString path = tr("://images/mine0_") + QString::number(m_itemVec[t_x][t_y]->m_aroundMineNum) + tr(".png");
        m_itemVec[t_x][t_y]->setPixmap(QPixmap(path));
    }

    if(0 == m_remainNoMines)
    {
        m_isGameOver = true;
        if(!m_soundOpen)
            QSound::play("://images/win.wav");
        //qDebug()<<"win"<<endl;
        Winner *win  = new Winner;
        win->exec();
        QString name = win->name_line->text();
        this->openAllItems();
        emit sig_succesPassGame(name);
    }
}
void MineScene::openAroundMines(MineItem *item)
{
    if(m_isGameOver == true || !item->m_isMine)
        return;
    for(int i = 0; i < 8;i++)
    {
        int t_x = item->m_X + t_around[i].x();
        int t_y = item->m_Y + t_around[i].y();
        if(t_x < 0 || t_x >= m_scenerow || t_y < 0 || t_y >= m_scenecol)
            continue;
        m_itemVec[t_x][t_y]->m_pinkMineNum--;
        qDebug()<<m_itemVec[t_x][t_y]->m_pinkMineNum<<endl;
    }
}
