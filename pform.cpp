#include "pform.h"
#include "ui_pform.h"
#include <QDebug>
#include<QSizePolicy>
#include<QHeaderView>
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
    model->removeColumn(4);
    model->removeColumn(3);
    model->removeColumn(2);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    // specifics privileges:
        if(test->e_hum()==true){

            page1 = new QWidget;
            page2 = new QWidget;

            center = new QGridLayout;
            tabbar = new QTabWidget(this);
            //page1:
           {
              createpage1(page1);
            }
            tabbar->addTab(page1,"View");
            // page2
            {
                createpage2(page2);
            }
            tabbar->addTab(page2,"set");

            center->addWidget(tabbar);
            this->setLayout(center);
        }
else{
            createpage1(this);
            name->setReadOnly(true);
            phone->setReadOnly(true);
            email->setReadOnly(true);
            birth->setReadOnly(true);

            stu->setEditTriggers(QAbstractItemView::NoEditTriggers);



}
        //Clicked Slot:
        //    connect(stu,SIGNAL(clicked(QModelIndex )),stu,SLOT())
            CONNECT(test->e_hum());
}

pForm::~pForm()
{
    delete ui;
}

void pForm::createpage1(QWidget *tku){
    //checkBox:
        student = new QCheckBox(tku);
        professor = new QCheckBox(tku);
        prolabel =new QLabel("Select Pro",tku);
        stulabel =new QLabel("Select stu",tku);

    //Widget
        name = new QLineEdit(tku);
        phone = new QLineEdit(tku);
        email = new QLineEdit(tku);
        birth = new QLineEdit(tku);

        in = new QLabel("name",tku);
        ip = new QLabel("Phone",tku);
        ie = new QLabel("Email",tku);
        ib = new QLabel("Birth",tku);


    //View
        mapper = new QDataWidgetMapper(tku);
        mapper->setModel(model);
        stu = new QTableView(tku);
        stu->setModel(model);


        //To highlight the entire row, insteads of a signal cell;
        stu->setSelectionBehavior(QAbstractItemView::SelectRows);
        stu->setSelectionMode(QAbstractItemView::SingleSelection);

        // set readonly

        //size
    //    stu->resizeColumnsToContents();
    //    stu->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
        stu->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
        stu->horizontalHeader()->setStretchLastSection(true);


    //Layout
        glayout = new QGridLayout;
        vlayout = new QVBoxLayout;
        hlayout = new QHBoxLayout;
        glayoutc = new QGridLayout;


        glayoutc->addWidget(professor,1,2);
        glayoutc->addWidget(prolabel,1,1);
        glayoutc->addWidget(student,2,2);
        glayoutc->addWidget(stulabel,2,1);


        glayout->addWidget(in,1,1);
        glayout->addWidget(ib,1,3);
        glayout->addWidget(name,1,2);
        glayout->addWidget(birth,1,4);

        glayout->addWidget(ie,2,1);
        glayout->addWidget(ip,2,3);
        glayout->addWidget(email,2,2);
        glayout->addWidget(phone,2,4);

        hlayout->addLayout(glayout);
        hlayout->addLayout(glayoutc);

        vlayout->addWidget(stu);
        vlayout->addLayout(hlayout);

        tku->setLayout(vlayout);
        //   tab = new QTabWidget(tku);


        mapper->addMapping(name,0);
        mapper->addMapping(birth,1);
        mapper->addMapping(email,2);
        mapper->addMapping(phone,3);
        mapper->toFirst();
}
void pForm::createpage2(QWidget *tku){

                 level1 = new QGridLayout;
                 level2_1 = new QHBoxLayout;
                 level2_2 = new QHBoxLayout;
                 all = new QVBoxLayout;

                 submitter = new QPushButton(tku);
                 pname = new QLineEdit(tku);
                 pbirth = new QLineEdit(tku);
                 pphone = new QLineEdit(tku);
                 pemail = new QLineEdit(tku);
                 ppass = new QLineEdit(tku);
                 p2pass = new QLineEdit(tku);
                 ppriority = new QLineEdit(tku);
                 ptype = new QLineEdit(tku);

                 lpname = new QLabel("name",tku);
                 lpbirth = new QLabel("birth",tku);
                 lpphone = new QLabel("phone",tku);
                 lpemail = new QLabel("email",tku);
                 lppass = new QLabel("pass",tku);
                 lppriority = new QLabel("pri",tku);
                 lptype = new QLabel("type",tku);

                 model2 = new QSqlTableModel(this,database);
                 model2->setTable("person");
                 model2->select();
                 model2->setEditStrategy(QSqlTableModel::OnManualSubmit);

                 mapper2 = new QDataWidgetMapper(tku);
                 mapper2->setModel(model2);

                 mapper2->addMapping(pname,0);
                 mapper2->addMapping(pbirth,1);
                 mapper2->addMapping(ppass,2);
                 mapper2->addMapping(ppriority,3);
                 mapper2->addMapping(ptype,4);
                 mapper2->addMapping(pemail,5);
                 mapper2->addMapping(pphone,6);
                 mapper2->toLast();

                 level1->addWidget(pname,1,2);
                 level1->addWidget(pbirth,1,4);
                 level1->addWidget(lpname,1,1);
                 level1->addWidget(lpbirth,1,3);
                 level1->addWidget(pemail,2,2);
                 level1->addWidget(pphone,2,4);
                 level1->addWidget(lpphone,2,3);
                 level1->addWidget(lpemail,2,1);

                 level2_1->addWidget(lppass);
                 level2_1->addWidget(ppass);
                 level2_1->addWidget(p2pass);

                 level2_2->addWidget(lppriority);
                 level2_2->addWidget(ppriority);
                 level2_2->addWidget(lptype);
                 level2_2->addWidget(ptype);
                 level2_2->addWidget(submitter);

                 all->addLayout(level1);
                 all->addLayout(level2_1);
                 all->addLayout(level2_2);

                 tku->setLayout(all);

}

void pForm::CONNECT(bool mode){
    if(mode==false){

    }
    else{
        connect(submitter,SIGNAL(clicked()),this,SLOT(submit()));

    }

    connect(stu,SIGNAL(clicked(QModelIndex )),mapper,SLOT(setCurrentModelIndex(QModelIndex )));

}

void pForm::submit(){
    model2->database().transaction();
    if(model2->submitAll()){
        model->database().commit();
        qDebug()<<"success";
    }
    else{
        model->database().rollback();
        qDebug()<<"failed!"<<model2->lastError();
    }
}

