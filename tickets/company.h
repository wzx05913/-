#ifndef COMPANY_H
#define COMPANY_H
#include <QString>
class Company
{
private:
    int CompanyID;
    QString CompanyName;
public:
    Company();
    Company(int _id,const QString& _name);
    virtual ~Company();
    static void Load();
    static void Release();
    QString getCompanyName();
};

#endif // COMPANY_H
