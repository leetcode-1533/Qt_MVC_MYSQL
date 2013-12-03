#ifndef W_LOGIN_H
#define W_LOGIN_H

#include <QDialog>
#include<QString>
#include"mysql_establish.h"

namespace Ui {
class W_login;
}

class W_login : public QDialog
{
    Q_OBJECT
    
public:
    explicit W_login(Mysql_Establish * connect,  QString u1=tr("Test"),
                     QString u2=tr("test"),QWidget * parent = 0);
    ~W_login();
    
private slots:
    void on_enterButton_clicked();

private:
    Ui::W_login *ui;
    QString user;
    QString pass;
    int priority(QString na, QString pass);
    Mysql_Establish * con;
};

#endif // W_LOGIN_H
