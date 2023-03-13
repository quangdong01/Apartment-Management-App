#include "deletemember.h"
#include "ui_deletemember.h"
#include "searchtocomlement.h"
#include <seachtocomplement_addordel.h>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>
deletemember::deletemember(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::deletemember)
{
    ui->setupUi(this);
    model = nullptr;
    if(model == nullptr)
    {
        model = new QSqlQueryModel(this);
        model->setQuery(QString("SELECT member_ID, fullName, data_Of_Birth, sex, ID_Card, address FROM Members WHERE family_ID=%1").arg(mhgd));
        ui->tableView_tv->setModel(model);
    }
    else
    {
        model->setQuery(QString("SELECT member_ID, fullName, data_Of_Birth, sex, ID_Card, address FROM Members WHERE family_ID=%1").arg(mhgd));
    }
}

deletemember::~deletemember()
{
    delete ui;
}

void deletemember::on_btn_x_clicked()
{
    bool check = true;
    QString ma_ca_nhan = ui->lineEdit_mcn->text();

    QSqlQuery q(QString("SELECT * FROM Members WHERE family_ID=%1").arg(mhgd));
    QSqlRecord rec = q.record();
    int memCol = rec.indexOf("member_ID");
    while(q.next())
    {
        if(ma_ca_nhan == q.value(memCol).toString())
        {
            check = false;
            break;
        }
    }
    if(check)
    {
        QMessageBox::warning(this, "Warning", "Mã cá nhân không tồn tại");
    }
    else
    {
        QSqlQuery qry;
        qry.prepare("DELETE FROM Members WHERE member_ID=?");
        qry.bindValue(0, ma_ca_nhan);
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
        num2--;
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

