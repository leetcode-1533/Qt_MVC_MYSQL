#include <QtGui/QApplication>
#include "mainwindow.h"
#include"w_login.h"
#include <mysql_establish.h>
#include<QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Mysql_Establish con;
    con.connects();
    qDebug()<<con.initilize();

    QMainWindow w;
    w.show();
    return a.exec();
//    W_login login(&con);

//    login.show();
//    qDebug()<<"test"<<login.exec();




//    if(login.exec()!=QDialog::Accepted)
//    {
//        //w.show();
//        return a.exec();
//    }
//    else
//        return 0;
}
