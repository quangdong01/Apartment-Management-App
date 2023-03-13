#ifndef SEACHTOCOMPLEMENT_ADDORDEL_H
#define SEACHTOCOMPLEMENT_ADDORDEL_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include "family_complementaddnew.h"
#include "deletemember.h"
namespace Ui {
class seachtocomplement_addordel;
}

class seachtocomplement_addordel : public QMainWindow
{
    Q_OBJECT

public:
    explicit seachtocomplement_addordel(QWidget *parent = nullptr);
    ~seachtocomplement_addordel();

private slots:
    void on_btn_ttv_clicked();

    void on_btn_xtt_clicked();

private:
    Ui::seachtocomplement_addordel *ui;
    QSqlQueryModel *modell;
};

#endif // SEACHTOCOMPLEMENT_ADDORDEL_H
