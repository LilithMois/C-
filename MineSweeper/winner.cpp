#include "winner.h"
#include "mainwindow.h"
Winner::Winner(QWidget *parent) : QDialog(parent)
{
    this->setWindowTitle(tr("You win"));
    QGridLayout *win_layout = new QGridLayout(this);
    input_but = new QPushButton(tr("Submit"));
    name_line = new QLineEdit(tr("Input your name"));
    QLabel *name_label = new QLabel(tr("Name:"));
    win_layout->addWidget(name_label,0,0);
    win_layout->addWidget(name_line,0,1);
    win_layout->addWidget(input_but,1,1);
    connect(input_but,SIGNAL(clicked(bool)),this,SLOT(slot_sendname()));
}
void Winner::slot_sendname()
{
    QString name = name_line->text();
    sig_sendname(name);
    this->close();
}
