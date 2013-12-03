#include <QtGui>
#include "mainwindow.h"
#include"w_login.h"
#include <mysql_establish.h>
#include<QDebug>
#include<QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Mysql_Establish con;
    con.connects();

    MainWindow w(&con);
    W_login login(&con);
    QObject::connect(&login,SIGNAL(found(QVector<int>)),&w,SLOT(set_pri(QVector<int>)));
    login.show();


    return a.exec();




}
