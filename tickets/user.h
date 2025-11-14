#ifndef USER_H
#define USER_H
#include<QString>
class User
{
private:
    int UserID;
    QString UserName;
    QString HashPwd;
    QByteArray Salt;//盐
    QString UserType;
public:
    User();
    User(int _id,const QString& _name,const QString& _hashpwd,const QByteArray& _salt,const QString& _type);
    virtual ~User();
    static QByteArray GenerateSalt(int length=16);
    static QString Hash(const QString& pwd,const QByteArray& salt);
};

#endif // USER_H
