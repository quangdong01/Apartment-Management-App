#ifndef SHOWFAMILYS_H
#define SHOWFAMILYS_H

#include <QMainWindow>
#include <QSqlQueryModel>
namespace Ui {
class showFamilys;
}

class showFamilys : public QMainWindow
{
    Q_OBJECT

public:
    explicit showFamilys(QWidget *parent = nullptr);
    ~showFamilys();

private:
    Ui::showFamilys *ui;
    QSqlQueryModel *mModel;
};

#endif // SHOWFAMILYS_H
