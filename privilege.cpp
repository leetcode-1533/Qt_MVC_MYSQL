#include "privilege.h"
#include<QDebug>

privilege::privilege(QVector<int> init, QObject *parent) :
    QObject(parent),
    pri(init)
{
    switch (pri[0]){
    case 0:human=false;doc=false;break;
    case 1:human=true;doc=false;break;
    case 2:doc=true;human=false;break;
    case 3:human=true;doc=false;break;
    }
    switch (pri[1]){
    case 0:tutor=false;stu=false;break;
    case 1:tutor=false;stu=true;break;
    case 2:tutor=true;stu=false;break;
    }
}

privilege::~privilege(){
}
