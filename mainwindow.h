#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QDebug>
#include<QVector>
#include "privilege.h"
#include"mysql_establish.h"
#include"pform.h"
#include<QPushButton>
#include"news.h"
#include<QSqlRelationalTableModel>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(news *wrong,Mysql_Establish * connects,QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void set_pri(QVector<int> priv);


private:
    Ui::MainWindow *ui;
    QVector<int> pri;
    privilege* cd;
    pForm* pf;
    Mysql_Establish * con;
    news *newer;
    QPushButton * declearer;
    QSqlRelationalTableModel * rel;


};

#endif // MAINWINDOW_H
