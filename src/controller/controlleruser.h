#ifndef CONTROLLERUSER_H
#define CONTROLLERUSER_H
#include <QObject>
#include <QString>

class ControllerUser:public QObject
{
    Q_OBJECT
public:
    explicit ControllerUser(QObject* parent = nullptr);
    bool RegisterUser(const QString& name,const QString& ori_pwd,const QString& reori_pwd,QString& err);
    bool RegisterUser(const QString& name,const QString& ori_pwd,const QString& reori_pwd,const QString& cname,QString& err);
    bool LoginUser(const QString& name,const QString& ori_pwd,QString& err);
    void LogoutUser();
signals:
    void clientLoggedIn(const QString& name);
    void adminLoggedIn(const QString& name);
    void userLoggedOut();
};
#endif // CONTROLLERUSER_H
