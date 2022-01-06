#include "management.h"
#include "ui_management.h"
#include "choose_option_login.h"
#include <QDateTime>
choose_option_login *ma;
management::management(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::management)
{
    ui->setupUi(this);
    // Set time for Window
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(my_function()));
    timer->start(1);

    // Set statusbar with follow text
    ui->statusbar->showMessage("Copyright@ Embedded Networking Laboratory");
}

management::~management()
{
    delete ui;
}

void management::my_function()
{
    QTime time = QTime::currentTime();
    QString date_text = time.toString("hh:mm:ss");
    date_text += "  ";
    QDate Date = QDate::currentDate();
    int day = Date.day();
    date_text += QString::number(day);

    date_text += " Thg";
    int month = Date.month();
    date_text += QString::number(month);

    ui->label_Time->setText(date_text);
}

void management::on_action_ng_xu_t_triggered()
{
    close();
    ma = new choose_option_login(this);
    ma->setWindowTitle("CỔNG THÔNG TIN QUẢN LÍ DỊCH VỤ");
    ma->show();
}

