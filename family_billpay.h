#ifndef FAMILY_BILLPAY_H
#define FAMILY_BILLPAY_H

#include <QMainWindow>

namespace Ui {
class family_billpay;
}

class family_billpay : public QMainWindow
{
    Q_OBJECT

public:
    explicit family_billpay(QWidget *parent = nullptr);
    ~family_billpay();

private:
    Ui::family_billpay *ui;
};

#endif // FAMILY_BILLPAY_H
