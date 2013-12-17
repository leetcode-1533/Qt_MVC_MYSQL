#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"w_form.h"
#include<QDebug>
#include<QVector>
#include "privilege.h"
#include"mysql_establish.h"
#include"sql_professor.h"

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
    W_Form Filler;
    QVector<int> pri;
    privilege* cd;
    Mysql_Establish * con;

    QAction *openAction;

    sql_professor tk;

};

#endif // MAINWINDOW_H
