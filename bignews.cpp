#include "bignews.h"
#include "ui_bignews.h"

bignews::bignews(Mysql_Establish *conn, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bignews),con(conn)
{
    ui->setupUi(this);
    mapper = new QDataWidgetMapper(this);
    //mapper->addMapping();
}

bignews::~bignews()
{
    delete ui;
}
