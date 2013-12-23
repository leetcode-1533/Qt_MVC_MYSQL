#ifndef W_LOGIN_H
#define W_LOGIN_H

#include <QDialog>
#include<QString>
#include"mysql_establish.h"
#include<QVector>
#include<QDebug>
namespace Ui {
class W_login;
}

class W_login : public QDialog
{
    Q_OBJECT
    
public:
    explicit W_login(Mysql_Establish * connect,  QString u1=tr("Test"),
                     QString u2=tr("test"),QWidget * parent = 0);
    QString getname(){
        qDebug()<<user;
        return user;
    }

    ~W_login();
    
private slots:
    void on_enterButton_clicked();
    void on_pushButton_clicked();

signals:
    void found(QVector<int>);

private:
    Ui::W_login *ui;
    QString user;
    QString pass;
    int priority(QString na, QString pass);
    Mysql_Establish * con;
    QVector<int> set_pri(int a, int b);

};

#endif // W_LOGIN_H
