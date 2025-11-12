#pragma once
#ifndef USER_H
#define USER_H

#include <QString>
#include <QList>

class User {
protected:
    int m_id;
    QString m_name;
    QString m_password;
    QList<int> m_luggageIds;
    QString m_foodPreference;
    QString m_specialDemands;
    QList<QString> m_manageRecords;

public:
    User(int id, const QString& name, const QString& password);
    virtual ~User() = default;

    // 认证相关
    bool authenticate(const QString& password) const;
    void changePassword(const QString& newPassword);

    // 行李和偏好管理
    void addLuggage(int luggageId);
    void setFoodPreference(const QString& food);
    void setSpecialDemands(const QString& demands);

    virtual QString getRole() const { return "User"; }
};
#endif
