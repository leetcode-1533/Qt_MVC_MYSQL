#ifndef NEWS_H
#define NEWS_H

#include <QDialog>
#include"mysql_establish.h"
#include<QSqlTableModel>
#include<QSqlRecord>
#include<QSqlQuery>
#include<QModelIndex>
#include<QSqlTableModel>
#include<QModelIndex>
#include<QSqlRelationalTableModel>
#include<QDataWidgetMapper>
#include"bignews.h"

namespace Ui {
class news;
}

class news : public QDialog
{
    Q_OBJECT
    
public:
    explicit news(Mysql_Establish *conn,QWidget *parent = 0);
    ~news();
    QSqlTableModel * getmodel(){
        return model;
    }
    
private slots:

private:
    Ui::news *ui;
    Mysql_Establish *con;
    QSqlQuery *query;
    QSqlRelationalTableModel * model;
//    QSqlRelationalTableModel *modeld;
    QDataWidgetMapper * mapper;
    bignews * dia;
    QString name;
private slots:
    void insert();
    void detail(QModelIndex  index);
    void setname(QString namer);
////        qDebug()<<"LOVE";
//            name = namer;
////            qDebug()<<name<<namer;
////            model->select();
//    }

};

#endif // NEWS_H
