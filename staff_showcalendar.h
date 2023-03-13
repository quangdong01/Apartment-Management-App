#ifndef STAFF_SHOWCALENDAR_H
#define STAFF_SHOWCALENDAR_H

#include <QMainWindow>
#include <QSqlQueryModel>
namespace Ui {
class staff_showcalendar;
}

class staff_showcalendar : public QMainWindow
{
    Q_OBJECT

public:
    explicit staff_showcalendar(QWidget *parent = nullptr);
    ~staff_showcalendar();

private:
    Ui::staff_showcalendar *ui;
    QSqlQueryModel *Model;
};

#endif // STAFF_SHOWCALENDAR_H
