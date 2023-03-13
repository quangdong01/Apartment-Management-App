#ifndef STAFF_SHOWINF4_H
#define STAFF_SHOWINF4_H

#include <QMainWindow>
#include <QSqlQueryModel>
namespace Ui {
class staff_showinf4;
}

class staff_showinf4 : public QMainWindow
{
    Q_OBJECT

public:
    explicit staff_showinf4(QWidget *parent = nullptr);
    ~staff_showinf4();

private:
    Ui::staff_showinf4 *ui;
    QSqlQueryModel *Model;
};

#endif // STAFF_SHOWINF4_H
