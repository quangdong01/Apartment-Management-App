#include "staff_showcalendar.h"
#include "ui_staff_showcalendar.h"
#include "login.h"
staff_showcalendar::staff_showcalendar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::staff_showcalendar)
{
    ui->setupUi(this);
    Model = nullptr;
    if(Model == nullptr)
    {
        Model = new QSqlQueryModel(this);
        Model->setQuery(QString("SELECT staff_ID, staff_Monday, staff_Tuesday, staff_Wednesday, staff_Thursday, staff_Friday, staff_Saturday, staff_Sunday FROM Staffs WHERE staff_ID=%1").arg(MNV));
        ui->tableView_lt->setModel(Model);
    }
}

staff_showcalendar::~staff_showcalendar()
{
    delete ui;
}
