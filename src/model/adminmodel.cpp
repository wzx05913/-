#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "adminmodel.h"

bool AdminModel::GetCompanyID(int id,int& cid,QString& err){
    QSqlDatabase db=QSqlDatabase::database();
    QSqlQuery qryadm(db);
    qryadm.prepare("SELECT c.CompanyID FROM admins a JOIN companies c ON a.CompanyID=c.CompanyID WHERE a.AdminID=:id");
    qryadm.bindValue(":id",id);
    if(!qryadm.exec()){
        err=qryadm.lastError().text();
        return 0;
    }
    if(qryadm.next()){
        cid=qryadm.value("CompanyID").toInt();
        err="";
        return 1;
    }
    else{
        err="找不到用户所在的航司！";
        return 0;
    }
}

bool AdminModel::InsertAdmin(const QString& name,const QString& hashpwd,const QByteArray& salt,const QString& cname,QString& err){
    QSqlDatabase db=QSqlDatabase::database();
    if(!db.transaction()){
        err="开启事务失败: "+db.lastError().text();
        return 0;
    }

    QSqlQuery qryusr(db);
    qryusr.prepare("INSERT INTO users (UserName,HashPwd,Salt,UserType) VALUES(:name,:hashpwd,:salt,:type)");
    qryusr.bindValue(":name",name);
    qryusr.bindValue(":hashpwd",hashpwd);
    qryusr.bindValue(":salt",salt.toHex());
    qryusr.bindValue(":type","admin");
    if(!qryusr.exec()){
        err=qryusr.lastError().text();
        db.rollback();
        return 0;
    }
    int id=qryusr.lastInsertId().toInt();
    qryusr.finish();

    int cid=-1;
    QSqlQuery qrycpy(db);
    qrycpy.prepare("SELECT CompanyID FROM companies WHERE CompanyName=:cname");
    qrycpy.bindValue(":cname",cname);
    if(!qrycpy.exec()){
        err=qrycpy.lastError().text();
        db.rollback();
        return 0;
    }
    if(qrycpy.next()) cid=qrycpy.value("CompanyID").toInt();
    else{
        err="所选航司不存在！";
        db.rollback();
        return 0;
    }
    qrycpy.finish();

    QSqlQuery qryadm(db);
    qryadm.prepare("INSERT INTO admins (AdminID,CompanyID) VALUES(:id,:cid)");
    qryadm.bindValue(":id",id);
    qryadm.bindValue(":cid",cid);
    if(!qryadm.exec()){
        err=qryadm.lastError().text();
        db.rollback();
        return 0;
    }
    qryadm.finish();

    if(!db.commit()){
        err="提交失败："+db.lastError().text();
        db.rollback();
        return 0;
    }
    err="";
    return 1;
}
