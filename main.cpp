#include "choose_option_login.h"
#include <QApplication>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    choose_option_login w;
    w.setWindowTitle("CỔNG THÔNG TIN QUẢN LÍ DỊCH VỤ");
    w.show();

    return a.exec();
}
