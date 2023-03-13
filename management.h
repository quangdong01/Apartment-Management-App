#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include <QTimer>
#include <QMainWindow>
#include "showfamilys.h"
#include "addnewfamilys.h"
#include "updatefamily.h"
#include "inf4full.h"
#include "family_addnewstaff.h"
#include "manage_deletestaff.h"
#include "manage_showstaffs.h"
#include "manage_addnewservice.h"
#include "manage_showservice.h"
#include "manage_delservice.h"
#include "manage_servicebebuy.h"
#include "manage_showsumserpay.h"


namespace Ui {
class management;
}

class management : public QMainWindow
{
    Q_OBJECT

public:
    explicit management(QWidget *parent = nullptr);
    ~management();

public slots:
    void my_function();

private slots:
    // function handle issue when click close (X)
    void on_action_ng_xu_t_triggered();

    // function show inf4 of Familys table in database
    void on_actionXem_th_ng_tin_c_c_h_gia_nh_triggered();

    // function add new family
    void on_actionTh_m_h_gia_nh_triggered();

    //  function update family
    void on_actionC_p_nh_t_th_ng_tin_h_gia_nh_triggered();

    void on_actionXem_th_ng_tin_th_nh_vi_n_triggered();

    void on_actionTh_m_nh_n_vi_n_triggered();

    void on_actionX_a_nh_n_vi_n_triggered();

    void on_actionXem_th_ng_tin_to_n_b_nh_n_vi_n_triggered();

    void on_actionTh_m_d_ch_v_triggered();

    void on_actionXem_th_ng_tin_c_c_d_ch_v_triggered();

    void on_actionC_p_nh_t_d_ch_v_triggered();

    void on_actionD_li_u_d_ch_v_c_ng_k_triggered();


    void on_actionD_li_u_t_ng_d_ch_v_h_gia_nh_triggered();

private:
    Ui::management *ui;
    QTimer *timer;
};

#endif // MANAGEMENT_H
