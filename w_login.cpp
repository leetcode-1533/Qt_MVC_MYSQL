#include "w_login.h"
#include "ui_w_login.h"
#include<QDebug>
#include<QMessageBox>
#include"mysql_establish.h"
#include<QtSql>
#include<QString>
#include<QVector>

W_login::W_login(Mysql_Establish * connect, QString u1, QString u2, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::W_login),
    user(u1),pass(u2)
{
    ui->setupUi(this);
    ui->line_pass->setEchoMode(QLineEdit::Password);
    ui->line_user->setFocus();
    con=connect;
}

W_login::~W_login()
{
   // qDebug()<<user<<pass;
    delete ui;
}

int W_login::priority(QString na, QString pass)
{
    QSqlQuery test(con->data());
    test.exec("select * from person");
    bool flag = 0;
    while(test.next())
    {
        QString name = test.value(0).toString();
        QString password = test.value(2).toString();
        if (name==na&&pass==password)
        {
            flag = 1;
            return test.at();
        }
    }
    if (flag==0)
    {
        return -1;
    }
}
void W_login::on_enterButton_clicked()
{
    user=this->ui->line_user->text().trimmed();
    pass=this->ui->line_pass->text();
    int loc =priority(user,pass);
    if (loc==-1)
    {
         QMessageBox::warning(this,tr("Wrong passer"),
                              tr("some wrong with the input"),QMessageBox::Yes);
                  this->ui->line_pass->clear();
                  this->ui->line_user->clear();
                  this->ui->line_user->setFocus();
    }
     else{
         QSqlQuery reader(con->data());
         reader.exec("select * from person");
         reader.seek(loc);
         int av = reader.value(3).toInt();
         int bv = reader.value(4).toInt();
         emit found(set_pri(av,bv));
         accept();
     }
}
QVector<int> W_login::set_pri(int a,int b){
    //qDebug()<<"yingjie"<<a<<b;
    QVector<int> ap;
    switch (a)
    {
    case 0: ap.append(0);break;
    case 1: ap.append(1);break;
    case 2: ap.append(2);break;
    case 3: ap.append(3);break;
 //   default: ap.append(0);
    }
    switch (b)
    {
    case 0:ap.append(0);break;
    case 1:ap.append(1);break;
    case 2:ap.append(2);break;
    }
    return ap;
}

void W_login::on_pushButton_clicked()
{
    this->close();
}
