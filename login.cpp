#include "login.h"
#include "ui_login.h"
#include "choose_option_login.h"
#include <QDebug>
#include <QTime>


choose_option_login *re;

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    // Set statusbar with follow text
    ui->statusbar->showMessage("Copyright@ Embedded Networking Laboratory");

    // set time
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(my_function()));
    timer->start(1);
}

login::~login()
{
    delete ui;
}

void login::my_function()
{
    QTime time = QTime::currentTime();
    QString date_text = time.toString("hh:mm:ss");
    date_text += "  ";
    QDate Date = QDate::currentDate();
    int day = Date.day();
    date_text += QString::number(day);

    date_text += " Thg";
    int month = Date.month();
    date_text += QString::number(month);

    ui->label_Time->setText(date_text);
}

// Function kiểm tra tài khoản mật khẩu phải phù hợp với từng CSDL của từng đối tượng
void login::on_btn_Login_clicked()
{
    if(option == 1)
    {
        QString taikhoan = ui->lineEdit_Taikhoan->text();
        QString matkhau = ui->lineEdit_Matkhau->text();
        if(taikhoan == "1" && matkhau == "2")
        {
            close();
            fam = new::family;
            fam->setWindowTitle("CỔNG THÔNG TIN HỘ GIA ĐÌNH");
            fam->show();
        }
        else
        {
            QString text = "Thông tin của bạn không hợp lệ\n";
            text += "với vai trò hộ gia đình";
            QMessageBox::warning(this, "Cảnh Báo", text);
        }
    }
    else if(option == 2)
    {
        QString taikhoan = ui->lineEdit_Taikhoan->text();
        QString matkhau = ui->lineEdit_Matkhau->text();
        if(taikhoan == "11" && matkhau == "22")
        {
            close();
            staf = new::staff;
            staf->setWindowTitle("CỔNG THÔNG TIN NHÂN VIÊN");
            staf->show();
        }
        else
        {
            QString text = "Thông tin của bạn không hợp lệ\n";
            text += "với vai trò nhân viên";
            QMessageBox::warning(this, "Cảnh Báo", text);
        }
    }
    else if(option == 3)
    {
        QString taikhoan = ui->lineEdit_Taikhoan->text();
        QString matkhau = ui->lineEdit_Matkhau->text();
        if(taikhoan == "admin" && matkhau == "admin")
        {
            close();
            man = new::management;
            man->setWindowTitle("TRUNG TÂM QUẢN LÍ DỮ LIỆU");
            man->show();
        }
        else
        {
            QString text = "Thông tin của bạn không hợp lệ\n";
            text += "với vai trò quản lí";
            QMessageBox::warning(this, "Cảnh Báo", text);
        }
    }
    else
    {
        QMessageBox::warning(this, "Cảnh báo", "Thông tin không hợp lệ");
    }
}



// Function thông báo không được để trống tài khoản
void login::on_lineEdit_Taikhoan_cursorPositionChanged(int , int )
{
    if(ui->lineEdit_Taikhoan->text() != NULL)
    {
        ui->label_texttaikhoan->hide();
    }
    else
    {
        ui->label_texttaikhoan->show();
    }
}


// Function thông báo không được để trống mật khẩu
void login::on_lineEdit_Matkhau_cursorPositionChanged(int , int )
{
    if(ui->lineEdit_Matkhau->text() != NULL)
    {
        ui->label_textmatkhau->hide();
    }
    else
    {
        ui->label_textmatkhau->show();
    }
}





void login::on_btn_Return_clicked()
{
    close();
    re = new choose_option_login();
    re->setWindowTitle("CỔNG THÔNG TIN QUẢN LÍ DỊCH VỤ");
    re->show();
}

