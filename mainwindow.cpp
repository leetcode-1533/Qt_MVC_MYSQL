#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"mysql_establish.h"
#include<QDebug>
#include"privilege.h"

MainWindow::MainWindow(Mysql_Establish * connect, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    con(connect)
{
    ui->setupUi(this);

    openAction = new QAction(tr("&Open"),this);
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("Open a file"));

    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);
    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction); 

}

MainWindow::~MainWindow()
{
    delete ui;
  //  qDebug()<<cd->e_hum();
}

void MainWindow::on_pushButton_clicked()
{
    Filler.show();
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
}
