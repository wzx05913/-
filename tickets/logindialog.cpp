#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include "logindialog.h"
#include "ui_logindialog.h"
#include "user.h"
#include "client.h"
#include "admin.h"
#include "registerdialog.h"
extern User *curUser;

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_btnLogin_clicked()
{
    if(ui->txtUserName->text().trimmed()==""){
        QMessageBox::information(this, "提示", "用户名不能为空！");
    }
    else if(ui->txtPassword->text().trimmed()==""){
        QMessageBox::information(this, "提示", "密码不能为空！");
    }
    else{
        QSqlDatabase db=QSqlDatabase::database();
        QString name=ui->txtUserName->text().trimmed();
        QString pwd=ui->txtPassword->text().trimmed();
        QSqlQuery qryusr(db);
        qryusr.prepare("SELECT * FROM users WHERE UserName=:name");
        qryusr.bindValue(":name",name);
        if(!qryusr.exec()){
            qDebug()<<qryusr.lastError().text();
            return;
        }
        if(qryusr.next()){
            int id=qryusr.value("UserID").toInt();
            QString hashpwd=qryusr.value("HashPwd").toString();
            QByteArray salt=QByteArray::fromHex(qryusr.value("Salt").toString().toUtf8());
            QString type=qryusr.value("UserType").toString();
            QString encrypt_pwd=User::Hash(pwd,salt);
            if(hashpwd==encrypt_pwd){
                if(type=="client"){
                    curUser=new Client(id,name,hashpwd,salt,type);
                    QMessageBox::information(this, "提示", "客户登录成功！");
                    accept();
                }
                else if(type=="admin"){
                    QSqlQuery qryadm(db);
                    qryadm.prepare("SELECT c.CompanyName FROM admins a JOIN companies c ON a.CompanyID=c.CompanyID WHERE a.AdminID=:id");
                    qryadm.bindValue(":id",id);
                    if(!qryadm.exec()){
                        qDebug()<<qryadm.lastError().text();
                        return;
                    }
                    if(qryadm.next()){
                        QString cname=qryadm.value("CompanyName").toString();
                        curUser=new Admin(id,name,hashpwd,salt,type,cname);
                        QMessageBox::information(this, "提示", "管理员登录成功！");
                        accept();
                    }
                    else QMessageBox::information(this, "提示", "找不到用户所在的航司！");
                }
            }
            else QMessageBox::information(this, "提示", "密码错误！");
        }
        else QMessageBox::information(this, "提示", "用户名不存在！");
    }
}


void LoginDialog::on_btnRegister_clicked()
{
    RegisterDialog registerdialog;
    registerdialog.exec();
}

