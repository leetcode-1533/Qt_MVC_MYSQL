#ifndef BIGNEWS_H
#define BIGNEWS_H

#include <QWidget>
#include"mysql_establish.h"
#include<QDataWidgetMapper>

namespace Ui {
class bignews;
}

class bignews : public QWidget
{
    Q_OBJECT
    
public:
    explicit bignews(Mysql_Establish * conn,QWidget *parent = 0);
    ~bignews();
    
private:
    Ui::bignews *ui;
    QDataWidgetMapper * mapper;
    Mysql_Establish * con;
};

#endif // BIGNEWS_H
