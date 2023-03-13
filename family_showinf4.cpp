#include "family_showinf4.h"
#include "ui_family_showinf4.h"
#include "login.h"
#include <QDebug>
family_showinf4::family_showinf4(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::family_showinf4)
{
    ui->setupUi(this);
    model = nullptr;
    if(model == nullptr)
    {
        model = new QSqlQueryModel(this);
        model->setQuery(QString("SELECT * FROM Members WHERE family_ID=%1").arg(MHGD));
        ui->tableView_gd->setModel(model);
    }
    else
    {
        model->setQuery(QString("SELECT * FROM Members WHERE family_ID=%1").arg(MHGD));
    }
}

family_showinf4::~family_showinf4()
{
    delete ui;
}
