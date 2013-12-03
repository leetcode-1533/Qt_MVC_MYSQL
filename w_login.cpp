#include "w_login.h"
#include "ui_w_login.h"
#include<QDebug>
#include<QMessageBox>
#include"mysql_establish.h"
#include<QtSql>
#include<QString>

W_login::W_login(Mysql_Establish * connect, QString u1, QString u2, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::W_login),
    user(u1),pass(u2)
{
    ui->setupUi(this);
    ui->line_pass->setEchoMode(QLineEdit::Password);
    con=connect;
}

W_login::~W_login()
{
    qDebug()<<user<<pass;
    delete ui;
}
int W_login::priority(QString na, QString pass)
{
    QSqlQuery test(con->data());
   // qDebug()<<test.at();
    test.exec("select * from professor");
    int flag=0;
    while(test.next())
    {
           // int id = query.value(0).toInt();

        QString name = test.value(0).toString();
        QString password = test.value(2).toString();
        int pri = test.value(3).toInt();

        if (name==na&&pass==password)
        {
            return pri;
        }
    }
    if (flag==0)
    {
        return 0;
    }
}
void W_login::on_enterButton_clicked()
{
    user=this->ui->line_user->text().trimmed();
    pass=this->ui->line_pass->text();
  //  qDebug()<<priority(user,pass);
     priority(user,pass);
//     if (this->ui->line_user->text().trimmed()==user&&
//             this->ui->line_pass->text()==pass)
//         accept();
//     else
//     {
//         QMessageBox::warning(this,tr("Wrong passer"),tr("some wrong with the input"),QMessageBox::Yes);
//         this->ui->line_pass->clear();
//         this->ui->line_user->clear();
//         this->ui->line_user->setFocus();
//     }
}
