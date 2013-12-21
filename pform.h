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
#include<QPushButton>
#include<QSignalMapper>
#include"yingqlineedit.h"
#include<QCalendarWidget>
#include<QDate>
#include<QSqlRecord>
#include <QVariant>
#include<QSqlQuery>

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
    void submit();
    int pshow(bool state);
    void setbirth();
    void setbirth(QDate date);
    void del();
    void reset1();
    void reset2();
    void reset_warning(int );
signals:
    void clearall();
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

    QVBoxLayout * vlayout;
    QHBoxLayout * hlayout;

    QGridLayout  * glayout;
    QGridLayout * glayoutc;
    QGridLayout * center;

    QTableView * stu;

    QCheckBox *professor;
    QCheckBox *student;

    QLineEdit * name;
    QLineEdit * birth;
    QLineEdit * phone;
    QLineEdit * email;

    QLabel * in;
    QLabel * ib;
    QLabel *ip;
    QLabel *ie;
//page2:

    QSqlQuery * query;
    QLineEdit * pname;
    QCalendarWidget *cal;
    QGridLayout * callayout;
    yingQlineEdit * pbirth;
    QLineEdit * pphone;
    QLineEdit * pemail;
    QLineEdit * ppass;
    QLineEdit * p2pass;
    QLineEdit * ppriority;
    QLineEdit * ptype;

    QLabel * lpname;
    QLabel * lpbirth;
    QLabel * lpphone;
    QLabel * lpemail;
    QLabel * lppass;
    QLabel * lppriority;
    QLabel * lptype;

    QGridLayout * level1;
    QHBoxLayout * level2_1;
    QHBoxLayout * level2_2;
    QVBoxLayout * all;

    QPushButton *submitter;
    QPushButton * deleter;
    QPushButton * reseter1;
    QPushButton * reseter2;

// pack up
    void createpage1(QWidget * tku);
    void createpage2(QWidget * tku);

    void CONNECT(bool mode);

};

#endif // PFORM_H
