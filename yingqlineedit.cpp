#include "yingqlineedit.h"

yingQlineEdit::yingQlineEdit(QWidget *parent) :
    QLineEdit(parent)
{
}
void yingQlineEdit::mousePressEvent(QMouseEvent *event){
    emit clicked();
}
void yingQlineEdit::set_date(QDate date){
    this->setText(date.toString());
}
