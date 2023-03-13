#include "manage_showservice.h"
#include "ui_manage_showservice.h"

manage_showservice::manage_showservice(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::manage_showservice)
{
    ui->setupUi(this);
    mModel = nullptr;
    if(mModel == nullptr)
    {
        mModel = new QSqlQueryModel(this);
        mModel->setQuery("SELECT * FROM Services");
        ui->tableView_dv->setModel(mModel);
    }
    else
    {
        mModel->setQuery("SELECT * FROM Services");
    }
}

manage_showservice::~manage_showservice()
{
    delete ui;
}
