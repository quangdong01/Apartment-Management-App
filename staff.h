#ifndef STAFF_H
#define STAFF_H

#include <QMainWindow>
#include <QTimer>
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

private:
    Ui::staff *ui;
     QTimer *timer;
};

#endif // STAFF_H
