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
#include<QPoint>
#include<QModelIndex>
#include<QSqlRecord>
#include"privilege.h"


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

//            tabbar->setCurrentIndex(1);
//            qDebug()<<tabbar->currentIndex();


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
        deleter = new QPushButton("delete",tku);
        reseter1 = new QPushButton("reset",tku);

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
        glayout->addWidget(deleter,1,5);

        glayout->addWidget(ie,2,1);
        glayout->addWidget(ip,2,3);
        glayout->addWidget(email,2,2);
        glayout->addWidget(phone,2,4);
        glayout->addWidget(reseter1,2,5);

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

                 submitter = new QPushButton("submit",tku);
                 reseter2 = new QPushButton("reset",tku);
                 reseter2->hide();


                 cal= new QCalendarWidget(tku);
                 cal->hide();
                 pname = new QLineEdit(tku);
                 pbirth = new yingQlineEdit(tku);
                 pphone = new QLineEdit(tku);
                 pemail = new QLineEdit(tku);
                 ppass = new QLineEdit(tku);
                 p2pass = new QLineEdit(tku);
                 ppriority = new QComboBox(tku);
                 ptype = new QComboBox(tku);

                 ppass->setEchoMode(QLineEdit::Password);
                 p2pass->setEchoMode(QLineEdit::Password);

                 ppriority->addItem("none");
//                 ppriority->addItem(privilege::p2str(1));
//                 ppriority->addItem(privilege::p2str(2));
//                 ppriority->addItem(privilege::p2str(3));


//                 ptype->addItem(privilege::type2str(0));
//                 ptype->addItem(privilege::type2str(1));
//                 ptype->addItem(privilege::type2str(2));


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
                 level2_2->addWidget(reseter2);

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
        connect(reseter1,SIGNAL(clicked()),this,SLOT(reset1()));
        connect(reseter2,SIGNAL(clicked()),this,SLOT(reset2()));
        connect(deleter,SIGNAL(clicked()),this,SLOT(del()));
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
    if(p2pass->text()!=ppass->text()){
        QMessageBox::warning(this,"Wrong Passer","The passwords do not equal",QMessageBox::Yes);
    }


    else{
    QVector<QString> vec;
    vec.append(pname->text());
    vec.append(pbirth->text());
    vec.append(ppass->text());
    vec.append((QString)ppriority->currentIndex());
    vec.append((QString)ptype->currentIndex());
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
    query->bindValue(":priority",ppriority->currentIndex());
    query->bindValue(":type",ptype->currentIndex());
    query->bindValue(":phone",pphone->text());
    query->bindValue(":email",pemail->text());
    if(query->exec()==false){
        QMessageBox::warning(this,tr("Failed"),
                             tr("%1").arg(model->lastError().text()),QMessageBox::Yes);
    }
    else{
    emit(clearall());
    ptype->setCurrentIndex(-1);
    ppriority->setCurrentIndex(-1);
    pshow(true); //I didn't actual need the inputed variable itself, just to keep consistence of the Two functions
    }
    }
    }
    }
}

int pForm::pshow(bool state){
    int a = professor->checkState();
    int b = student->checkState();

    if(a==Qt::Unchecked&&b==Qt::Unchecked)
        model->setFilter("type=11");   //11 Does not exist,Sorry for My poor SQL
    if(a==Qt::Checked&&b==Qt::Checked)
        model->setFilter("");
    if(a==Qt::Unchecked&&b==Qt::Checked)
        model->setFilter("type=1");   // 1 stands for pro
    if(a==Qt::Checked&&b==Qt::Unchecked)
        model->setFilter("type=2");  //2 stands for stu


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
    level2_2->addWidget(reseter2);

    all->addLayout(level1);
    all->addLayout(level2_1);
    all->addLayout(level2_2);

    pbirth->setText(date.toString(Qt::ISODate));

}

void pForm::del(){

    QModelIndex index = stu->selectionModel()->currentIndex();
//    qDebug()<<stu->selectionModel()->currentIndex().data();
    QString name=model->record(index.row()).value(0).toString();

//    int row =stu->selectionModel()->currentIndex().row();
//    int col = stu->selectionModel()->currentIndex();
//    model->data()
//    qDebug()<<stu->indexAt(QPoint(1,row));

//    qDebug()<<model->dat(
       bool flag =QMessageBox::warning(this,tr("Are you sure"),tr("are you sure delete %1?").arg(name));
       if (flag == true){
           model->removeRow(stu->selectionModel()->currentIndex().row());
           model->submitAll();
           pshow(true);
       }else{
           model->revertAll();
       }
//    model->data(QModeli)
}
void pForm::reset_warning(int index)
{
    //Prevent go back to Page 1(In this case labeled 0
        tabbar->setCurrentIndex(1);
}

void pForm::reset1(){
    QModelIndex index = stu->selectionModel()->currentIndex();
    QSqlTableModel * model2= new QSqlTableModel(this,database);
    model2->setTable("person");
    model2->select();
    QSqlRecord records = model2 ->record(index.row());

    //Turn To Page 2
    submitter->hide();
    reseter2->show();
    tabbar->setCurrentIndex(1);
    connect(tabbar,SIGNAL(currentChanged(int)),this,SLOT(reset_warning(int)));
    // Modify Page2
    QString name=records.value(0).toString();
    QString birth = records.value(1).toString();
    QString pass = records.value(2).toString();
    QString pri = records.value(3).toString();
    QString type = records.value(4).toString();
    QString phone = records.value(5).toString();
    QString email = records.value(6).toString();

    pname->setText(name);
    pbirth->setText(birth);
    ppass->setText(pass);
    p2pass->setText(pass);
//    ppriority->setCurrentIndex(privilege::str2p(pri));
//    ptype->setCurrentIndex(privilege::str2type(type));
    pphone->setText(phone);
    pemail->setText(email);
    model->removeRow(index.row());

//    qDebug()<<stu->selectionModel()->currentIndex().data();
//    =model->record(index.row()).value(0).toString();
//    delete submitter;

//   submitter = reseter;

}
void pForm::reset2(){
    bool flag =QMessageBox::warning(this,tr("Are you sure"),tr("are you sure to modify ?"),QMessageBox::Yes,QMessageBox::Cancel);

    if (flag == true){
//        model->removeRow(stu->selectionModel()->currentIndex().row());
        model->submitAll();
    }else{
        model->revertAll();
    }
    //Re-insert
    {
        this->submit();
    }
    disconnect(tabbar,SIGNAL(currentChanged(int)),0,0);
    submitter->show();
    reseter2->hide();

}

