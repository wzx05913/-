#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "company.h"
extern std::vector<Company*> companies;

Company::Company() {}
Company::Company(int _id,const QString& _name)
    :CompanyID(_id),CompanyName(_name){}
Company::~Company(){}
void Company::Load(){
    QSqlDatabase db=QSqlDatabase::database();
    QSqlQuery qrycpy(db);
    if(!qrycpy.exec("SELECT * FROM companies")) qDebug()<<qrycpy.lastError().text();
    while(qrycpy.next()){
        int id=qrycpy.value("CompanyID").toInt();
        QString name=qrycpy.value("CompanyName").toString();
        companies.push_back(new Company(id,name));
    }
}
void Company::Release(){
    for(auto ptr:companies) delete ptr;
    companies.clear();
}
QString Company::getCompanyName(){
    return CompanyName;
}
