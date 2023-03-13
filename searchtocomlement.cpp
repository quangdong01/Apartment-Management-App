#include "searchtocomlement.h"
#include "ui_searchtocomlement.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>
#include "seachtocomplement_addordel.h"
QString mhgd;
searchtocomlement::searchtocomlement(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::searchtocomlement)
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
}

searchtocomlement::~searchtocomlement()
{
    delete ui;
}

void searchtocomlement::on_btn_tt_clicked()
{
    uint16_t check = 0;
    QString ma_Ho_gia_dinh = ui->lineEdit_mhgd->text();
    QSqlQuery q("SELECT * FROM Familys");
    QSqlRecord rec = q.record();
    int IDfamilyCol = rec.indexOf("family_ID");
    while(q.next())
    {
        if(ma_Ho_gia_dinh == q.value(IDfamilyCol).toString())
        {
            QMessageBox::StandardButton reply = QMessageBox::question(this,"Warning", "Bạn không hối hận chứ", QMessageBox::Yes | QMessageBox::No);
            if(reply == QMessageBox::Yes)
            {
                mhgd = ma_Ho_gia_dinh;
                close();
                seachtocomplement_addordel *seach = new seachtocomplement_addordel();
                seach->setWindowTitle("Cập nhật thành viên");
                seach->show();
                check = 1;
                break;
            }
            else
            {
                check = 2;
            }
        }
    }
    if(check == 0)
    {
        QMessageBox::warning(this, "Warning", "Mã hộ gia đình không tồn tại");
    }
}

