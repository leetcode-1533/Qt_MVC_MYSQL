#ifndef MYSQL_ESTABLISH_H
#define MYSQL_ESTABLISH_H
#include<QtSql>
#include<QString>

class Mysql_Establish
{
public:
    Mysql_Establish(QString ="QMYSQL", QString="localhost" ,
                    QString ="root", QString="1562348" , QString ="test");
    void connects();
    bool initilize();
    QSqlDatabase data();
private:
    QString Type;
    QString Hostname;
    QString Username;
    QString Password;
    QString Basename;
    QSqlQuery query;
    QSqlDatabase database;
};

#endif // MYSQL_ESTABLISH_H
