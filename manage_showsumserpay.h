#ifndef MANAGE_SHOWSUMSERPAY_H
#define MANAGE_SHOWSUMSERPAY_H

#include <QMainWindow>
#include <QSqlQueryModel>
namespace Ui {
class manage_showsumserpay;
}

class manage_showsumserpay : public QMainWindow
{
    Q_OBJECT

public:
    explicit manage_showsumserpay(QWidget *parent = nullptr);
    ~manage_showsumserpay();

private:
    Ui::manage_showsumserpay *ui;
    QSqlQueryModel *Model;
};

#endif // MANAGE_SHOWSUMSERPAY_H
