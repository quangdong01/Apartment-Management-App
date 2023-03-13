#ifndef MANAGE_DELSERVICE_H
#define MANAGE_DELSERVICE_H

#include <QMainWindow>
#include <QSqlQueryModel>
namespace Ui {
class manage_delservice;
}

class manage_delservice : public QMainWindow
{
    Q_OBJECT

public:
    explicit manage_delservice(QWidget *parent = nullptr);
    ~manage_delservice();

private slots:
    void on_btn_x_clicked();

private:
    Ui::manage_delservice *ui;
    QSqlQueryModel *Model;
};

#endif // MANAGE_DELSERVICE_H
