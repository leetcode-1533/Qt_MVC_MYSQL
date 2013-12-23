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
    QSqlTableModel * model;
    QSqlRelationalTableModel *modeld;
private slots:
    void insert();
    void detail(QModelIndex &index);


};

#endif // NEWS_H
