#include "sql_professor.h"
#include<QDebug>

sql_professor::sql_professor(QSqlDatabase db, QObject *parent) :
    QObject(parent),
    data(db)
{
    model=new QSqlTableModel(this,data);
    query=QSqlQuery(db);
    model->setTable("professor");
    model->select();
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
}

bool sql_professor::insert(){

    int rowNum=model->rowCount();
    model->insertRow(rowNum);
    model->setData(model->index(rowNum,0),name);
    model->setData(model->index(rowNum,1),age);

    if(model->submitAll()){
        model->database().commit();
        qDebug()<<"SQL_Submitted";
        return true;
    }
    else
    {
        model->database().rollback();
        qDebug()<<"arrogant";
        return false;
    }
}
