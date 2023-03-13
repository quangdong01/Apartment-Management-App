#include "manage_showsumserpay.h"
#include "ui_manage_showsumserpay.h"

manage_showsumserpay::manage_showsumserpay(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::manage_showsumserpay)
{
    ui->setupUi(this);
    Model = nullptr;
    if(Model == nullptr)
    {
        Model = new QSqlQueryModel(this);
        Model->setQuery("SELECT * FROM ServicePayment");
        ui->tableView_dltdv->setModel(Model);
    }
    else
    {
        Model->setQuery("SELECT * FROM ServicePayment");
    }
}

manage_showsumserpay::~manage_showsumserpay()
{
    delete ui;
}
