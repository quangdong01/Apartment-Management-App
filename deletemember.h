#ifndef DELETEMEMBER_H
#define DELETEMEMBER_H

#include <QMainWindow>
#include <QSqlQueryModel>
namespace Ui {
class deletemember;
}

class deletemember : public QMainWindow
{
    Q_OBJECT

public:
    explicit deletemember(QWidget *parent = nullptr);
    ~deletemember();

private slots:
    void on_btn_x_clicked();

private:
    Ui::deletemember *ui;
    QSqlQueryModel * model;
};

#endif // DELETEMEMBER_H
