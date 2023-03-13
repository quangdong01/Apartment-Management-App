#ifndef FAMILY_SERVICEBUY_H
#define FAMILY_SERVICEBUY_H

#include <QMainWindow>
#include <QSqlQueryModel>
namespace Ui {
class family_servicebuy;
}

class family_servicebuy : public QMainWindow
{
    Q_OBJECT

public:
    explicit family_servicebuy(QWidget *parent = nullptr);
    ~family_servicebuy();

private:
    Ui::family_servicebuy *ui;
    QSqlQueryModel *Model;
};

#endif // FAMILY_SERVICEBUY_H
