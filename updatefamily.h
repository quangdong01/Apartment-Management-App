#ifndef UPDATEFAMILY_H
#define UPDATEFAMILY_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include "deletefamily.h"
#include "searchtocomlement.h"
namespace Ui {
class updatefamily;
}

class updatefamily : public QMainWindow
{
    Q_OBJECT

public:
    explicit updatefamily(QWidget *parent = nullptr);
    ~updatefamily();

private slots:
    void on_btn_xhgd_clicked();

    void on_btn_ttv_clicked();

private:
    Ui::updatefamily *ui;
    QSqlQueryModel *mModel;
};

#endif // UPDATEFAMILY_H
