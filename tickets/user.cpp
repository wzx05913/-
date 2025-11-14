#include <QCryptographicHash>
#include <QRandomGenerator>
#include "user.h"

User::User() {}
User::User(int _id,const QString& _name,const QString& _hashpwd,const QByteArray& _salt,const QString& _type)
    :UserID(_id),UserName(_name),HashPwd(_hashpwd),Salt(_salt),UserType(_type){}
User::~User(){}
QByteArray User::GenerateSalt(int length){
    QByteArray salt;
    salt.reserve(length);
    for(int i=0;i<length;i++){ //生成ASCII 可打印字符作为盐
        char c=static_cast<char>(QRandomGenerator::global()->bounded(33, 127));
        salt.append(c);
    }
    return salt;
}
QString User::Hash(const QString& pwd,const QByteArray& salt){
    QByteArray passBytes=pwd.toUtf8();
    QByteArray salted=salt+passBytes;
    QByteArray hash=QCryptographicHash::hash(salted,QCryptographicHash::Sha256);
    return hash.toHex();
}
