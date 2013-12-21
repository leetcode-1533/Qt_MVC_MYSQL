#include "submit_dia.h"
#include "ui_submit_dia.h"
#include<QString>

submit_dia::submit_dia(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::submit_dia)
{
    ui->setupUi(this);
}

submit_dia::~submit_dia()
{
    delete ui;
}
void submit_dia::setdata(QVector<QString> contents){
    ui->label->setText(tr("name is %1").arg(contents[0]));
    ui->label_2->setText(tr("birth is %1").arg(contents[1]));
    ui->label_3->setText(tr("passowrd is %1").arg(contents[2]));
    ui->label_4->setText(tr("priority is %1").arg(contents[3]));
    ui->label_5->setText(tr("type is %1").arg(contents[4]));
    ui->label_6->setText(tr("phone is %1").arg(contents[5]));
    ui->label_7->setText(tr("Email is %1").arg(contents[6]));


}
