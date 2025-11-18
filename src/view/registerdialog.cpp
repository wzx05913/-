#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include "registerdialog.h"
#include "ui_registerdialog.h"
#include "../entity/company.h"
extern std::map<int,Company*> companies;


RegisterDialog::RegisterDialog(QWidget *parent,ControllerUser *_controlleruser)
    : QDialog(parent)
    , ui(new Ui::RegisterDialog)
    , controlleruser(_controlleruser)
{
    ui->setupUi(this);
    for(const auto& pr:companies){
        ui->cbxCompanyName->addItem(pr.second->getCompanyName());
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
    QString err;
    if(ui->cbxUserType->currentIndex()==0){
        if(!controlleruser->RegisterUser(ui->txtUserName->text().trimmed(),ui->txtPassword->text().trimmed(),ui->txtRePassword->text().trimmed(),err)){
            QMessageBox::warning(this, "警告", err);
        }
        else QMessageBox::information(this, "提示", "注册成功！");
    }
    else if(ui->cbxUserType->currentIndex()==1){
        if(!controlleruser->RegisterUser(ui->txtUserName->text().trimmed(),ui->txtPassword->text().trimmed(),ui->txtRePassword->text().trimmed(),ui->cbxCompanyName->currentText(),err)){
            QMessageBox::warning(this, "警告", err);
        }
        else QMessageBox::information(this, "提示", "注册成功！");
    }
}

