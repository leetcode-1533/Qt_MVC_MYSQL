#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"mysql_establish.h"
#include<QDebug>
#include"privilege.h"

MainWindow::MainWindow(Mysql_Establish * connects, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    con(connects)
{
    ui->setupUi(this);
    declearer = new QPushButton("declear",this);
    ui->horizontalLayout->addWidget(declearer);

    newer = new news(con);
    ui->tableView->setModel(newer->getmodel());
    ui->tableView->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    connect(declearer,SIGNAL(clicked()),newer,SLOT(show()));

    connects->initilize();
    //connect(ui->tableView,SIGNAL(clicked(QModelIndex)),)
//    connect->initilize();
}

MainWindow::~MainWindow()
{
    delete ui;
  //  qDebug()<<cd->e_hum();
}

void MainWindow::on_pushButton_clicked()
{
    pf->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    Mysql_Establish init;
    init.initilize();
}

void MainWindow::set_pri(QVector<int> priv)
{
    this->show();
    cd = new privilege(priv,this);
    pf = new pForm(con,cd);

    if(cd->e_tutor()&cd->e_stu()){
        ui->pushButton_2->show();
    }
    else{
        ui->pushButton_2->hide();
    }

    qDebug()<<cd->e_tutor();
    if(cd->e_tutor())
    {
        declearer->show();
    }
    else{
        declearer->hide();
    }
}

