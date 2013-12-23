#include "news.h"
#include "ui_news.h"
#include<QDebug>
#include<QMessageBox>
#include<QString>
#include<QTextDocument>
news::news(Mysql_Establish *conn,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::news),
    con(conn)
{
    ui->setupUi(this);
   // qDebug()<<this->exec();
   // qDebug()<<con->data();
    query = new QSqlQuery(con->data());
    model = new QSqlTableModel(this,con->data());
    model->setTable("news");
    model->removeColumn(2);
    model->removeColumn(0);
    model->select();

//    modeld = new QSqlTableModel(this,con->data());
//    modeld->
//    QPushButton * ok =ui->buttonBox->button(QDialogButtonBox::Ok);
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(insert()));
//    ui->buttonBox->standardButton(ok);
//    qDebug()<<ok;
  //  connect(
}

news::~news()
{
    delete ui;

}

void news::insert(){
    int flag=QMessageBox::question(this,"Are you sure","Your news is going to be published",QMessageBox::Save,QMessageBox::Cancel);
 //   qDebug()<<flag;
    if(flag==QMessageBox::Cancel){
        this->show();
    }
    else{
        QString til=ui->lineEdit->text();
        QString cont=ui->textEdit->document()->toHtml();
        int loc;
                //        qDebug()<<cont->toHtml();
//        ui->label_2->setText(ui->textEdit->document()->toHtml());
//        ui->textEdit_2->setText(cont->toHtml());
        QString pre("INSERT INTO `test`.`news` (`id`, `title`, `contents`) VALUES (NULL, :title, :contents)");
        query->prepare(pre);
        query->bindValue(":title",til);
        query->bindValue("contents",cont);
        if(query->exec()==false){
                QMessageBox::warning(this,tr("Failed"),
                                     tr("%1").arg(query->lastError().text()),QMessageBox::Yes);
            }
        else{
            ui->lineEdit->clear();
            ui->textEdit->clear();
//            query->value()

            // refresh readable
//get id
            QSqlQuery test(con->data());
            test.exec("select * from news");
            while(test.next()){
                if(test.value(1)==til,test.value(2)==cont){
                    loc=test.value(0).toInt();
                    break;
                }

            }
            QSqlQuery per(con->data());

            per.exec("select * from person");
            while(per.next()){
                QString name = per.value(0).toString();
                QSqlQuery inst(con->data());
                inst.prepare("INSERT INTO `test`.`readable` (`id`, `news_id`, `per_name`) VALUES (NULL, :id, :name);");
                inst.bindValue(":id",loc);
                inst.bindValue(":name",name);
                if(inst.exec()==false)
                qDebug()<<name<<loc<<endl;

            }
            model->select();

//            while(test.next())
//            {
//                QString name = test.value(0).toString();
//                QString ins=QString("INSERT INTO readable (`id`, `news_id`, `per_name`) VALUES (NULL,:news_id, :name)");
////                QSqlQuery("insert")

//            }

        }
    }
}
void news::detail(QModelIndex &index){
//    model

}
