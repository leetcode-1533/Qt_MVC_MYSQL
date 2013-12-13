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

     QString qtest= "INSERT INTO `test`.`person` (`name`, `birth`, `password`, `priority`, `type`, `phone`, `email`) VALUES (:first,:second,:third,:fourth,:fifth,:sixth,:seventh)";
     query.prepare(qtest);
     query.bindValue(":first","vcx");
     query.bindValue(":second","2013-12-31");
     query.bindValue(":third","123456");
     query.bindValue(":fourth","1");
     query.bindValue(":fifth","0");
     query.bindValue(":sixth","4312");
     query.bindValue(":seventh","4321");
     if( query.exec())
     {
         qDebug()<<"Value Recored"<<endl;
     }
     else{
         qDebug()<<query.lastError();
     }

}

QSqlDatabase Mysql_Establish::data()
{
        return database;
}

