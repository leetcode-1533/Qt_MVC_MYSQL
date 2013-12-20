#ifndef YINGQLINEEDIT_H
#define YINGQLINEEDIT_H

#include <QLineEdit>
#include<QMouseEvent>
#include<QDate>
class yingQlineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit yingQlineEdit(QWidget *parent = 0);
    
signals:
   void clicked();
    
public slots:
   void set_date(QDate date);

protected:
   void mousePressEvent(QMouseEvent *event);
    
};

#endif // YINGQLINEEDIT_H
