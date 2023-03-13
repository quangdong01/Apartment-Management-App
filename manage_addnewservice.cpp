#include "manage_addnewservice.h"
#include "ui_manage_addnewservice.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlRecord>

manage_addnewservice::manage_addnewservice(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::manage_addnewservice)
{
    ui->setupUi(this);
}

manage_addnewservice::~manage_addnewservice()
{
    delete ui;
}

void manage_addnewservice::on_pushButton_clicked()
{
   bool check = false;
   QString ma_dich_vu = ui->lineEdit_mdv->text();
   int ma_dv = ma_dich_vu.toInt();
   QString ten_dv = ui->lineEdit_tdv->text();
   QString gia_dich_vu = ui->lineEdit_gdv->text();
   int gia_dv = gia_dich_vu.toInt();

   if(ma_dich_vu == "" || ten_dv == "" || gia_dich_vu == "")
   {
        QMessageBox::information(this, "Warning", "Thông tin không được bỏ trống");
   }
   else
   {
       QSqlQuery q("SELECT * FROM Services");
       QSqlRecord rec = q.record();
       int serIdCol = rec.indexOf("service_ID");
       while(q.next())
       {
           if(ma_dv == q.value(serIdCol).toInt())
           {
                check = true;
                break;
           }
       }

       if(check)
       {
           QMessageBox::warning(this, "Warning", "Mã dịch vụ đã tồn tại");
       }
       else
       {
           QMessageBox::StandardButton reply = QMessageBox::question(this,"Warning", "Bạn chắc chắn với dịch vụ chứ", QMessageBox::Yes | QMessageBox::No);
           if(reply == QMessageBox::Yes)
           {
               QSqlQuery qry;
               qry.prepare("INSERT INTO Services "
                           "VALUES(?,?,?)");
               qry.bindValue(0, ma_dv);
               qry.bindValue(1, ten_dv);
               qry.bindValue(2, gia_dv);
               qry.exec();
               close();
            }
       }
   }
}

