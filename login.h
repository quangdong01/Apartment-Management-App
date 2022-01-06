#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "family.h"
#include "staff.h"
#include "management.h"
#include <QMessageBox>

namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_btn_Login_clicked();

    void on_lineEdit_Taikhoan_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_Matkhau_cursorPositionChanged(int arg1, int arg2);


    void on_btn_Return_clicked();

public slots:
    void my_function();
private:
    Ui::login *ui;
    QTimer *timer;
    family *fam;
    staff *staf;
    management *man;

};

#endif // LOGIN_H
