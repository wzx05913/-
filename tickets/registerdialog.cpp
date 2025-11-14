#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include "registerdialog.h"
#include "ui_registerdialog.h"
#include "user.h"
#include "company.h"
extern std::vector<Company*> companies;

RegisterDialog::RegisterDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
    for(Company* ptr:companies){
        ui->cbxCompanyName->addItem(ptr->getCompanyName());
    }
    ui->labelCompanyName->hide();
    ui->cbxCompanyName->hide();
}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

void RegisterDialog::on_cbxUserType_currentIndexChanged(int index)
{
    if(ui->cbxUserType->currentIndex()==0){
        ui->labelCompanyName->hide();
        ui->cbxCompanyName->hide();
    }
    else if(ui->cbxUserType->currentIndex()==1){
        ui->labelCompanyName->show();
        ui->cbxCompanyName->show();
    }
}


void RegisterDialog::on_pushButton_clicked()
{
    if(ui->txtUserName->text().trimmed()==""){
        QMessageBox::information(this, "提示", "用户名不能为空！");
    }
    else if(ui->txtPassword->text().trimmed()==""){
        QMessageBox::information(this, "提示", "密码不能为空！");
    }
    else if(ui->txtRePassword->text().trimmed()!=ui->txtPassword->text().trimmed()){
        QMessageBox::information(this, "提示", "密码与确认密码不一致！");
    }
    else{
        QSqlDatabase db=QSqlDatabase::database();
        QString name=ui->txtUserName->text().trimmed();
        QString ori_pwd=ui->txtPassword->text().trimmed();
        QByteArray salt=User::GenerateSalt();
        QString encrypt_pwd=User::Hash(ori_pwd,salt);
        QString type = ui->cbxUserType->currentIndex()==0?"client":"admin";

        if(!db.transaction()){
            qDebug()<<"开启事务失败: "<<db.lastError().text();
            return;
        }

        QSqlQuery qryusr(db);
        qryusr.prepare("INSERT INTO users (UserName,HashPwd,Salt,UserType) VALUES(:name,:hashpwd,:salt,:type)");
        qryusr.bindValue(":name",name);
        qryusr.bindValue(":hashpwd",encrypt_pwd);
        qryusr.bindValue(":salt",salt.toHex());
        qryusr.bindValue(":type",type);
        if(!qryusr.exec()){
            QMessageBox::information(this, "提示", qryusr.lastError().text());
            db.rollback();
            return;
        }
        int id=qryusr.lastInsertId().toInt();
        qryusr.finish();

        if(type=="client"){
            QSqlQuery qrycli(db);
            qrycli.prepare("INSERT INTO clients (ClientID) VALUES(:id)");
            qrycli.bindValue(":id",id);
            if(!qrycli.exec()){
                QMessageBox::information(this, "提示", qrycli.lastError().text());
                db.rollback();
                return;
            }
        }//退出代码块时qrycli会自动释放结果集
        else if(type=="admin"){
            QString cname=ui->cbxCompanyName->currentText();
            int cid=-1;

            QSqlQuery qrycpy(db);
            qrycpy.prepare("SELECT CompanyID FROM companies WHERE CompanyName=:cname");
            qrycpy.bindValue(":cname",cname);
            if(!qrycpy.exec()){
                qDebug()<<qrycpy.lastError().text();
                db.rollback();
                return;
            }
            if(qrycpy.next()) cid=qrycpy.value("CompanyID").toInt();
            else{
                QMessageBox::information(this, "提示", "所选航司不存在！");
                db.rollback();
                return;
            }
            qrycpy.finish();

            QSqlQuery qryadm(db);
            qryadm.prepare("INSERT INTO admins (AdminID,CompanyID) VALUES(:id,:cid)");
            qryadm.bindValue(":id",id);
            qryadm.bindValue(":cid",cid);
            if(!qryadm.exec()){
                QMessageBox::information(this, "提示", qryadm.lastError().text());
                db.rollback();
                return;
            }
            qryadm.finish();
        }
        QMessageBox::information(this, "提示", "注册成功！");
        db.commit();
    }
}

