#include "seachtocomplement_addordel.h"
#include "ui_seachtocomplement_addordel.h"
#include "searchtocomlement.h"
#include <QSqlQuery>
#include <QDebug>
seachtocomplement_addordel::seachtocomplement_addordel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::seachtocomplement_addordel)
{
    ui->setupUi(this);
    modell = nullptr;
    if(modell == nullptr)
    {
        modell = new QSqlQueryModel(this);
        modell->setQuery(QString("SELECT member_ID, fullName, data_Of_Birth, sex, ID_Card, address FROM Members WHERE family_ID=%1").arg(mhgd));
        ui->tableView_tv->setModel(modell);
    }
    else
    {
        modell->setQuery("SELECT member_ID, full_Name, data_Of_Birth, sex, ID_Card, address FROM Members ");
    }
}

seachtocomplement_addordel::~seachtocomplement_addordel()
{
    delete ui;
}

void seachtocomplement_addordel::on_btn_ttv_clicked()
{
    close();
    family_complementaddnew *fami = new family_complementaddnew();
    fami->setWindowTitle("Thêm thành viên mới");
    fami->show();
}


void seachtocomplement_addordel::on_btn_xtt_clicked()
{
    close();
    deletemember *delet = new deletemember();
    delet->setWindowTitle("Xóa thành viên");
    delet->show();
}

