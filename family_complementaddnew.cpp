#include "family_complementaddnew.h"
#include "ui_family_complementaddnew.h"
#include <searchtocomlement.h>
#include <seachtocomplement_addordel.h>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
family_complementaddnew::family_complementaddnew(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::family_complementaddnew)
{
    ui->setupUi(this);
    // Add option sex
    ui->comboBox_gt->addItem("Nam");
    ui->comboBox_gt->addItem("Nữ");

    // Add option dc
    ui->comboBox_dc->addItem("An Giang");
    ui->comboBox_dc->addItem("Bà Rịa - Vũng Tàu");
    ui->comboBox_dc->addItem("Bắc Giang");
    ui->comboBox_dc->addItem("Bắc Kạn");
    ui->comboBox_dc->addItem("Bạc Liêu");
    ui->comboBox_dc->addItem("Bắc Ninh");
    ui->comboBox_dc->addItem("Bến Tre");
    ui->comboBox_dc->addItem("Bình Định");
    ui->comboBox_dc->addItem("Bình Dương");
    ui->comboBox_dc->addItem("Bình Phước");
    ui->comboBox_dc->addItem("Bình Thuận");
    ui->comboBox_dc->addItem("Cà Mau");
    ui->comboBox_dc->addItem("Cao Bằng");
    ui->comboBox_dc->addItem("Đắk Lắk");
    ui->comboBox_dc->addItem("Đắk Nông");
    ui->comboBox_dc->addItem("Điện Biên");
    ui->comboBox_dc->addItem("Đồng Nai");
    ui->comboBox_dc->addItem("Đồng Tháp");
    ui->comboBox_dc->addItem("Gia Lai");
    ui->comboBox_dc->addItem("Hà Giang");
    ui->comboBox_dc->addItem("Hà Nam");
    ui->comboBox_dc->addItem("Hà Tĩnh");
    ui->comboBox_dc->addItem("Hải Dương");
    ui->comboBox_dc->addItem("Hậu Giang");
    ui->comboBox_dc->addItem("Hòa Bình");
    ui->comboBox_dc->addItem("Hưng Yên");
    ui->comboBox_dc->addItem("Khánh Hòa");
    ui->comboBox_dc->addItem("Kiên Giang");
    ui->comboBox_dc->addItem("Kon Tum");
    ui->comboBox_dc->addItem("Lai Châu");
    ui->comboBox_dc->addItem("Lâm Đồng");
    ui->comboBox_dc->addItem("Lạng Sơn");
    ui->comboBox_dc->addItem("Lào Cai");
    ui->comboBox_dc->addItem("Long An");
    ui->comboBox_dc->addItem("Nam Định");
    ui->comboBox_dc->addItem("Ninh Bình");
    ui->comboBox_dc->addItem("Ninh Thuận");
    ui->comboBox_dc->addItem("Phú Thọ");
    ui->comboBox_dc->addItem("Quảng Bình");
    ui->comboBox_dc->addItem("Quảng Nam");
    ui->comboBox_dc->addItem("Quảng Ngãi");
    ui->comboBox_dc->addItem("Quảng Ninh");
    ui->comboBox_dc->addItem("Quảng Trị");
    ui->comboBox_dc->addItem("Sóc Trăng");
    ui->comboBox_dc->addItem("Sơn La");
    ui->comboBox_dc->addItem("Tây Ninh");
    ui->comboBox_dc->addItem("Thái Bình");
    ui->comboBox_dc->addItem("Thái Nguyên");
    ui->comboBox_dc->addItem("Thừa Thiên Huế");
    ui->comboBox_dc->addItem("Tiền Giang");
    ui->comboBox_dc->addItem("Trà Vinh");
    ui->comboBox_dc->addItem("Tuyên Quang");
    ui->comboBox_dc->addItem("Vĩnh Long");
    ui->comboBox_dc->addItem("Vĩnh Phúc");
    ui->comboBox_dc->addItem("Yên Bái");
    ui->comboBox_dc->addItem("Phú Yên");
    ui->comboBox_dc->addItem("Cần Thơ");
    ui->comboBox_dc->addItem("Đà Nẵng");
    ui->comboBox_dc->addItem("Hải Phòng");
    ui->comboBox_dc->addItem("Hà Nội");
    ui->comboBox_dc->addItem("TP HCM");
    Model = nullptr;
    if(Model == nullptr)
    {
        Model = new QSqlQueryModel(this);
        Model->setQuery(QString("SELECT member_ID, fullName, data_Of_Birth, sex, ID_Card, address FROM Members WHERE family_ID=%1").arg(mhgd));
        ui->tableView_tvgd->setModel(Model);
    }
    else
    {
        Model->setQuery(QString("SELECT member_ID, fullName, data_Of_Birth, sex, ID_Card, address FROM Members WHERE family_ID=%1").arg(mhgd));
    }
}

family_complementaddnew::~family_complementaddnew()
{
    delete ui;
}

void family_complementaddnew::on_pushButton_clicked()
{

        bool check = true;
        QString ma_ca_nhan = ui->lineEdit_mcn->text();
        QString ho_va_ten = ui->lineEdit_hvt->text();
        QString ngay_sinh = ui->lineEdit_ns->text();
        QString so_cmnd = ui->lineEdit_scmnd->text();
        QString gioi_tinh = ui->comboBox_gt->currentText();
        QString dia_chi = ui->comboBox_dc->currentText();

        if(ma_ca_nhan == "" || ho_va_ten == "" || ngay_sinh == "" || so_cmnd == "" || gioi_tinh == "" || dia_chi == "")
        {
            QMessageBox::warning(this, "Warning", "Bạn cần nhập đủ thông tin");
        }
        else
        {
            QSqlQuery q("SELECT member_ID FROM Members");
            QSqlRecord rec = q.record();
            int memIDCol = rec.indexOf("member_ID");
            while(q.next())
            {
                if(ma_ca_nhan == q.value(memIDCol).toString())
                {
                    QMessageBox::information(this, "Information", "Mã cá nhân này đã tồn tại");
                    check = false;
                    break;
                }
            }
        }
        if(check)
        {
            // Add new member
            QSqlQuery qry;
            qry.prepare("INSERT INTO Members"
                        " VALUES(?,?,?,?,?,?,?)");
            qry.bindValue(0, ma_ca_nhan);
            qry.bindValue(1, ho_va_ten);
            qry.bindValue(2, ngay_sinh);
            qry.bindValue(3, gioi_tinh);
            qry.bindValue(4, so_cmnd);
            qry.bindValue(5, dia_chi);
            qry.bindValue(6, mhgd);
            qry.exec();

            QSqlQuery q(QString("SELECT * FROM Familys WHERE family_ID=%1").arg(mhgd));
            QSqlRecord rec;
            rec = q.record();
            int numberCol = rec.indexOf("member_Number");
            QString num1;
            while(q.next())
            {
                num1 = q.value(numberCol).toString();
                break;
            }
            int num2 = num1.toInt();
            num2++;
            QString number_mem = QString("%1").arg(num2);
            QSqlQuery qrr;
            qrr.prepare("UPDATE Familys "
                      "SET member_Number=? "
                      "WHERE family_ID=?");
            qrr.bindValue(0, number_mem);
            qrr.bindValue(1, mhgd);
            qrr.exec();
            close();
            seachtocomplement_addordel *see = new seachtocomplement_addordel();
            see->setWindowTitle("Cập nhật thành viên");
            see->show();
        }
}

