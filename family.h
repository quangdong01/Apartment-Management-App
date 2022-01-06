#ifndef FAMILY_H
#define FAMILY_H
#include <QTimer>
#include <QMainWindow>


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

private:
    Ui::family *ui;
    QTimer *timer;
};

#endif // FAMILY_H
