#include "family_servicebuy.h"
#include "ui_family_servicebuy.h"
#include "login.h"
family_servicebuy::family_servicebuy(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::family_servicebuy)
{
    ui->setupUi(this);
    Model = nullptr;
    if(Model == nullptr)
    {
        Model = new QSqlQueryModel(this);
        Model->setQuery(QString("SELECT * FROM Orders WHERE family_ID=%1").arg(MHGD));
        ui->tableView_dvddk->setModel(Model);
    }
    else
    {
        Model->setQuery(QString("SELECT * FROM Orders WHERE family_ID=%1").arg(MHGD));
    }
}

family_servicebuy::~family_servicebuy()
{
    delete ui;
}
