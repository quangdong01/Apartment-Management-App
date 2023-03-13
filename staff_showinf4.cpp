#include "staff_showinf4.h"
#include "ui_staff_showinf4.h"
#include "login.h"
staff_showinf4::staff_showinf4(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::staff_showinf4)
{
    ui->setupUi(this);
    Model = nullptr;
    if(Model == nullptr)
    {
        Model = new QSqlQueryModel(this);
        Model->setQuery(QString("SELECT staff_ID, staff_FullName, staff_Sex, ID_Card, staff_Title, staff_Salary_default, staff_dayoff, staff_Salary_Pay, staff_Phone FROM Staffs WHERE staff_ID=%1").arg(MNV));
        ui->tableView_nv->setModel(Model);
    }
    else
    {
        Model->setQuery(QString("SELECT staff_ID, staff_FullName, staff_Sex, ID_Card, staff_Title, staff_Salary_dafault, staff_dayoff, staff_Salary_Pay, staff_Phone FROM Staffs WHERE staff_ID=%1").arg(MNV));
    }
}

staff_showinf4::~staff_showinf4()
{
    delete ui;
}
