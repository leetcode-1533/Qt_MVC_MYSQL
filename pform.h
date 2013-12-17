#ifndef PFORM_H
#define PFORM_H

#include <QWidget>
#include"privilege.h"
#include"mysql_establish.h"
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QTableWidget>
#include<QTabWidget>
#include<QLayout>
#include<QTableWidget>
#include<QSqlTableModel>
#include<QDataWidgetMapper>
#include"mysql_establish.h"

namespace Ui {
class pForm;
}

class pForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit pForm(Mysql_Establish *establish,privilege *test,QWidget *parent = 0);
    ~pForm();

    
private slots:

private:
    Ui::pForm *ui;
    privilege *tk;

    QDataWidgetMapper * mapper;

    Mysql_Establish *en;
    QSqlDatabase database;
    QSqlTableModel * model;



    // Widgets:
    QTabWidget * tab;
    QVBoxLayout * vlayout;
    QGridLayout  * glayout;


    QTableView * stu;
    QTableWidget * tutor;
    QTableWidget * admin;

    QLineEdit * name;
    QLineEdit * birth;
    QLineEdit * phone;
    QLineEdit * email;

};

#endif // PFORM_H
