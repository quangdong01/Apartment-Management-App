#include "inf4full.h"
#include "ui_inf4full.h"
#include <QSqlQuery>
inf4full::inf4full(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::inf4full)
{
    ui->setupUi(this);
    qModel = nullptr;
    if(qModel == nullptr)
    {
        qModel = new QSqlQueryModel(this);
        qModel->setQuery("SELECT * FROM Members");
        ui->tableView_tv->setModel(qModel);
    }
    else
    {
        qModel->setQuery("SELECT * FROM Members");
    }
}

inf4full::~inf4full()
{
    delete ui;
}
