#ifndef SQL_PROFESSOR_H
#define SQL_PROFESSOR_H

#include <QObject>
#include<QtSql>
#include<QString>

class sql_professor : public QObject
{
    Q_OBJECT
public:
    explicit sql_professor(QSqlDatabase db,QObject *parent = 0);

    void propertyset(QString na,QString ag){
        name=na;
        age=ag;
    }

    bool insert();
    QSqlTableModel * gettable(){
        return model;
    }

private:
    QSqlDatabase data;
    QSqlTableModel * model;
    QSqlQuery query;

    QString name;
    QString age;
    
signals:
    
public slots:
    
};

#endif // SQL_PROFESSOR_H
