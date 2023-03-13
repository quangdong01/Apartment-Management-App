#ifndef FAMILY_SHOWINF4_H
#define FAMILY_SHOWINF4_H

#include <QMainWindow>
#include <QSqlQueryModel>
namespace Ui {
class family_showinf4;
}

class family_showinf4 : public QMainWindow
{
    Q_OBJECT

public:
    explicit family_showinf4(QWidget *parent = nullptr);
    ~family_showinf4();

private:
    Ui::family_showinf4 *ui;
    QSqlQueryModel *model;
};

#endif // FAMILY_SHOWINF4_H
