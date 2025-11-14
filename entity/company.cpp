#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "company.h"

Company::Company() {}

Company::Company(int _id,const QString& _name)
    :CompanyID(_id),CompanyName(_name){}

Company::~Company(){}

QString Company::getCompanyName(){
    return CompanyName;
}
