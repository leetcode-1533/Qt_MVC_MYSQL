#include "w_form.h"
#include "ui_w_form.h"
#include"s_form.h"
#include<QtGui>
#include"mysql_establish.h"

W_Form::W_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::W_Form)
{
    ui->setupUi(this);
    tab = new QTabWidget(this);
    Mysql_Establish con;
    QLabel * label = new QLabel("Hell QT");
    s_Form * test = new s_Form(this);
    tab->addTab(label,"tab");
    tab->addTab(test,"SHUNI");
    tab->resize(400,300);

    this->resize(500,500);
}

W_Form::~W_Form()
{
    delete ui;
}
