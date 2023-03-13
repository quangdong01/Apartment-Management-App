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
    ui->statusbar->showMessage("Copyright@ Hanoi University of Science and Technology");
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

// function handle trigger Show familys information
void management::on_actionXem_th_ng_tin_c_c_h_gia_nh_triggered()
{
    showFamilys *familys = new showFamilys();
    familys->setWindowTitle("THÔNG TIN HỘ GIA ĐÌNH");
    familys->show();
}

// function add new familys
void management::on_actionTh_m_h_gia_nh_triggered()
{
    addnewfamilys *addnew = new addnewfamilys();
    addnew->setWindowTitle("THÊM HỘ GIA ĐÌNH");
    addnew->show();
}


void management::on_actionC_p_nh_t_th_ng_tin_h_gia_nh_triggered()
{
    updatefamily *upd = new updatefamily();
    upd->setWindowTitle("Cập nhật thông tin hộ gia đình");
    upd->show();
}


void management::on_actionXem_th_ng_tin_th_nh_vi_n_triggered()
{
    inf4full *inf = new inf4full();
    inf->setWindowTitle("Thông tin thành viên");
    inf->show();
}


void management::on_actionTh_m_nh_n_vi_n_triggered()
{
    family_addnewstaff *famad = new family_addnewstaff();
    famad->setWindowTitle("Thêm nhân viên mới");
    famad->show();
}


void management::on_actionX_a_nh_n_vi_n_triggered()
{
    manage_deletestaff *manade = new manage_deletestaff();
    manade->setWindowTitle("Xóa nhân viên");
    manade->show();
}


void management::on_actionXem_th_ng_tin_to_n_b_nh_n_vi_n_triggered()
{
    manage_showstaffs *manas = new manage_showstaffs();
    manas->setWindowTitle("Thông tin nhân viên");
    manas->show();
}


void management::on_actionTh_m_d_ch_v_triggered()
{
    manage_addnewservice *manaser = new manage_addnewservice();
    manaser->setWindowTitle("Thêm dịch vụ");
    manaser->show();
}


void management::on_actionXem_th_ng_tin_c_c_d_ch_v_triggered()
{
    manage_showservice *mansh = new manage_showservice();
    mansh->setWindowTitle("Thông tin dịch vụ");
    mansh->show();
}


void management::on_actionC_p_nh_t_d_ch_v_triggered()
{
    manage_delservice *madelse = new manage_delservice();
    madelse->setWindowTitle("Xóa dịch vụ");
    madelse->show();
}


void management::on_actionD_li_u_d_ch_v_c_ng_k_triggered()
{
    manage_servicebebuy *manservi = new manage_servicebebuy();
    manservi->setWindowTitle("Dữ liệu dịch vụ được đăng kí");
    manservi->show();
}


void management::on_actionD_li_u_t_ng_d_ch_v_h_gia_nh_triggered()
{
    manage_showsumserpay *manshow = new manage_showsumserpay();
    manshow->setWindowTitle("Dữ liệu tổng dịch vụ");
    manshow->show();
}

