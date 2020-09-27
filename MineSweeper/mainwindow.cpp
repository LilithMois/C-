#include "mainwindow.h"
#include "winner.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),central(0),mineView(0),minescene(0),mine_lcd(0),time_lcd(0),smile_but(0),m_timer(0)
{
    this->setWindowTitle(tr("MineSweeper"));
    this->setWindowIcon(QPixmap("://images/icon.png"));
    //this->setWindowFlags(Qt::WindowCloseButtonHint);

    this->create_action();
    this->create_menu();
    this->slot_new();

}
void MainWindow::create_action()
{
    newaction = new QAction(tr("New game"));//新游戏
    connect(newaction,SIGNAL(triggered()),this,SLOT(slot_new()));

    lowaction = new QAction(tr("Low level"),this);//低级
    lowaction->setCheckable(true);
    lowaction->setChecked(true);

    midaction = new QAction(tr("Middle level"),this);//中级
    midaction->setCheckable(true);

    highaction = new QAction(tr("High level"),this);//高级
    highaction->setCheckable(true);

    customaction = new QAction(tr("Customize"),this);//自定义
    customaction->setCheckable(true);

    rankaction = new QAction(tr("Rank"));//排行榜
    connect(rankaction,SIGNAL(triggered(bool)),this,SLOT(slot_rank()));

    soundaction = new QAction(tr("Sound"));//音效
    connect(soundaction,SIGNAL(triggered(bool)),this,SLOT(slot_sound()));
    soundaction->setCheckable(true);

    exitaction = new QAction(tr("Exit"));//退出
    connect(exitaction,SIGNAL(triggered()),this,SLOT(close()));

    aboutaction = new QAction(tr("About"));//关于
    connect(aboutaction,SIGNAL(triggered()),this,SLOT(slot_about()));


    QActionGroup *level_group = new QActionGroup(this);
    level_group->addAction(lowaction);
    level_group->addAction(midaction);
    level_group->addAction(highaction);
    level_group->addAction(customaction);
    this->connect(level_group,SIGNAL(triggered(QAction *)),this,SLOT(slot_level(QAction *)));
}
void MainWindow::create_menu()
{
    QMenuBar *main_menu = new QMenuBar();
    this->setMenuBar(main_menu);
    QMenu *game_menu = new QMenu(tr("Game"));
    QMenu *about_menu = new QMenu(tr("About"));

    main_menu->addMenu(game_menu);
    main_menu->addMenu(about_menu);

    game_menu->addAction(newaction);
    game_menu->addSeparator();

    game_menu->addAction(lowaction);
    game_menu->addAction(midaction);
    game_menu->addAction(highaction);
    game_menu->addAction(customaction);
    game_menu->addSeparator();

    game_menu->addAction(rankaction);
    game_menu->addAction(soundaction);
    game_menu->addSeparator();

    game_menu->addAction(exitaction);
    about_menu->addAction(aboutaction);
}
void MainWindow::readsettings()
{
    QSettings settings(tr("MineSweeper"),tr("Setting"));
    settings.beginGroup(tr("All set"));
    minescene->m_Crrentleve = settings.value(tr("level"),Common::LOWLEVE).toInt();
    minescene->m_scenerow = settings.value(tr("rownum"),Common::LOWROWANDCOL).toInt();
    minescene->m_scenecol = settings.value(tr("colnum"),Common::LOWROWANDCOL).toInt();
    minescene->m_minesum = settings.value(tr("minesum"),Common::LOWMINENUM).toInt();
    settings.endGroup();
}
void MainWindow::writesettings()
{
    QSettings settings(tr("MineSweeper"),tr("Setting"));
    settings.beginGroup(tr("All set"));
    settings.setValue(tr("level"),minescene->m_Crrentleve);
    settings.setValue(tr("rownum"),minescene->m_scenerow);
    settings.setValue(tr("colnum"),minescene->m_scenecol);
    settings.setValue(tr("minesum"),minescene->m_minesum);
    settings.endGroup();
}
void MainWindow::slot_new()
{
    central->deleteLater();
    mineView->deleteLater();
    minescene->deleteLater();
    mine_lcd->deleteLater();
    time_lcd->deleteLater();
    smile_but->deleteLater();
    m_timer->deleteLater();

    central = new QWidget(this);//主程序界面

    mine_lcd = new QLCDNumber;
    mine_lcd->setDigitCount(3);
    mine_lcd->display("000");

    mine_lcd->setSegmentStyle(QLCDNumber::Flat);
    QPalette mine_pa = mine_lcd->palette();
    mine_pa.setColor(QPalette::Dark,Qt::red);//内边框
    mine_pa.setColor(QPalette::Light,Qt::red);//外边框
    mine_pa.setColor(QPalette::WindowText,Qt::red);
    mine_lcd->setPalette(mine_pa);
    mine_lcd->setStyleSheet("background-color: black");//背景颜色

    time_lcd = new QLCDNumber;
    time_lcd->setDigitCount(3);
    time_lcd->setSegmentStyle(QLCDNumber::Flat);

    QPalette time_pa = time_lcd->palette();
    time_pa.setColor(QPalette::Dark,Qt::red);//内边框
    time_pa.setColor(QPalette::Light,Qt::red);//外边框
    time_pa.setColor(QPalette::WindowText,Qt::red);
    time_lcd->setPalette(time_pa);
    time_lcd->setStyleSheet("background-color: black");//背景颜色

    smile_but = new QPushButton(QIcon(QPixmap("://images/center1.png")),NULL);
    this->connect(smile_but,SIGNAL(clicked(bool)),this,SLOT(slot_new()));

    QHBoxLayout *status_layout = new QHBoxLayout();
    status_layout->addStretch();
    status_layout->addWidget(mine_lcd);
    status_layout->addStretch();
    status_layout->addWidget(smile_but);
    status_layout->addStretch();
    status_layout->addWidget(time_lcd);
    status_layout->addStretch();

    mineView = new QGraphicsView(central);
    minescene = new MineScene;
    mineView->setScene(minescene);
    this->readsettings();

    this->connect(minescene,SIGNAL(sig_scenenewGame()),this,SLOT(slot_new()));
    this->connect(minescene,SIGNAL(sig_succesPassGame(QString)),this,SLOT(slot_updaterank(QString)));
    this->connect(minescene,SIGNAL(sig_scenedisplayMineNum(int)),this,SLOT(slot_displayMineNum(int)));

    QVBoxLayout *main_layout = new QVBoxLayout(central);
    main_layout->addLayout(status_layout);
    main_layout->addWidget(mineView);
    this->setCentralWidget(central);

    minescene->setSceneRect(0,0,minescene->m_scenecol * Common::MAPWIDYH,minescene->m_scenerow * Common::MAPHEIGHT);
    mineView->setFixedSize(minescene->m_scenecol * Common::MAPWIDYH + 4,minescene->m_scenerow * Common::MAPHEIGHT + 4);
    this->setFixedSize(minescene->m_scenecol * Common::MAPWIDYH + 20,minescene->m_scenerow * Common::MAPHEIGHT + 80);

    if(minescene->m_Crrentleve == Common::LOWLEVE)
        lowaction->setChecked(true);
    else if(minescene->m_Crrentleve == Common::MIDDLELEVE)
        midaction->setChecked(true);
    else if(minescene->m_Crrentleve == Common::HEIGHTLEVE)
        highaction->setChecked(true);
    else if(minescene->m_Crrentleve == Common::CUSOMLEVE)
        customaction->setChecked(true);

    m_time = 0;
    mine_lcd->display(minescene->m_minesum);
    time_lcd->display(m_time);

    m_timer = new QTimer(this);
    if(minescene->m_GameStart == true)
        connect(m_timer,SIGNAL(timeout()),this,SLOT(slot_displayTime()));

    minescene->initscene();
    m_timer->start(1000);
}
void MainWindow::slot_level(QAction *level)
{
    if(level == lowaction)
    {
        minescene->m_Crrentleve = Common::LOWLEVE;
        minescene->m_scenerow = Common::LOWROWANDCOL;
        minescene->m_scenecol = Common::LOWROWANDCOL;
        minescene->m_minesum = Common::LOWMINENUM;
    }
    else if(level == midaction)
    {
        minescene->m_Crrentleve = Common::MIDDLELEVE;
        minescene->m_scenerow = Common::MIDDLEROWANDCOL;
        minescene->m_scenecol = Common::MIDDLEROWANDCOL;
        minescene->m_minesum  = Common::MIDDLEMINENUM;
    }
    else if(level == highaction)
    {
        minescene->m_Crrentleve = Common::HEIGHTLEVE;
        minescene->m_scenerow = Common::HEIGHTROW;
        minescene->m_scenecol = Common::HEIGHTCOL;
        minescene->m_minesum = Common::HEIGHTMINENUM;
    }
    else if(level == customaction)
    {
        Customdialog *custom = new Customdialog;
        this->connect(custom,SIGNAL(signal_sendCustomset(int,int,int)),this,SLOT(slot_cutsom(int,int,int)));
        custom->exec();
    }
    this->writesettings();
    this->slot_new();
}
void MainWindow::slot_cutsom(int row,int col,int mine)
{
    minescene->m_Crrentleve = Common::CUSOMLEVE;
    minescene->m_scenerow = row;
    minescene->m_scenecol = col;
    minescene->m_minesum = mine;
    this->writesettings();
}
void MainWindow::slot_sound()
{
    if(soundaction->isChecked())
    {
        minescene->m_soundOpen = Common::soundon;
    }
    else
    {
        minescene->m_soundOpen = Common::soundoff;
    }
}
void MainWindow::slot_rank()
{
    Rankdialog *rank = new Rankdialog(this);
    rank->exec();
}
void MainWindow::slot_about()
{
    QMessageBox::about(this,tr("About"),tr("Version:1.0")+"\n"+tr("Author: 张益铭"));
}
void MainWindow::slot_updaterank(QString name)
{
    //qDebug()<<name<<endl;
    QSettings *setting = new QSettings(tr("MineGame"),tr("mine"),this);
    setting->beginGroup(tr("Rank"));
    if(minescene->m_Crrentleve == Common::LOWLEVE)
    {
        setting->setValue(tr("Rank_lowname"),name);
        setting->setValue(tr("Rank_lowtime"),m_time);
    }
    else if(minescene->m_Crrentleve == Common::MIDDLELEVE)
    {
        setting->setValue(tr("Rank_midname"),name);
        setting->setValue(tr("Rank_midtime"),m_time);
    }
    else if(minescene->m_Crrentleve == Common::HEIGHTLEVE)
    {
        setting->setValue(tr("Rank_highname"),name);
        setting->setValue(tr("Rank_hightime"),m_time);
    }
    setting->endGroup();
}
void MainWindow::slot_displayMineNum(int flag)
{
    mine_lcd->display(minescene->m_minesum - flag);
}
void MainWindow::slot_displayTime()
{
    if(!minescene->m_isGameOver)
    {
        m_time++;
        time_lcd->display(m_time);
        if(!minescene->m_soundOpen)
            QSound::play("://images/time.wav");
    }
    else
    {
        m_timer->stop();
    }
}

MainWindow::~MainWindow()
{

}
