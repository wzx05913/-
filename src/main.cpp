#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "view/mainwindow.h"
#include "model/companymodel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //连接数据库
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");//使用ODBC驱动
    db.setHostName("47.115.59.217");
    db.setPort(3306);
    db.setDatabaseName("ticketsys");
    if(!db.open()){
        qDebug()<<"数据库连接失败："<<db.lastError().text();
        return -1;
    }

    //载入现有的全部航司
    CompanyModel::LoadCompanies();

    MainWindow w;
    w.show();

    int ret=a.exec();

    //释放航司对象
    CompanyModel::ReleaseCompanies();

    //关闭数据库连接
    db.close();

    return ret;
}
