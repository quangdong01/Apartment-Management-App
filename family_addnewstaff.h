#ifndef FAMILY_ADDNEWSTAFF_H
#define FAMILY_ADDNEWSTAFF_H

#include <QMainWindow>

namespace Ui {
class family_addnewstaff;
}

class family_addnewstaff : public QMainWindow
{
    Q_OBJECT

public:
    explicit family_addnewstaff(QWidget *parent = nullptr);
    ~family_addnewstaff();

private slots:
    void on_pushButton_clicked();

private:
    Ui::family_addnewstaff *ui;
};

#endif // FAMILY_ADDNEWSTAFF_H
