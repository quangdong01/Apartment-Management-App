#ifndef FAMILY_H
#define FAMILY_H
#include <QTimer>
#include <QMainWindow>
#include "family_showinf4.h"
#include "family_chooseservice.h"
#include "family_servicebuy.h"
namespace Ui {
class family;
}

class family : public QMainWindow
{
    Q_OBJECT

public:
    explicit family(QWidget *parent = nullptr);
    ~family();
public slots:
    void my_function();


private slots:

    void on_actionTho_t_triggered();

    void on_actionXem_h_s_triggered();

    void on_actionD_ch_v_triggered();

    void on_actionTh_ng_tin_d_ch_v_th_ng_n_y_triggered();

private:
    Ui::family *ui;
    QTimer *timer;
};

#endif // FAMILY_H
