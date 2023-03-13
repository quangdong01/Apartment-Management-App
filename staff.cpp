#include "staff.h"
#include "ui_staff.h"
#include "choose_option_login.h"
#include <QDateTime>
choose_option_login *sta;

staff::staff(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::staff)
{
    ui->setupUi(this);
    // Set time for Window
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(my_function()));
    timer->start(1);

    // Set statusbar with follow text
   ui->statusbar->showMessage("Copyright@ Hanoi University of Science and Technology");
}

staff::~staff()
{
    delete ui;
}

void staff::my_function()
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

    ui->label_time->setText(date_text);
}

void staff::on_actionTho_t_triggered()
{
    close();
    sta = new choose_option_login(this);
    sta->setWindowTitle("CỔNG THÔNG TIN QUẢN LÍ DỊCH VỤ");
    sta->show();
}


void staff::on_actionXem_h_s_triggered()
{
    staff_showinf4 *staffs = new staff_showinf4();
    staffs->setWindowTitle("Hồ sơ nhân viên");
    staffs->show();
}


void staff::on_actionL_ch_tr_c_triggered()
{
    staff_showcalendar *stasho = new staff_showcalendar();
    stasho->setWindowTitle("Lịch trực nhân viên");
    stasho->show();
}

