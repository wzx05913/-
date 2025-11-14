#include "admin.h"

Admin::Admin():User() {}
Admin::Admin(int _id,const QString& _name,const QString& _hashpwd,const QByteArray& _salt,const QString& _type,const QString& _cname)
    :User(_id,_name,_hashpwd,_salt,_type),CompanyName(_cname){}
Admin::~Admin(){}
