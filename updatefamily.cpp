#include "updatefamily.h"
#include "ui_updatefamily.h"

updatefamily::updatefamily(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::updatefamily)
{
    ui->setupUi(this);


    // Show Familys table in Database
    mModel = nullptr;
    if(mModel == nullptr)
    {
        mModel = new QSqlQueryModel(this);
        mModel->setQuery("SELECT * FROM Familys");
        ui->tableView_dshgd->setModel(mModel);
    }
    else
    {
        mModel->setQuery("SELECT * FROM Familys");
    }
}

updatefamily::~updatefamily()
{
    delete ui;
}

void updatefamily::on_btn_xhgd_clicked()
{
    close();
    deletefamily * del = new deletefamily();
    del->setWindowTitle("Xóa hộ gia đình");
    del->show();
}


void updatefamily::on_btn_ttv_clicked()
{
    close();
    searchtocomlement *sea = new searchtocomlement();
    sea->setWindowTitle("Cập nhật thành viên mới");
    sea->show();
}

