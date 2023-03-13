#ifndef SEARCHTOCOMLEMENT_H
#define SEARCHTOCOMLEMENT_H

#include <QMainWindow>
#include <QSqlQueryModel>
extern QString mhgd;
namespace Ui {
class searchtocomlement;
}

class searchtocomlement : public QMainWindow
{
    Q_OBJECT

public:
    explicit searchtocomlement(QWidget *parent = nullptr);
    ~searchtocomlement();

private slots:
    void on_btn_tt_clicked();

private:
    Ui::searchtocomlement *ui;
    QSqlQueryModel *mModel;
};

#endif // SEARCHTOCOMLEMENT_H
