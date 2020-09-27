#include "rankdialog.h"

Rankdialog::Rankdialog(QWidget *parent) : QDialog(parent)
{
    lowrecordtimelabel = new QLabel;
    lowrecordnamelabel = new QLabel;
    midrecordnamelabel = new QLabel;
    midrecordtimelabel = new QLabel;
    highrecordnamelabel = new QLabel;
    highrecordtimelabel = new QLabel;

    QLabel *low_label = new QLabel(tr("Low level"));
    QLabel *mid_label = new QLabel(tr("Mid level"));
    QLabel *high_label = new QLabel(tr("High level"));
    QLabel *name1_label = new QLabel(tr("Player:"));
    QLabel *time1_label = new QLabel(tr("Time:"));
    QLabel *name2_label = new QLabel(tr("Player:"));
    QLabel *time2_label = new QLabel(tr("Time:"));
    QLabel *name3_label = new QLabel(tr("Player:"));
    QLabel *time3_label = new QLabel(tr("Time:"));

    QHBoxLayout *lowtit = new QHBoxLayout;
    lowtit->addStretch();
    lowtit->addWidget(low_label);
    lowtit->addStretch();

    QHBoxLayout *midtit = new QHBoxLayout;
    midtit->addStretch();
    midtit->addWidget(mid_label);
    midtit->addStretch();

    QHBoxLayout *hightit = new QHBoxLayout;
    hightit->addStretch();
    hightit->addWidget(high_label);
    hightit->addStretch();


    QGridLayout *rank_layout = new QGridLayout(this);
    rank_layout->addLayout(lowtit,0,0,1,2);
    rank_layout->addWidget(name1_label,1,0);
    rank_layout->addWidget(time1_label,2,0);
    rank_layout->addWidget(lowrecordnamelabel,1,1);
    rank_layout->addWidget(lowrecordtimelabel,2,1);

    rank_layout->addLayout(midtit,3,0,1,2);
    rank_layout->addWidget(name2_label,4,0);
    rank_layout->addWidget(time2_label,5,0);
    rank_layout->addWidget(midrecordnamelabel,4,1);
    rank_layout->addWidget(midrecordtimelabel,5,1);


    rank_layout->addLayout(hightit,6,0,1,2);
    rank_layout->addWidget(name3_label,7,0);
    rank_layout->addWidget(time3_label,8,0);
    rank_layout->addWidget(highrecordnamelabel,7,1);
    rank_layout->addWidget(highrecordtimelabel,8,1);

    QPushButton *close_rank = new QPushButton(tr("Close"));
    QPushButton *reset_rank = new QPushButton(tr("Reset"));
    this->connect(reset_rank,SIGNAL(clicked(bool)),this,SLOT(slot_reset()));
    this->connect(close_rank,SIGNAL(clicked(bool)),this,SLOT(close()));

    rank_layout->addWidget(reset_rank,9,0);
    rank_layout->addWidget(close_rank,9,1);

    readsettings();
}
void Rankdialog::slot_reset()
{
    lowrecordtimelabel->setText(tr("NULL"));
    lowrecordnamelabel->setText(tr("NULL"));
    midrecordnamelabel->setText(tr("NULL"));
    midrecordtimelabel->setText(tr("NULL"));
    highrecordnamelabel->setText(tr("NULL"));
    highrecordtimelabel->setText(tr("NULL"));
    //init_rankrecord();
}
void Rankdialog::init_rankrecord()
{
    QSettings *setting = new QSettings(tr("MineGame"),tr("mine"),this);
    setting->beginGroup(tr("Rank"));
    setting->setValue(tr("Rank_lowname"),NULL);
    setting->setValue(tr("Rank_lowtime"),NULL);
    setting->setValue(tr("Rank_midname"),NULL);
    setting->setValue(tr("Rank_midtime"),NULL);
    setting->setValue(tr("Rank_highname"),NULL);
    setting->setValue(tr("Rank_hightime"),NULL);
    setting->endGroup();
}
void Rankdialog::readsettings()
{
    QSettings *setting = new QSettings(tr("MineGame"),tr("mine"),this);
    setting->beginGroup(tr("Rank"));
    QString ran_ln = setting->value(tr("Rank_lowname"),NULL).toString();
    QString ran_lt = setting->value(tr("Rank_lowtime"),NULL).toString();
    QString ran_mn = setting->value(tr("Rank_midname"),NULL).toString();
    QString ran_mt = setting->value(tr("Rank_midtime"),NULL).toString();
    QString ran_hn = setting->value(tr("Rank_highname"),NULL).toString();
    QString ran_ht = setting->value(tr("Rank_hightime"),NULL).toString();
    setting->endGroup();
    if(ran_hn == 0 || ran_ln == 0 || ran_hn == 0)
        init_rankrecord();

    lowrecordtimelabel->setText(ran_lt);
    lowrecordnamelabel->setText(ran_ln);
    midrecordnamelabel->setText(ran_mn);
    midrecordtimelabel->setText(ran_mt);
    highrecordnamelabel->setText(ran_hn);
    highrecordtimelabel->setText(ran_ht);
}
