#include "pform.h"
#include "ui_pform.h"
#include <QDebug>

pForm::pForm(Mysql_Establish *establish, privilege *test, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pForm),
    tk(test)
{
    ui->setupUi(this);
    en=establish;
    database=en->data();
//Model
    model= new QSqlTableModel(this,database);
    model->setTable("person");
    model->select();


//Widget
    name = new QLineEdit(this);
    phone = new QLineEdit(this);
    email = new QLineEdit(this);
    birth = new QLineEdit(this);

//View
    mapper = new QDataWidgetMapper;
    mapper->setModel(model);
    stu = new QTableView(this);
    stu->setModel(model);
   // admin= new QTableWidget(this);
    //tutor = new QTableWidget(this);
//Layout
    glayout = new QGridLayout;
    vlayout = new QVBoxLayout;

    glayout->addWidget(name,1,1);
    glayout->addWidget(birth,1,2);
    glayout->addWidget(email,2,1);
    glayout->addWidget(phone,2,2);

    vlayout->addWidget(stu,2);
    vlayout->addLayout(glayout,1);

    this->setLayout(vlayout);
    //   tab = new QTabWidget(this);


    mapper->addMapping(name,0);
    mapper->addMapping(birth,1);
    mapper->addMapping(email,5);
    mapper->addMapping(phone,6);

    mapper->toFirst();


}

pForm::~pForm()
{
    delete ui;
}


