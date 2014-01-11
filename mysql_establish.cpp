#include "mysql_establish.h"
#include<QtSql>
#include<QtDebug>
#include<QMessageBox>
#include<QString>

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
    QString create_news=QString("CREATE TABLE news(id INT(11) NOT NULL AUTO_INCREMENT, title TEXT , contents TEXT,PRIMARY KEY(id))ENGINE=InnoDB");
    QString create_readable=QString("CREATE TABLE readables(id INT(11) NOT NULL AUTO_INCREMENT,news_id INT(11),new_id INT(11),per_name char(64),PRIMARY KEY(id), FOREIGN KEY(news_id) REFERENCES news(id) ON DELETE CASCADE, FOREIGN KEY(new_id) REFERENCES news(id) ON DELETE CASCADE,FOREIGN KEY (per_name) REFERENCES person(name)ON DELETE CASCADE)ENGINE=InnoDB");
    QString add_test = QString("INSERT INTO `test`.`person` (`name`, `birth`, `password`, `priority`, `type`, `phone`, `email`) VALUES ('test', '2014-01-08', '123456', '3', '2', '123456', '132456')");
    query.exec(create_news);
    query.exec(create_readable);
    query.exec(add_test);
   // qDebug()<<query.lastError();



}

QSqlDatabase Mysql_Establish::data()
{
        return database;
}

