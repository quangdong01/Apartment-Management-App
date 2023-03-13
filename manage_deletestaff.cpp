#include "manage_deletestaff.h"
#include "ui_manage_deletestaff.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlRecord>
manage_deletestaff::manage_deletestaff(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::manage_deletestaff)
{
    ui->setupUi(this);
    mmModel = nullptr;
    if(mmModel == nullptr)
    {
        mmModel = new QSqlQueryModel(this);
        mmModel->setQuery("SELECT staff_ID, staff_FullName, staff_Sex, ID_Card, staff_Title, staff_Salary_default, staff_dayoff, staff_Salary_Pay, staff_Phone FROM Staffs");
        ui->tableView_nv->setModel(mmModel);
    }
    else
    {
        mmModel = new QSqlQueryModel(this);
        mmModel->setQuery("SELECT staff_ID, staff_FullName, staff_Sex, ID_Card, staff_Title, staff_Salary_default, staff_dayoff, staff_Salary_Pay, staff_Phone FROM Staffs");
        ui->tableView_nv->setModel(mmModel);
    }
}

manage_deletestaff::~manage_deletestaff()
{
    delete ui;
}

void manage_deletestaff::on_btn_x_clicked()
{
    bool check = true;
    QString ma_nhan_vien = ui->lineEdit_mnv->text();
    if(ma_nhan_vien == "")
    {
        QMessageBox::warning(this, "Warning", "Thông tin không được để trống");
    }
    else
    {
        QSqlQuery q("SELECT * FROM Staffs");
        QSqlRecord rec = q.record();
        int staffCol = rec.indexOf("staff_ID");
        while(q.next())
        {
            if(ma_nhan_vien == q.value(staffCol).toString())
            {
                check = false;
                break;
            }
        }
        if(check == false)
        {
            QMessageBox::StandardButton reply = QMessageBox::question(this,"Warning", "Bạn có chắc xóa nhân viên này chứ", QMessageBox::Yes | QMessageBox::No);
            if(reply == QMessageBox::Yes)
            {
                QSqlQuery qry;
                qry.prepare("DELETE FROM Staffs WHERE staff_ID=?");
                qry.bindValue(0, ma_nhan_vien);
                qry.exec();
                close();
            }
        }
        else
        {
            QMessageBox::information(this, "Information", "Mã nhân viên không tồn tại");
        }
    }
}

