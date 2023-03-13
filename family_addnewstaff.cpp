#include "family_addnewstaff.h"
#include "ui_family_addnewstaff.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>
family_addnewstaff::family_addnewstaff(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::family_addnewstaff)
{
    ui->setupUi(this);
    // set gt
    ui->comboBox_gt->addItem("Nam");
    ui->comboBox_gt->addItem("Nữ");

    // set calendar
    ui->comboBox_2->addItem("Sáng");
    ui->comboBox_2->addItem("Chiều");
    ui->comboBox_2->addItem("Nghỉ");

    ui->comboBox_3->addItem("Sáng");
    ui->comboBox_3->addItem("Chiều");
    ui->comboBox_3->addItem("Nghỉ");

    ui->comboBox_4->addItem("Sáng");
    ui->comboBox_4->addItem("Chiều");
    ui->comboBox_4->addItem("Nghỉ");

    ui->comboBox_5->addItem("Sáng");
    ui->comboBox_5->addItem("Chiều");
    ui->comboBox_5->addItem("Nghỉ");

    ui->comboBox_6->addItem("Sáng");
    ui->comboBox_6->addItem("Chiều");
    ui->comboBox_6->addItem("Nghỉ");

    ui->comboBox_7->addItem("Sáng");
    ui->comboBox_7->addItem("Chiều");
    ui->comboBox_7->addItem("Nghỉ");

    ui->comboBox_cn->addItem("Sáng");
    ui->comboBox_cn->addItem("Chiều");
    ui->comboBox_cn->addItem("Nghỉ");
}

family_addnewstaff::~family_addnewstaff()
{
    delete ui;
}

void family_addnewstaff::on_pushButton_clicked()
{
     bool check = true;
    // Thong tin
    QString ma_nhan_vien = ui->lineEdit_mnv->text();
    QString ho_va_ten = ui->lineEdit_hvt->text();
    QString gioi_tinh = ui->comboBox_gt->currentText();
    QString so_can_cuoc = ui->lineEdit_scc->text();
    QString chuc_vu = ui->lineEdit_cv->text();
    QString luong = ui->lineEdit_l->text();
    QString so_dien_thoai = ui->lineEdit_sdt->text();

    // Lich truc
    QString thu2 = ui->comboBox_2->currentText();
    QString thu3 = ui->comboBox_3->currentText();
    QString thu4 = ui->comboBox_4->currentText();
    QString thu5 = ui->comboBox_5->currentText();
    QString thu6 = ui->comboBox_6->currentText();
    QString thu7 = ui->comboBox_7->currentText();
    QString thucn = ui->comboBox_cn->currentText();

    if(ma_nhan_vien == "" || ho_va_ten == "" || so_can_cuoc =="" || chuc_vu == "" || luong == "" || so_dien_thoai == "")
    {
        QMessageBox::warning(this, "Warning", "Bạn cần điền đầy đủ thông tin");
    }
    else
    {
        QSqlQuery q("SELECT * FROM Staffs");
        QSqlRecord rec = q.record();
        int memIDCol = rec.indexOf("staff_ID");
        while(q.next())
        {
            if(ma_nhan_vien == q.value(memIDCol).toString())
            {
                QMessageBox::information(this, "Information", "Mã cá nhân này đã tồn tại");
                check = false;
                break;
            }
        }
        if(check)
        {
            QSqlQuery qr("SELECT * FROM Staffs");
            QSqlRecord rec = qr.record();
            int memIDCol = rec.indexOf("ID_Card");
            while(qr.next())
            {
                if(ma_nhan_vien == qr.value(memIDCol).toString())
                {
                    QMessageBox::information(this, "Information", "Số căn cước đã tồn tại");
                    check = false;
                    break;
                }
            }
            int x = 0;
            if(check)
            {
                QMessageBox::StandardButton reply = QMessageBox::question(this,"Warning", "Thông tin bạn nhập chính xác chứ", QMessageBox::Yes | QMessageBox::No);
                if(reply == QMessageBox::Yes)
                {
                    QSqlQuery query;
                    query.prepare("INSERT INTO Staffs "
                                  "VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)");
                    query.bindValue(0, ma_nhan_vien);
                    query.bindValue(1, ho_va_ten);
                    query.bindValue(2, gioi_tinh);
                    query.bindValue(3, so_can_cuoc);
                    query.bindValue(4, chuc_vu);
                    query.bindValue(5, luong);
                    query.bindValue(6, x);
                    query.bindValue(7, luong);
                    query.bindValue(8, so_dien_thoai);
                    query.bindValue(9, thu2);
                    query.bindValue(10, thu3);
                    query.bindValue(11, thu4);
                    query.bindValue(12, thu5);
                    query.bindValue(13, thu6);
                    query.bindValue(14, thu7);
                    query.bindValue(15, thucn);
                    query.exec();
                    close();
                }
            }
        }
     }
}
















































