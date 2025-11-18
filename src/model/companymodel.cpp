#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "companymodel.h"
#include "planemodel.h"
#include "../entity/company.h"
extern std::map<int,Company*> companies;

void CompanyModel::LoadCompanies(){
    QSqlDatabase db=QSqlDatabase::database();
    QSqlQuery qrycpy(db);
    if(!qrycpy.exec("SELECT * FROM companies")) qDebug()<<qrycpy.lastError().text();
    while(qrycpy.next()){
        int id=qrycpy.value("CompanyID").toInt();
        QString name=qrycpy.value("CompanyName").toString();
        Company* ptr=new Company(id,name);
        QString err;
        if(!PlaneModel::GetPlanesByCompanyID(id,ptr->Planes,err)) qDebug()<<err;
        companies[id]=ptr;
    }
}
void CompanyModel::ReleaseCompanies(){
    for(auto& pr:companies) delete pr.second;
    companies.clear();
}
