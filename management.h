#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include <QTimer>
#include <QMainWindow>

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
    void on_action_ng_xu_t_triggered();

private:
    Ui::management *ui;
    QTimer *timer;
};

#endif // MANAGEMENT_H
