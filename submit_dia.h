#ifndef SUBMIT_DIA_H
#define SUBMIT_DIA_H

#include <QDialog>
#include<QVector>

namespace Ui {
class submit_dia;
}

class submit_dia : public QDialog
{
    Q_OBJECT
    
public:
    explicit submit_dia(QWidget *parent = 0);
    ~submit_dia();
    void setdata(QVector<QString> contents);
    
private:
    Ui::submit_dia *ui;
};

#endif // SUBMIT_DIA_H
