#include "enternewmember.h"
#include "ui_enternewmember.h"
#include "addnewfamilys.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>
enternewmember::enternewmember(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::enternewmember)
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
}

enternewmember::~enternewmember()
{
    delete ui;
}

void enternewmember::on_pushButton_clicked()
{
    bool check = true;
    QString ma_ca_nhan = ui->lineEdit_mcn->text();
    QString ho_va_ten = ui->lineEdit_hvt->text();
    QString ngay_sinh = ui->lineEdit_ns->text();
    QString so_cmnd = ui->lineEdit_scmnd->text();
    QString gioi_tinh = ui->comboBox_gt->currentText();
    QString dia_chi = ui->comboBox_dc->currentText();

    // Check for sufficent inf4?
    if(ma_ca_nhan == "" || ho_va_ten == "" || ngay_sinh == "" || so_cmnd == "" || gioi_tinh == "" || dia_chi == "")
    {
        QMessageBox::warning(this, "Warning", "Bạn cần phải nhập đủ thông tin");
        check = false;
    }

    // Check first
    if(check)
    {
        QSqlQuery qq("SELECT member_ID FROM Members");

        // Create record from query select
        QSqlRecord rec1 = qq.record();
        int idMemberCol = rec1.indexOf("member_ID"); // index of the field "name"
        while (qq.next())
        {
            if(ma_ca_nhan == qq.value(idMemberCol).toString())
            {
                QMessageBox::warning(this, "Warning", "Mã cá nhân đã tồn tại");
                check = false;
                break;
            }
        }
    }

    // Check second
    if(check)
    {
        QSqlQuery query;
        query.prepare("INSERT INTO Members "
                      "VALUES(?,?,?,?,?,?,?)");
        query.bindValue(0, ma_ca_nhan);
        query.bindValue(1, ho_va_ten);
        query.bindValue(2, ngay_sinh);
        query.bindValue(3, gioi_tinh);
        query.bindValue(4, so_cmnd);
        query.bindValue(5, dia_chi);
        query.bindValue(6, Ma_ho_gia_dinh);
        query.exec();
        close();
    }
}

