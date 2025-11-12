#include "QtWidgetsApplication1.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QMessageBox>

QtWidgetsApplication1::QtWidgetsApplication1(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    // 显示当前 Qt 支持的驱动，便于调试
    QStringList drivers = QSqlDatabase::drivers();
    QMessageBox::information(this, "Qt SQL Drivers", drivers.join(", "));

    // 使用 DSN-less 连接（确保 Driver 名称与 ODBC 管理器里的 Drivers 标签完全一致）
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    QString conn = QStringLiteral(
        "Driver={MySQL ODBC 9.5 Unicode Driver};"
        "Server=127.0.0.1;"
        "Port=3306;"
        "Database=airport_system;"
        "User=root;"
        "Password=123abc;"
        "Option=3;");
    db.setDatabaseName(conn);
    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", db.lastError().text());
        return;
    }

    // 列出当前连接的所有表（运行后弹窗会显示）
    QStringList tables = db.tables();
    QMessageBox::information(this, "Tables in DB", tables.join(", "));

    QSqlQuery q(db);
    if (q.exec("SHOW TABLES")) {
        QStringList tables;
        while (q.next()) tables << q.value(0).toString();
        QMessageBox::information(this, "Tables (SHOW TABLES)", tables.join(", "));
    } else {
        QMessageBox::warning(this, "SHOW TABLES failed", q.lastError().text());
    }
}

QtWidgetsApplication1::~QtWidgetsApplication1()
{
    QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
}