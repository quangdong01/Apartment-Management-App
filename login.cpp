#include "login.h"
#include "ui_login.h"
#include "choose_option_login.h"
#include <QDebug>
#include <QTime>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>
QString MHGD;
QString MNV;

choose_option_login *re;

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    ui->lineEdit_Taikhoan->setPlaceholderText("Tài khoản");
    ui->lineEdit_Matkhau->setPlaceholderText("Mật khẩu");
    ui->lineEdit_Taikhoan->setClearButtonEnabled(true);
    ui->lineEdit_Matkhau->setClearButtonEnabled(true);
    // Set statusbar with follow text
    ui->statusbar->showMessage("Copyright@ Hanoi University of Science and Technology");

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
    // Sign in with family
    if(option == 1)
    {
        bool check = true;
        QString taikhoan = ui->lineEdit_Taikhoan->text();
        QString matkhau = ui->lineEdit_Matkhau->text();

        if(taikhoan == "" || matkhau == "")
        {
            QMessageBox::information(this, "Information", "Không được để trống");
        }
        else
        {
            QSqlQuery q("SELECT * FROM Members");
            QSqlRecord rec = q.record();
            int famID = rec.indexOf("member_ID");
            while(q.next())
            {
                if(taikhoan == q.value(famID).toString())
                {
                    check = false;
                    break;
                }
            }
            if(check == false)
            {
                QSqlQuery q1(QString("SELECT * FROM Members WHERE member_ID=%1").arg(taikhoan));
                QSqlRecord rec1;
                rec1 = q1.record();
                int numberCol = rec1.indexOf("ID_Card");
                QString num1;
                while(q1.next())
                {
                    num1 = q1.value(numberCol).toString();
                    break;
                }
                if(matkhau == num1)
                {
                    QSqlQuery q1(QString("SELECT * FROM Members WHERE member_ID=%1").arg(taikhoan));
                    QSqlRecord rec;
                    rec = q1.record();
                    int numberCol = rec.indexOf("family_ID");
                    QString num1;
                    while(q1.next())
                    {
                        num1 = q1.value(numberCol).toString();
                        break;
                    }
                    close();
                    MHGD = num1;
                    fam = new::family;
                    fam->setWindowTitle("Cổng thông tin nhân viên");
                    fam->show();
                }
                else
                {
                    QMessageBox::warning(this, "Warning", "Tài khoản hoặc mật khẩu không đúng");
                }
            }
            else
            {
                QMessageBox::warning(this, "Warning", "Tài khoản hoặc mật khẩu không đúng");
            }
        }
    }

    // Sign in with staff
    else if(option == 2)
    {
        bool check = true;
        QString taikhoan = ui->lineEdit_Taikhoan->text();
        QString matkhau = ui->lineEdit_Matkhau->text();
        if(taikhoan == "" || matkhau == "")
        {
            QMessageBox::information(this, "Information", "Không được để trống");
        }
        else
        {
            QSqlQuery q("SELECT * FROM Staffs");
            QSqlRecord rec = q.record();
            int famID = rec.indexOf("staff_ID");
            while(q.next())
            {
                if(taikhoan == q.value(famID).toString())
                {
                    check = false;
                    break;
                }
            }
            if(check == false)
            {
                QSqlQuery q1(QString("SELECT * FROM Staffs WHERE staff_ID=%1").arg(taikhoan));
                QSqlRecord rec1;
                rec1 = q1.record();
                int numberCol = rec1.indexOf("ID_Card");
                QString num1;
                while(q1.next())
                {
                    num1 = q1.value(numberCol).toString();
                    break;
                }
                if(matkhau == num1)
                {
                    close();
                    MNV = taikhoan;
                    staf = new::staff;
                    staf->setWindowTitle("Cổng thông tin hộ gia đình ");
                    staf->show();
                }
                else
                {
                    QMessageBox::warning(this, "Warning", "Tài khoản hoặc mật khẩu không đúng");
                }
            }
            else
            {
                QMessageBox::warning(this, "Warning", "Tài khoản hoặc mật khẩu không đúng");
            }
        }
    }

    // Sign up with manage
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

