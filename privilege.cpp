#include "privilege.h"
#include<QDebug>

privilege::privilege(QVector<int> init, QObject *parent) :
    QObject(parent),
    pri(init)
{
  //  qDebug()<<init;
    switch (pri[0]){
    case 0:human=false;doc=false;break;
    case 1:human=true;doc=false;break;
    case 2:doc=true;human=false;break;
    case 3:human=true;doc=true;break;
    }
    switch (pri[1]){
    case 0:tutor=false;stu=false;break;
    case 1:tutor=false;stu=true;break;
    case 2:tutor=true;stu=false;break;
    }
}
QString privilege::p2str(int type){
    switch (type){
    case 0:return "none";
    case 1:return "human";
    case 2:return "doc";
    case 3:return "full";
    }
}
int privilege::str2p(QString str){
        if(str=="none")
            return 0;
        if (str=="human")
            return 1;
        if (str=="doc")
            return 2;
        if (str=="full")
            return 3;

}
QString privilege::type2str(int p){


        switch (p){
        case 0:return "none";
        case 1:return "stu";
        case 2:return "tutor";
        }

}
int privilege::str2type(QString str){
//    switch (str){
//    case "none":return 0;
//    case "stu":return 1;
//    case "tutor":return 2;

//    }
    if(str=="none")
        return 0;
    if(str=="stu")
        return 1;
    if(str=="tutor")
        return 2;
}

privilege::~privilege(){
}
