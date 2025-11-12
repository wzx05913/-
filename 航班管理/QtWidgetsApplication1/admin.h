#pragma once
#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"

class Admin : public User {
private:
    int m_companyId;
    QList<int> m_managedFlightIds;
    QList<QString> m_foodRecords;
    QList<QString> m_specialDemandsRecords;

public:
    Admin(int id, const QString& name, const QString& password, int companyId);

    // 管理员特有方法
    void manageFlight(int flightId);
    void addFoodRecord(const QString& record);
    void processSpecialDemand(const QString& demand);

    QString getRole() const override { return "Admin"; }
    int getCompanyId() const { return m_companyId; }
};
#endif