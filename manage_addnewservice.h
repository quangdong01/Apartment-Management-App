#ifndef MANAGE_ADDNEWSERVICE_H
#define MANAGE_ADDNEWSERVICE_H

#include <QMainWindow>

namespace Ui {
class manage_addnewservice;
}

class manage_addnewservice : public QMainWindow
{
    Q_OBJECT

public:
    explicit manage_addnewservice(QWidget *parent = nullptr);
    ~manage_addnewservice();

private slots:
    void on_pushButton_clicked();

private:
    Ui::manage_addnewservice *ui;
};

#endif // MANAGE_ADDNEWSERVICE_H
