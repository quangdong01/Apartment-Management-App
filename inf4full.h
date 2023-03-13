#ifndef INF4FULL_H
#define INF4FULL_H

#include <QMainWindow>
#include <QSqlQueryModel>
namespace Ui {
class inf4full;
}

class inf4full : public QMainWindow
{
    Q_OBJECT

public:
    explicit inf4full(QWidget *parent = nullptr);
    ~inf4full();

private:
    Ui::inf4full *ui;
    QSqlQueryModel *qModel;
};

#endif // INF4FULL_H
