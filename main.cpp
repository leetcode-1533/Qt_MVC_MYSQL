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
    qDebug()<<con.data();
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
    MainWindow w(&con);
    W_login login(&con);
    QObject::connect(&login,SIGNAL(found(QVector<int>)),&w,SLOT(set_pri(QVector<int>)));
    login.show();
    return a.exec();
    }


}
