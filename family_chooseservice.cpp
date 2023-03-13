#include "family_chooseservice.h"
#include "ui_family_chooseservice.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>
#include "login.h"
#include <QDebug>
#include <QDate>
QString Ma_giao_dich;
QString Ngay_giao_dich;
QString Ten_dich_vu;
QString Gia_dich_vu;
family_chooseservice::family_chooseservice(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::family_chooseservice)
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

family_chooseservice::~family_chooseservice()
{
    delete ui;
}

void family_chooseservice::on_btn_ok_clicked()
{
    bool check = true;
    QString ma_dich_vu = ui->lineEdit_mdv->text();
    int mdv = ma_dich_vu.toInt();
    if(ma_dich_vu == "")
    {
        QMessageBox::information(this, "Warning", "Mã dịch vụ không tồn tại");
    }
    else
    {
        QSqlQuery q("SELECT * FROM Services");
        QSqlRecord rec = q.record();
        int serCol = rec.indexOf("service_ID");
        while(q.next())
        {
            if(mdv == q.value(serCol).toInt())
            {
                check = false;
                break;
            }
        }

        if(check == false)
        {
            QMessageBox::StandardButton reply = QMessageBox::question(this,"Warning", "Thông tin bạn nhập chính xác chứ", QMessageBox::Yes | QMessageBox::No);
            if(reply == QMessageBox::Yes)
            {
                // show option to confirm
                QMessageBox::information(this, "Thông báo", "Đã xác nhận dịch vụ. Hãy để ý điện thoại");

                // get value of service_Cost
                QSqlQuery q1(QString("SELECT * FROM Services WHERE service_ID=%1").arg(mdv));
                QSqlRecord rec;
                rec = q1.record();
                int numberCol = rec.indexOf("service_Cost");
                int ma_dv = 0;

                // variable ma dat dich vu
                int ma_datdv = MHGD.toInt();

                // Check for duplicate
                QuangDong:
                {
                    QSqlQuery q2("SELECT * FROM Orders");
                    QSqlRecord Rec = q2.record();
                    int mddvCol = Rec.indexOf("order_ID");
                    while(q2.next())
                    {
                        if(ma_datdv == q2.value(mddvCol).toInt())
                        {
                            ma_datdv++;
                            goto QuangDong;
                        }
                    }
                }
                // Save to billpay
                Ma_giao_dich = QString("%1").arg(ma_datdv);
                // variable ma dich vu
                int order_madv = mdv;

                // variable name dich vu
                QString name_dv;
                QSqlQuery q3(QString("SELECT * FROM Services WHERE service_ID=%1").arg(mdv));
                QSqlRecord rec2;
                rec2 = q3.record();
                int Coll = rec2.indexOf("service_Name");
                while(q3.next())
                {
                    name_dv = q3.value(Coll).toString();
                    break;
                }

                // Save to billpay
                Ten_dich_vu = name_dv;

                //variable service name
                int gia_dv = 0;
                QSqlQuery q4(QString("SELECT * FROM Services WHERE service_ID=%1").arg(mdv));
                QSqlRecord rec3;
                rec3 = q4.record();
                int Colll = rec2.indexOf("service_Cost");
                while(q4.next())
                {
                    gia_dv = q4.value(Colll).toInt();
                    break;
                }

                Gia_dich_vu = QString("%1").arg(gia_dv);
                // variable Date
                QDate order_Day = QDate::currentDate();
                QString Order_day = order_Day.toString();

                // Save to billpay
                Ngay_giao_dich = Order_day;

                // Push data to Orders table in sql server
                QSqlQuery qqry;
                qqry.prepare("INSERT INTO Orders "
                             "VALUES(?,?,?,?,?,?)");
                qqry.bindValue(0, ma_datdv);
                qqry.bindValue(1, order_madv);
                qqry.bindValue(2, name_dv);
                qqry.bindValue(3, gia_dv);
                qqry.bindValue(4, Order_day);
                qqry.bindValue(5, MHGD);
                qqry.exec();


                while(q1.next())
                {
                    ma_dv = q1.value(numberCol).toInt();             
                    break;
                }

                // get value of Sum_service
                QSqlQuery qqq(QString("SELECT * FROM ServicePayment WHERE family_ID=%1").arg(MHGD));
                QSqlRecord rec1;
                rec1 = qqq.record();
                int Col = rec1.indexOf("service_Payment");
                int serpay = 0;
                while(qqq.next())
                {
                    serpay = qqq.value(Col).toInt();
                    break;
                }

                // increase Sum of service;
                serpay = serpay + ma_dv;

                // Updata data
                QSqlQuery qrr;
                qrr.prepare("UPDATE ServicePayment "
                          "SET service_Payment=? "
                          "WHERE family_ID=?");
                qrr.bindValue(0, serpay);
                qrr.bindValue(1, MHGD);
                qrr.exec();

                family_billpay *fambi = new family_billpay();
                fambi->setWindowTitle("Hóa đơn của bạn");
                fambi->show();
                close();
            }
        }
        else
        {
            QMessageBox::warning(this, "Warning", "Mã dịch vụ không tồn tại");
        }
    }
}

