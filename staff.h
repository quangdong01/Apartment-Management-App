#ifndef STAFF_H
#define STAFF_H

#include <QMainWindow>
#include <QTimer>
#include "staff_showinf4.h"
#include "staff_showcalendar.h"
namespace Ui {
class staff;
}

class staff : public QMainWindow
{
    Q_OBJECT

public:
    explicit staff(QWidget *parent = nullptr);
    ~staff();

public slots:
     void my_function();

private slots:
    void on_actionTho_t_triggered();

    void on_actionXem_h_s_triggered();

    void on_actionL_ch_tr_c_triggered();

private:
    Ui::staff *ui;
     QTimer *timer;
};

#endif // STAFF_H
