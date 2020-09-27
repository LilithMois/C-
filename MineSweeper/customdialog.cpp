#include "customdialog.h"

Customdialog::Customdialog(QWidget *parent) : QDialog(parent)
{
    this->setWindowTitle(tr("CustomGame"));
    Rowbox = new QSpinBox;
    colsbox = new QSpinBox;
    minenumbox = new QSpinBox;

    Rowbox->setRange(10,50);
    colsbox->setRange(10,50);
    minenumbox->setRange(10,99);

    Rowbox->setSingleStep(1);
    colsbox->setSingleStep(1);
    minenumbox->setSingleStep(1);

    Rowbox->setValue(10);
    colsbox->setValue(10);
    minenumbox->setValue(10);

    QLabel *row_label = new QLabel(tr("Row:"));
    QLabel *clos_label = new QLabel(tr("Column:"));
    QLabel *mine_label = new QLabel(tr("Mines:"));

    QPushButton *ok_but = new QPushButton(tr("Ok"));
    QPushButton *cancel_but = new QPushButton(tr("Cancel"));

    QGridLayout *custom_layout = new QGridLayout(this);
    custom_layout->addWidget(row_label,0,0);
    custom_layout->addWidget(clos_label,1,0);
    custom_layout->addWidget(mine_label,2,0);
    custom_layout->addWidget(Rowbox,0,1);
    custom_layout->addWidget(colsbox,1,1);
    custom_layout->addWidget(minenumbox,2,1);
    custom_layout->addWidget(ok_but,3,0);
    custom_layout->addWidget(cancel_but,3,1);

    this->connect(ok_but,SIGNAL(clicked(bool)),this,SLOT(slot_accpetok()));
    this->connect(cancel_but,SIGNAL(clicked(bool)),this,SLOT(close()));
}
void Customdialog::writesettings()
{
    //int box_r = Rowbox->value();
    QSettings *setting = new QSettings(tr("MineGame"),tr("mine"),this);
    setting->beginGroup(tr("custom"));
    setting->setValue(tr("custom_row"),Rowbox->value());
    setting->setValue(tr("custom_col"),colsbox->value());
    setting->setValue(tr("custom_mine"),minenumbox->value());
    setting->endGroup();
}
void Customdialog::readsettings()
{
    QSettings *setting = new QSettings(tr("MineGame"),tr("mine"),this);
    setting->beginGroup(tr("custom"));
    int box_r = setting->value(tr("custom_row"),10).toInt();
    int box_c = setting->value(tr("custom_col"),10).toInt();
    int box_m = setting->value(tr("custom_mine"),10).toInt();
    setting->endGroup();
    Rowbox->setValue(box_r);
    colsbox->setValue(box_c);
    minenumbox->setValue(box_m);
}
void Customdialog::slot_accpetok()
{
    int row = Rowbox->value();
    int col = colsbox->value();
    int mine = minenumbox->value();

    emit this->signal_sendCustomset(row,col,mine);
    this->writesettings();
    this->close();
}
