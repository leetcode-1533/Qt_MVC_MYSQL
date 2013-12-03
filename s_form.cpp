#include "s_form.h"
#include "ui_s_form.h"
#include<QDebug>
#include<QtSql>
#include"sql_professor.h"
#include "mysql_establish.h"

s_Form::s_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::s_Form)
{
    ui->setupUi(this);
    this->setGeometry(0,0,400,300);

}

s_Form::~s_Form()
{
    delete ui;
}

void s_Form::on_pushButton_clicked()
{
    Mysql_Establish con;
//  //  sql_professor pro(con.connects(),this);
//    //pro.propertyset(ui->lineEdit->text(),
//                 //   ui->lineEdit_2->text());
//    pro.insert();

}
