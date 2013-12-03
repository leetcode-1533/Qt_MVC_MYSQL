#include "mysql_establish.h"
#include<QtSql>
#include<QtDebug>
#include<QMessageBox>

//QSqlDatabase Mysql_Establish::database;

Mysql_Establish::Mysql_Establish(QString type,QString hostname,
                                 QString username,QString password,QString basename)
{

    Type=type;
    Hostname=hostname;
    Username=username;
    Password=password;
    Basename=basename;
}

 void Mysql_Establish::connects(){
            database=QSqlDatabase::addDatabase(Type);
            database.setHostName(Hostname);
            database.setUserName(Username);
            database.setPassword(Password);
            database.setDatabaseName(Basename);

            if(!database.open()){
               QMessageBox::warning(0,"my","te",QMessageBox::Cancel|QMessageBox::Abort);
            }
            else{
                qDebug()<<"everything is fine";
            }
}
void Mysql_Establish::initilize(){
    /*query=QSqlQuery(Mysql_Establish::database);
    query.exec("create table professor(name char(64) primary key,"
               "age char(20),password char(20),priority bigint(4))");*/
}

QSqlDatabase Mysql_Establish::data()
{
        return database;
}

