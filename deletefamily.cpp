#include "deletefamily.h"
#include "ui_deletefamily.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>
#include "updatefamily.h"
deletefamily::deletefamily(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::deletefamily)
{
    ui->setupUi(this);
    mModel = nullptr;
    if(mModel == nullptr)
    {
        mModel = new QSqlQueryModel(this);
        mModel->setQuery("SELECT * FROM Familys");
        ui->tableView_dshgd->setModel(mModel);
    }
    else
    {
        mModel->setQuery("SELECT * FROM Familys");
    }
    ui->lineEdit_mhgd->setClearButtonEnabled(true);
    ui->lineEdit_mhgd->setPlaceholderText("Mã hộ gia đình");
}

deletefamily::~deletefamily()
{
    delete ui;
}

void deletefamily::on_btn_x_clicked()
{
    int check = 0;
    QString mhgd = ui->lineEdit_mhgd->text();
    QSqlQuery query("SELECT * FROM Familys");
    QSqlRecord rec = query.record();
    int familyIDCol = rec.indexOf("family_ID");

    while (query.next())
    {
        if(mhgd == query.value(familyIDCol).toString())
        {
            QMessageBox::StandardButton reply = QMessageBox::question(this,"Warning", "Bạn không hối hận chứ", QMessageBox::Yes | QMessageBox::No);
            if(reply == QMessageBox::Yes)
            {
                // Delete from Members table
                QSqlQuery qry;
                qry.prepare("DELETE FROM Members WHERE family_ID=:id2");
                qry.bindValue(":id2", mhgd);
                qry.exec();


                // Delete from Familys table
                QSqlQuery q;
                q.prepare("DELETE FROM Familys WHERE family_ID=:id1");
                q.bindValue(":id1", mhgd);
                q.exec();


                QSqlQuery query;
                query.prepare("DELETE FROM ServicePayment WHERE family_ID=:id3");
                query.bindValue(":id3", mhgd);
                query.exec();

                check = 1;
                close();
                updatefamily *upda = new updatefamily();
                upda->setWindowTitle("Cập nhật thông tin hộ gia đình");
                upda->show();
            }
            else
            {
                check = 2;
            }
            break;
        }
    }
    if(check == 0)
    {
        QMessageBox::warning(this, "Warning", "Mã hộ gia đình không tồn tại");
    }
}

