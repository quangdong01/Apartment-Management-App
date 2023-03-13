#include "family_billpay.h"
#include "ui_family_billpay.h"
#include "family_chooseservice.h"
family_billpay::family_billpay(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::family_billpay)
{
    ui->setupUi(this);
    ui->label_mgd->setText(Ma_giao_dich);
    ui->label_ni->setText(Ngay_giao_dich);
    ui->label_tdv->setText(Ten_dich_vu);
    ui->label_g->setText(Gia_dich_vu);
}

family_billpay::~family_billpay()
{
    delete ui;
}
