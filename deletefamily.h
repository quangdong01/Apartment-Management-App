#ifndef DELETEFAMILY_H
#define DELETEFAMILY_H

#include <QMainWindow>
#include <QSqlQueryModel>
namespace Ui {
class deletefamily;
}

class deletefamily : public QMainWindow
{
    Q_OBJECT

public:
    explicit deletefamily(QWidget *parent = nullptr);
    ~deletefamily();

private slots:
    void on_btn_x_clicked();

private:
    Ui::deletefamily *ui;
    QSqlQueryModel *mModel;
};

#endif // DELETEFAMILY_H
