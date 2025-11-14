#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <vector>
#include "companymodel.h"
#include "../entity/company.h"
extern std::vector<Company*> companies;

void CompanyModel::LoadCompanies(){
    QSqlDatabase db=QSqlDatabase::database();
    QSqlQuery qrycpy(db);
    if(!qrycpy.exec("SELECT * FROM companies")) qDebug()<<qrycpy.lastError().text();
    while(qrycpy.next()){
        int id=qrycpy.value("CompanyID").toInt();
        QString name=qrycpy.value("CompanyName").toString();
        companies.push_back(new Company(id,name));
    }
}
void CompanyModel::ReleaseCompanies(){
    for(auto ptr:companies) delete ptr;
    companies.clear();
}
