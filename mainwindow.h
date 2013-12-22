#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QDebug>
#include<QVector>
#include "privilege.h"
#include"mysql_establish.h"
#include"pform.h"
#include<QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(Mysql_Establish * connect,QWidget *parent = 0);
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

    QPushButton * declearer;


};

#endif // MAINWINDOW_H
