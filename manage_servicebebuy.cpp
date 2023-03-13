#include "manage_servicebebuy.h"
#include "ui_manage_servicebebuy.h"

manage_servicebebuy::manage_servicebebuy(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::manage_servicebebuy)
{
    ui->setupUi(this);
    Model = nullptr;
    if(Model == nullptr)
    {
        Model = new QSqlQueryModel(this);
        Model->setQuery("SELECT * FROM Orders");
        ui->tableView_dvddk->setModel(Model);
    }
    else
    {
        Model->setQuery("SELECT * FROM Orders");
    }
}

manage_servicebebuy::~manage_servicebebuy()
{
    delete ui;
}
