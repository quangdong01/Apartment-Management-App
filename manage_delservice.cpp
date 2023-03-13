#include "manage_delservice.h"
#include "ui_manage_delservice.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>
manage_delservice::manage_delservice(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::manage_delservice)
{
    ui->setupUi(this);
    Model = nullptr;
    if(Model == nullptr)
    {
        Model = new QSqlQueryModel(this);
        Model->setQuery("SELECT * FROM Services");
        ui->tableView_dv->setModel(Model);
    }
    else
    {
         Model->setQuery("SELECT * FROM Services");
    }
}

manage_delservice::~manage_delservice()
{
    delete ui;
}

void manage_delservice::on_btn_x_clicked()
{
    bool check = true;
    QString ma_dich_vu = ui->lineEdit_mdv->text();
    int mdv = ma_dich_vu.toInt();

    if(ma_dich_vu == "")
    {
        QMessageBox::information(this, "Warning", "Thông tin không được bỏ trống");
    }
    else
    {
        // Create record for search if mdv already existed

        QSqlQuery q("SELECT * FROM Services");
        QSqlRecord rec = q.record();
        int mCol = rec.indexOf("service_ID");
        while(q.next())
        {
            if(mdv == q.value(mCol).toInt())
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

                QSqlQuery query;
                query.prepare("DELETE FROM Orders WHERE service_ID=?");
                query.bindValue(0, mdv);
                query.exec();


                QSqlQuery qry;
                qry.prepare("DELETE FROM Services WHERE service_ID=?");
                qry.bindValue(0, mdv);
                qry.exec();
                close();
            }
        }
        else
        {
            QMessageBox::warning(this, "Warning", "Mã nhân viên không tồn tại");
        }
    }
}

