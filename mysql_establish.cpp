#include "mysql_establish.h"
#include<QtSql>
#include<QtDebug>
#include<QMessageBox>

//QSqlDatabase Mysql_Establish::database;

Mysql_Establish::Mysql_Establish(QString type,QString hostname,
                                 QString username,QString password,
                                 QString basename,int po)
{
    Type=type;
    Hostname=hostname;
    Username=username;
    Password=password;
    Basename=basename;
    port=po;
}
Mysql_Establish::~Mysql_Establish(){
    database.close();
}

 void Mysql_Establish::connects(){
            database=QSqlDatabase::addDatabase(Type);
            database.setHostName(Hostname);
            database.setUserName(Username);
            database.setPassword(Password);
            database.setDatabaseName(Basename);
            database.setPort(port);
            database.open();

}
bool Mysql_Establish::initilize(){
    query=QSqlQuery(Mysql_Establish::database);
    query.exec("create table person(name char(64) primary key,"
               "birth date,password char(20),priority bigint(4),"
               "type bigint(4),phone char(30),email char(30))");



}

QSqlDatabase Mysql_Establish::data()
{
        return database;
}

