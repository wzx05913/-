#ifndef ADMINMODEL_H
#define ADMINMODEL_H
#include <QString>

class AdminModel{
public:
    static bool GetCompanyID(int id,int& cid,QString& err);
    static bool InsertAdmin(const QString& name,const QString& hashpwd,const QByteArray& salt,const QString& cname,QString& err);
};

#endif // ADMINMODEL_H
