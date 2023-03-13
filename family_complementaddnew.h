#ifndef FAMILY_COMPLEMENTADDNEW_H
#define FAMILY_COMPLEMENTADDNEW_H

#include <QMainWindow>
#include <QSqlQueryModel>
namespace Ui {
class family_complementaddnew;
}

class family_complementaddnew : public QMainWindow
{
    Q_OBJECT

public:
    explicit family_complementaddnew(QWidget *parent = nullptr);
    ~family_complementaddnew();

private slots:
    void on_pushButton_clicked();

private:
    Ui::family_complementaddnew *ui;
    QSqlQueryModel *Model;
};

#endif // FAMILY_COMPLEMENTADDNEW_H
