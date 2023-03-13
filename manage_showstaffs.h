#ifndef MANAGE_SHOWSTAFFS_H
#define MANAGE_SHOWSTAFFS_H

#include <QMainWindow>
#include <QSqlQueryModel>
namespace Ui {
class manage_showstaffs;
}

class manage_showstaffs : public QMainWindow
{
    Q_OBJECT

public:
    explicit manage_showstaffs(QWidget *parent = nullptr);
    ~manage_showstaffs();

private:
    Ui::manage_showstaffs *ui;
    QSqlQueryModel *mmmModel;
};

#endif // MANAGE_SHOWSTAFFS_H
