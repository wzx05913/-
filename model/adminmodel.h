#ifndef ADMINMODEL_H
#define ADMINMODEL_H
#include <QString>

class AdminModel{
public:
    static bool GetCompanyName(int id,QString& cname,QString& err);
    static bool InsertAdmin(const QString& name,const QString& hashpwd,const QByteArray& salt,const QString& cname,QString& err);
};

#endif // ADMINMODEL_H
