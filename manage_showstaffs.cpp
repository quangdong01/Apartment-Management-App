#include "manage_showstaffs.h"
#include "ui_manage_showstaffs.h"

manage_showstaffs::manage_showstaffs(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::manage_showstaffs)
{
    ui->setupUi(this);
    mmmModel = nullptr;
    if(mmmModel == nullptr)
    {
        mmmModel = new QSqlQueryModel(this);
        mmmModel->setQuery("SELECT * FROM Staffs");
        ui->tableView_nv->setModel(mmmModel);
    }
    else
    {
         mmmModel->setQuery("SELECT * FROM Staffs");
    }
}

manage_showstaffs::~manage_showstaffs()
{
    delete ui;
}
