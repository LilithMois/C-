#include "mineitem.h"
#include "minescene.h"
#include "common.h"
#include "winner.h"
#include "mainwindow.h"

MineItem::MineItem(int x, int y, QPixmap pixmap, QGraphicsPixmapItem *parent) : QGraphicsPixmapItem(pixmap,parent),m_X(x),m_Y(y)
{
    m_isMine = 0;
    m_isOpened = 0;
    m_aroundMineNum = 0;
    m_rMouseKeyNum = 0;
    m_pinkMineNum = 0;
    m_isrightMouse = false;
    this->setPixmap(pixmap);
}
void MineItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    MineScene *minesence = (MineScene *)this->scene();
    minesence->m_GameStart = true;
    if(minesence->m_isGameOver)
    {
        minesence->m_GameStart = false;
        return;
    }
    else if(event->button() == Qt::RightButton)
    {
        if(m_isOpened)
            return;
        m_rMouseKeyNum++;
        if(1 == m_rMouseKeyNum)
        {

            minesence->m_signedMineNum++;
            this->setPixmap(QPixmap("://images/flag1.png"));
            emit sig_resetMineNum(minesence->m_signedMineNum);
            if(this->m_isMine)
            {
                minesence->m_rightMineNum++;
                m_pinkMineNum--;
                minesence->openAroundMines(this);
            }
        }
        else if(2 == m_rMouseKeyNum)
        {
            m_isrightMouse = true;
            this->setPixmap(QPixmap("://images/interrogation1_0.png"));
            minesence->m_signedMineNum--;
            emit sig_resetMineNum(minesence->m_signedMineNum);

            if(this->m_isMine)
                minesence->m_rightMineNum--;
        }
        else if(3 == m_rMouseKeyNum)
        {
            m_isrightMouse = false;
            this->setPixmap(QPixmap("://images/cover1.png"));
            m_rMouseKeyNum = 0;
            m_pinkMineNum++;
        }
    }

}
void MineItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

    MineScene *minesence = (MineScene *)this->scene();
        minesence->m_GameStart = true;
    if(minesence->m_isGameOver)
    {
        minesence->m_GameStart = false;
        return;
    }

    if(event->button() == Qt::LeftButton)
    {
        if(1 == this->m_rMouseKeyNum)
            return;

        if(m_isMine)
        {
            this->setPixmap(QPixmap("://images/CXK1.png"));
            m_isOpened = true;
            if(!minesence->m_soundOpen)
                QSound::play("://images/bong.wav");
            minesence->openAllItems();
            minesence->m_isGameOver = true;
            QMessageBox::information((QWidget*)minesence->parent(),tr("Game Over"),tr("Play again"),QMessageBox::Ok);
            emit this->sig_restartGame();
            return;
        }
        else
        {
            if(!m_aroundMineNum)
            {
                this->setPixmap(QPixmap("://images/mine0_0.png"));
                if(!m_isOpened)
                    minesence->m_remainNoMines--;
                m_isOpened = true;
                minesence->expendWater(this);
            }
            else
            {
                QString path = tr("://images/mine0_") + QString::number(m_aroundMineNum) + tr(".png");
                this->setPixmap(QPixmap(path));
                if(!m_isOpened)
                    minesence->m_remainNoMines--;
                m_isOpened = true;
            }
        }

        qDebug()<<"sta"<<minesence->m_remainNoMines<<endl;
        if(!minesence->m_remainNoMines)
        {
            minesence->m_isGameOver = true;
            if(!minesence->m_soundOpen)
                QSound::play("://images/win.wav");
            qDebug()<<"win"<<endl;
            Winner *win  = new Winner;
            win->exec();
            QString name = win->name_line->text();
            minesence->openAllItems();
            minesence->sig_succesPassGame(name);
            minesence->m_GameStart = false;
        }
    }
    m_lMouseKeyNum = 0;
    if(m_isOpened)
    {
        if(m_pinkMineNum <= 0)
        {
            if(event->button() == Qt::LeftButton)
            {
                m_lMouseKeyNum++;
                if(m_lMouseKeyNum == 1)
                {
                    minesence->expendWater(this);
                }
            }
        }
        m_lMouseKeyNum=0;
    }
}
