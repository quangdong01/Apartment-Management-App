#ifndef MANAGE_SHOWSERVICE_H
#define MANAGE_SHOWSERVICE_H

#include <QMainWindow>
#include <QSqlQueryModel>
namespace Ui {
class manage_showservice;
}

class manage_showservice : public QMainWindow
{
    Q_OBJECT

public:
    explicit manage_showservice(QWidget *parent = nullptr);
    ~manage_showservice();

private:
    Ui::manage_showservice *ui;
    QSqlQueryModel *mModel;
};

#endif // MANAGE_SHOWSERVICE_H
