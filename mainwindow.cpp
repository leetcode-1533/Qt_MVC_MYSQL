#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"mysql_establish.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
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
