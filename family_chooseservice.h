#ifndef FAMILY_CHOOSESERVICE_H
#define FAMILY_CHOOSESERVICE_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include "family_billpay.h"
extern QString Ma_giao_dich;
extern QString Ngay_giao_dich;
extern QString Ten_dich_vu;
extern QString Gia_dich_vu;
namespace Ui {
class family_chooseservice;
}

class family_chooseservice : public QMainWindow
{
    Q_OBJECT

public:
    explicit family_chooseservice(QWidget *parent = nullptr);
    ~family_chooseservice();

private slots:
    void on_btn_ok_clicked();

private:
    Ui::family_chooseservice *ui;
    QSqlQueryModel *Model;
};

#endif // FAMILY_CHOOSESERVICE_H
