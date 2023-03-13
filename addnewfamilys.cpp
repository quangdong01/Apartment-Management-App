#include "addnewfamilys.h"
#include "ui_addnewfamilys.h"
#include "enternewmember.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>
int Ma_ho_gia_dinh;
int So_thanh_vien;
addnewfamilys::addnewfamilys(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::addnewfamilys)
{
    ui->setupUi(this);
    ui->lineEdit_mhgd->setPlaceholderText("Mã hộ gia đình");
    ui->lineEdit_tp->setPlaceholderText("Tên phòng");
    ui->lineEdit_stv->setPlaceholderText("Số thành viên");
    ui->lineEdit_mhgd->setClearButtonEnabled(true);
    ui->lineEdit_stv->setClearButtonEnabled(true);
    ui->lineEdit_tp->setClearButtonEnabled(true);
}

addnewfamilys::~addnewfamilys()
{
    delete ui;
}

// function to create new family
void addnewfamilys::on_pushButton_clicked()
{
    // variable check if already existed
    bool trusted = false;
    // Catch value in lineEdit of each filed
    QString ma_ho_gia_dinh = ui->lineEdit_mhgd->text();
    QString ten_phong = ui->lineEdit_tp->text();
    QString so_thanh_vien = ui->lineEdit_stv->text();
    if(ma_ho_gia_dinh == "" || ten_phong == "" || so_thanh_vien == "")
    {
        QMessageBox::warning(this, "Warning", "Thông tin không được bỏ trống");
        trusted = true;
    }
    if(trusted == false)
    {
        // Create query
        QSqlQuery q("SELECT * FROM Familys");

        // Create record from query select
        QSqlRecord rec1 = q.record();
        int idFamilyCol = rec1.indexOf("family_ID"); // index of the field "name"
        while (q.next())
        {
            if(ma_ho_gia_dinh == q.value(idFamilyCol).toString())
            {
                QMessageBox::warning(this, "Warning", "Mã hộ gia đình đã xuất hiện");
                trusted = true;
                break;
            }
            // output all names
        }
        if(trusted == false)
        {
            QSqlQuery p("SELECT * FROM Familys");
            // continue check roomNumber
            QSqlRecord rec2 = p.record();
            int roomNameCol = rec2.indexOf("room_Name"); // index of the field "name"
            while (p.next())
            {
                if(ten_phong == p.value(roomNameCol).toString())
                {
                    QMessageBox::warning(this, "Warning", "Phòng đã có gia đình ở");
                    trusted = true;
                    break;
                }
                // output all names
            }
         }
    }
    if(trusted == false)
    {
        Ma_ho_gia_dinh = ma_ho_gia_dinh.toInt();
        So_thanh_vien = so_thanh_vien.toInt();
        QSqlQuery qry;
        qry.prepare("INSERT INTO Familys "
                    "VALUES(?,?,?)");
        qry.bindValue(0, ma_ho_gia_dinh);
        qry.bindValue(1, ten_phong);
        qry.bindValue(2, so_thanh_vien);
        qry.exec();

        QSqlQuery qq;
        qq.prepare("INSERT INTO ServicePayment "
                   "VALUES(?,?,?,?)");
        qq.bindValue(0, ma_ho_gia_dinh);
        qq.bindValue(1, ten_phong);
        qq.bindValue(2, 100000);
        qq.bindValue(3, 0);
        qq.exec();

        // setText to return original state
        ui->lineEdit_mhgd->setText("");
        ui->lineEdit_tp->setText("");
        ui->lineEdit_stv->setText("");


        for(int i = 0; i < So_thanh_vien; i++)
        {
            enternewmember *newm = new enternewmember();
            newm->setWindowTitle(QString("Nhập thành viên thứ %1").arg(So_thanh_vien-i));
            newm->show();
        }
    }
}

