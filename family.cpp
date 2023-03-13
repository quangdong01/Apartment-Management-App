#include "family.h"
#include "ui_family.h"
#include <QDateTime>
#include "choose_option_login.h"

choose_option_login *fa;

family::family(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::family)
{
    ui->setupUi(this);

    // Set time for Window
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(my_function()));
    timer->start(1);

    // Set statusbar with follow text
   ui->statusbar->showMessage("Copyright@ Hanoi University of Science and Technology");
}

// to set time
void family::my_function()
{
    QTime time = QTime::currentTime();
    QString date_text = time.toString("hh:mm:ss");
    date_text += "  ";
    QDate Date = QDate::currentDate();
    int day = Date.day();
    date_text += QString::number(day);

    date_text += " Thg ";
    int month = Date.month();
    date_text += QString::number(month);

    ui->label_time->setText(date_text);
}

family::~family()
{
    delete ui;
}


// Return the window to option login method

void family::on_actionTho_t_triggered()
{
    close();
    fa = new choose_option_login(this);
    fa->setWindowTitle("CỔNG THÔNG TIN QUẢN LÍ DỊCH VỤ");
    fa->show();
}


void family::on_actionXem_h_s_triggered()
{
    family_showinf4 *fam = new family_showinf4();
    fam->setWindowTitle("Thông tin thành viên gia đình bạn");
    fam->show();
}


void family::on_actionD_ch_v_triggered()
{
    family_chooseservice *famch = new family_chooseservice();
    famch->setWindowTitle("Dịch vụ của bạn");
    famch->show();
}


void family::on_actionTh_ng_tin_d_ch_v_th_ng_n_y_triggered()
{
    family_servicebuy *famser = new family_servicebuy();
    famser->setWindowTitle("Dịch vụ đã sử dụng");
    famser->show();
}

