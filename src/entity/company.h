#ifndef COMPANY_H
#define COMPANY_H
#include <QString>
#include "plane.h"

class Company{
private:
    int CompanyID;
    QString CompanyName;
public:
    std::vector<Plane> Planes;
    Company();
    Company(int _id,const QString& _name);
    virtual ~Company();
    int getCompanyID();
    QString getCompanyName();
};

#endif // COMPANY_H
