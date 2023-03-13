#ifndef MANAGE_SERVICEBEBUY_H
#define MANAGE_SERVICEBEBUY_H

#include <QMainWindow>
#include <QSqlQueryModel>
namespace Ui {
class manage_servicebebuy;
}

class manage_servicebebuy : public QMainWindow
{
    Q_OBJECT

public:
    explicit manage_servicebebuy(QWidget *parent = nullptr);
    ~manage_servicebebuy();

private:
    Ui::manage_servicebebuy *ui;
    QSqlQueryModel *Model;
};

#endif // MANAGE_SERVICEBEBUY_H
