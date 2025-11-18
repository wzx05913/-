#include "controlleruser.h"
#include "../entity/user.h"
#include "../entity/client.h"
#include "../entity/admin.h"
#include "../model/usermodel.h"
#include "../model/clientmodel.h"
#include "../model/adminmodel.h"
extern User *curUser;

ControllerUser::ControllerUser(QObject* parent)
    : QObject(parent){}

bool ControllerUser::LoginUser(const QString& name,const QString& ori_pwd,QString& err){
    if(name==""){
        err="用户名不能为空！";
        return 0;
    }
    if(ori_pwd==""){
        err="密码不能为空！";
        return 0;
    }
    User usr;
    if(!UserModel::SelectByName(name,usr,err)) return 0;
    QString encry_pwd=User::Hash(ori_pwd,usr.getSalt());
    if(usr.getHashPwd()!=encry_pwd){
        err="密码错误！";
        return 0;
    }
    if(usr.getUserType()=="client"){
        curUser=new Client(usr.getUserID(),name,encry_pwd,usr.getSalt(),"client");
        emit clientLoggedIn(name);
    }
    else if(usr.getUserType()=="admin"){
        int cid=-1;
        if(!AdminModel::GetCompanyID(usr.getUserID(),cid,err)) return 0;
        curUser=new Admin(usr.getUserID(),name,encry_pwd,usr.getSalt(),"admin",cid);
        emit adminLoggedIn(name);
    }
    err="";
    return 1;
}

bool ControllerUser::RegisterUser(const QString& name,const QString& ori_pwd,const QString& reori_pwd,QString& err){
    if(name==""){
        err="用户名不能为空！";
        return 0;
    }
    if(ori_pwd==""){
        err="密码不能为空！";
        return 0;
    }
    if(ori_pwd!=reori_pwd){
        err="两次输入密码不一致！";
        return 0;
    }
    QByteArray salt=User::GenerateSalt();
    QString encry_pwd=User::Hash(ori_pwd,salt);
    if(!ClientModel::InsertClient(name,encry_pwd,salt,err)) return 0;
    err="";
    return 1;
}
bool ControllerUser::RegisterUser(const QString& name,const QString& ori_pwd,const QString& reori_pwd,const QString& cname,QString& err){
    if(name==""){
        err="用户名不能为空！";
        return 0;
    }
    if(ori_pwd==""){
        err="密码不能为空！";
        return 0;
    }
    if(ori_pwd!=reori_pwd){
        err="两次输入密码不一致！";
        return 0;
    }
    QByteArray salt=User::GenerateSalt();
    QString encry_pwd=User::Hash(ori_pwd,salt);
    if(!AdminModel::InsertAdmin(name,encry_pwd,salt,cname,err)) return 0;
    err="";
    return 1;
}

void ControllerUser::LogoutUser(){
    curUser=nullptr;
    emit userLoggedOut();
}
