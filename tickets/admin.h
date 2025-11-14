#ifndef ADMIN_H
#define ADMIN_H
#include "user.h"
class Admin:public User
{
private:
    QString CompanyName;
public:
    Admin();
    Admin(int _id,const QString& _name,const QString& _hashpwd,const QByteArray& _salt,const QString& _type,const QString& _cname);
    virtual ~Admin();
};

#endif // ADMIN_H
