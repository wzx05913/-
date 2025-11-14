#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "mainwindow.h"
#include "company.h"
extern std::vector<Company*> companies;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //获取数据库连接对象
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");//使用ODBC驱动
    db.setHostName("47.115.59.217");
    db.setPort(3306);
    db.setDatabaseName("ticketsys");

    //载入现有的全部航司
    Company::Load();

    MainWindow w;
    w.show();

    int ret=a.exec();

    //释放航司对象
    Company::Release();

    return ret;
}
