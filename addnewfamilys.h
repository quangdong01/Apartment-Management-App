#ifndef ADDNEWFAMILYS_H
#define ADDNEWFAMILYS_H

#include <QMainWindow>
extern int Ma_ho_gia_dinh;
extern int So_thanh_vien;
namespace Ui {
class addnewfamilys;
}

class addnewfamilys : public QMainWindow
{
    Q_OBJECT

public:
    explicit addnewfamilys(QWidget *parent = nullptr);
    ~addnewfamilys();

private slots:
    void on_pushButton_clicked();

private:
    Ui::addnewfamilys *ui;
};

#endif // ADDNEWFAMILYS_H
