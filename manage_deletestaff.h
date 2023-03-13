#ifndef MANAGE_DELETESTAFF_H
#define MANAGE_DELETESTAFF_H

#include <QMainWindow>
#include <QSqlQueryModel>
namespace Ui {
class manage_deletestaff;
}

class manage_deletestaff : public QMainWindow
{
    Q_OBJECT

public:
    explicit manage_deletestaff(QWidget *parent = nullptr);
    ~manage_deletestaff();

private slots:
    void on_btn_x_clicked();

private:
    Ui::manage_deletestaff *ui;
    QSqlQueryModel *mmModel;
};

#endif // MANAGE_DELETESTAFF_H
