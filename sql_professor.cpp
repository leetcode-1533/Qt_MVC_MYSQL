#include "sql_professor.h"
#include<QDebug>

sql_professor::sql_professor(QSqlDatabase db, QObject *parent) :
    QObject(parent),
    data(db)
{
    model=new QSqlTableModel(this,data);
    relmodel=new QSqlRelationalTableModel(this,data);


    query=QSqlQuery(db);
    model->setTable("person");
    model->select();
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    relmodel->setTable("person");
    relmodel->setRelation(0,QSqlRelation("test","name","test"));
    relmodel->select();
    qDebug()<<relmodel->lastError().text()<<relmodel->relation(0).displayColumn();
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
