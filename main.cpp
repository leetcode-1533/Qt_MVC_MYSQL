#include <QtGui>
#include "mainwindow.h"
#include"w_login.h"
#include <mysql_establish.h>
#include<QDebug>
#include<QObject>
#include<QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Mysql_Establish con;
    con.connects();
   // con.initilize();

    int flag = 0;
//    qDebug()<<con.data();
    // This part is about how to set up connections.
    while (con.data().isOpen()==false && flag == 0){
        QMessageBox::StandardButton tk=QMessageBox::warning(0,"Wrong","Wrong connection",
                                    QMessageBox::Retry|QMessageBox::Cancel);
        if (tk==QMessageBox::Retry)
        {
            flag = 0;
            con.connects();
        }
        else if (tk==QMessageBox::Cancel)
        {
            flag = 1;
            return 0;
        }
    }

    {
    W_login login(&con);
    MainWindow w(&con);
    QObject::connect(&login,SIGNAL(found(QVector<int>)),&w,SLOT(set_pri(QVector<int>)));
    //Something about the privilege System.
    login.show();

    return a.exec();
//    login.getname();//
    }


}
