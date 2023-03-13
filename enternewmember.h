#ifndef ENTERNEWMEMBER_H
#define ENTERNEWMEMBER_H

#include <QMainWindow>

namespace Ui {
class enternewmember;
}

class enternewmember : public QMainWindow
{
    Q_OBJECT

public:
    explicit enternewmember(QWidget *parent = nullptr);
    ~enternewmember();

private slots:
    void on_pushButton_clicked();

private:
    Ui::enternewmember *ui;
};

#endif // ENTERNEWMEMBER_H
