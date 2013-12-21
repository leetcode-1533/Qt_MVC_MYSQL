#include "pform.h"
#include "ui_pform.h"
#include <QDebug>
#include<QSizePolicy>
#include<QHeaderView>
#include<QMessageBox>
#include"submit_dia.h"
#include<QVector>
#include<QStringList>
#include<QString>
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
//    model->select();
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
//            int row = model2->rowCount();
//            model2->insertRow(row);
//            model2->setData(model2->index(row,0),"ying");
//            model2->submitAll();


}

pForm::~pForm()
{
    delete ui;
}

void pForm::createpage1(QWidget *tku){
    //checkBox:
        student = new QCheckBox("stu",tku);
        student->setChecked(false);
        professor = new QCheckBox("pro",tku);
        professor->setChecked(false);

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

        glayoutc->addWidget(student,2,2);



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
                 cal= new QCalendarWidget(tku);
                 cal->hide();
                 pname = new QLineEdit(tku);
                 pbirth = new yingQlineEdit(tku);
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

                 query = new QSqlQuery(database);


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
    connect(professor,SIGNAL(clicked(bool)),this,SLOT(pshow(bool)));
    connect(student,SIGNAL(clicked(bool)),this,SLOT(pshow(bool)));

    connect(pbirth,SIGNAL(clicked()),this,SLOT(setbirth()));
    connect(cal,SIGNAL(clicked(QDate)),this,SLOT(setbirth(QDate)));
    {
        connect(this,SIGNAL(clearall()),pname,SLOT(clear()));
        connect(this,SIGNAL(clearall()),pbirth,SLOT(clear()));
        connect(this,SIGNAL(clearall()),pemail,SLOT(clear()));
        connect(this,SIGNAL(clearall()),pphone,SLOT(clear()));
        connect(this,SIGNAL(clearall()),p2pass,SLOT(clear()));
        connect(this,SIGNAL(clearall()),ppass,SLOT(clear()));
        connect(this,SIGNAL(clearall()),ptype,SLOT(clear()));
        connect(this,SIGNAL(clearall()),ppriority,SLOT(clear()));

    }
}

void pForm::submit(){

//    submitter = new QPushButton(tku);
//    cal= new QCalendarWidget(tku);
//    cal->hide();
//    pname = new QLineEdit(tku);
//    pbirth = new yingQlineEdit(tku);
//    pphone = new QLineEdit(tku);
//    pemail = new QLineEdit(tku);
//    ppass = new QLineEdit(tku);
//    p2pass = new QLineEdit(tku);
//    ppriority = new QLineEdit(tku);
//    ptype = new QLineEdit(tku);


    QVector<QString> vec;
    vec.append(pname->text());
    vec.append(pbirth->text());
    vec.append(ppass->text());
    vec.append(ppriority->text());
    vec.append(ptype->text());
    vec.append(pphone->text());
    vec.append(pemail->text());

    QString str = QString("name,birth,password,priority,type,phone,email");
    QStringList strlist = str.split(",");
    bool could = true;
    for (int i = 0 ; i<= 6;i++)
    {
        if(vec[i]==NULL)
        {

            QMessageBox::warning(this,tr("Incomplete"),
                                 tr("%1 is missing").arg(strlist.at(i)),QMessageBox::Yes);
            could = false;
            break;
        }
    }
//    /*qDebug*/()<<could;
    if(could == true)
    {


    submit_dia * sub = new submit_dia(this);
    sub->setModal(true);
    sub->setdata(vec);
    sub->show();
    if(sub->exec()==true){
    QString pre=QString ("INSERT INTO person (`name`, `birth`, `password`, `priority`, `type`, `phone`, `email`) VALUES (:name,:birth,:password,:priority,:type,:phone,:email)");
    query->prepare(pre);
    query->bindValue(":name",pname->text().toAscii());
    query->bindValue(":birth",pbirth->text());
    query->bindValue(":password",ppass->text());
    query->bindValue(":priority",ppriority->text());
    query->bindValue(":type",ptype->text());
    query->bindValue(":phone",pphone->text());
    query->bindValue(":email",pemail->text());
    if(query->exec()==false){
        QMessageBox::warning(this,tr("Failed"),
                             tr("%1").arg(model->lastError().text()),QMessageBox::Yes);
    }
    else{
    emit(clearall());
    }

    }

    }

}

int pForm::pshow(bool state){
    int a = professor->checkState();
    int b = student->checkState();

    if(a==Qt::Unchecked&&b==Qt::Unchecked)
        model->setFilter("type=3");   //3 Does not exist,Sorry for My poor SQL
    if(a==Qt::Checked&&b==Qt::Checked)
        model->setFilter("");
    if(a==Qt::Unchecked&&b==Qt::Checked)
        model->setFilter("type=1");
    if(a==Qt::Checked&&b==Qt::Unchecked)
        model->setFilter("type=2");


//    qDebug()<<model->filter()<<a<<b;
    model->select();
}
void pForm::setbirth()
{
    callayout = new QGridLayout;
    //cal->adjustSize();
//    int w=this->size().width();
//    int h=this->size().height();
//    cal->setGeometry(0,0,w,h);
//    cal->show();
    cal->resize(this->size());
    cal->show();
    callayout->addWidget(cal,1,1);


//    lpname = new QLabel("name",tku);
//    lpbirth = new QLabel("birth",tku);
//    lpphone = new QLabel("phone",tku);
//    lpemail = new QLabel("email",tku);
//    lppass = new QLabel("pass",tku);
//    lppriority = new QLabel("pri",tku);
//    lptype = new QLabel("type",tku);

    pname->hide();
    pbirth->hide();
    pphone->hide();
    pemail->hide();
    ppass->hide();
    p2pass->hide();
    ppriority->hide();
    ptype->hide();

    lpname->hide();
    lpbirth->hide();
    lpphone->hide();
    lpemail->hide();
    lppass->hide();
    lppriority->hide();
    lptype->hide();
    submitter->hide();
    all->removeItem(level1);
    all->removeItem(level2_1);
    all->removeItem(level2_2);
    all->addWidget(cal);
    delete level1;
    delete level2_1;
    delete level2_2;
}
void pForm::setbirth(QDate date){
    QCalendarWidget * sen=(QCalendarWidget *)this->sender();
    cal->hide();

    pname->show();
    pbirth->show();
    pphone->show();
    pemail->show();
    ppass->show();
    p2pass->show();
    ppriority->show();
    ptype->show();

    lpname->show();
    lpbirth->show();
    lpphone->show();
    lpemail->show();
    lppass->show();
    lppriority->show();
    lptype->show();
    submitter->show();

    all->removeWidget(cal);
    level1 = new QGridLayout;
    level2_1 = new QHBoxLayout;
    level2_2 = new QHBoxLayout;

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


    pbirth->setText(date.toString(Qt::ISODate));


}

