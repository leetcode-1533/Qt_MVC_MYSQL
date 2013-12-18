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
#include<QCheckBox>
#include<QTableWidget>
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
    void table_highlight(QModelIndex lm);

private:
    Ui::pForm *ui;
    privilege *tk;

    QDataWidgetMapper * mapper;

    Mysql_Establish *en;
    QSqlDatabase database;
    QSqlTableModel * model;

   //QTableWidget * tabbar;


//pages:
    QWidget *page1;
    QWidget *page2;
   //page1
    // Widgets:
    QTabWidget * tabbar;
    QVBoxLayout * vlayoutc;
    QVBoxLayout * vlayout;
    QHBoxLayout * hlayout;
    QGridLayout  * glayout;
    QGridLayout * center;


    QTableView * stu;

    QCheckBox *professor;
    QCheckBox *student;
    QCheckBox *admin;


    QLineEdit * name;
    QLineEdit * birth;
    QLineEdit * phone;
    QLineEdit * email;

    QLabel * in;
    QLabel * ib;
    QLabel *ip;
    QLabel *ie;
//page2:



};

#endif // PFORM_H
