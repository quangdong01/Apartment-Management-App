#include "showfamilys.h"
#include "ui_showfamilys.h"

showFamilys::showFamilys(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::showFamilys)
{
    ui->setupUi(this);
    mModel = nullptr;
    if(mModel == nullptr)
    {
        mModel = new QSqlQueryModel(this);
        mModel->setQuery("SELECT * FROM Familys");
        ui->tableView_Familys->setModel(mModel);
    }
    else
    {
        mModel->setQuery("SELECT * FROM Customers");
    }
}

showFamilys::~showFamilys()
{
    delete ui;
}
