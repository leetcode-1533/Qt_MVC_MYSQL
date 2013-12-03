#ifndef PRIVILEGE_H
#define PRIVILEGE_H

#include <QObject>
#include<QVector>

class privilege : public QObject
{
    Q_OBJECT
public:
    explicit privilege(QVector<int> init,QObject *parent = 0);
    bool e_hum(){
        return human;
    }
    bool e_doc(){
        return doc;
    }
    bool e_tutor(){
        return tutor;
    }
    bool e_stu(){
        return stu;
    }
    ~privilege();

private:
    QVector<int> pri;
    bool human;
    bool doc;
    bool tutor;
    bool stu;
    
signals:
    
public slots:
    
};

#endif // PRIVILEGE_H
