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
bool Mysql_Establish::initilize(){
    query=QSqlQuery(Mysql_Establish::database);
    return query.exec("create table people(name char(64) primary kay,priority char(2),"
               "password char(20),birthday date,gender char(10),email char(64))");


}

QSqlDatabase Mysql_Establish::data()
{
        return database;
}

