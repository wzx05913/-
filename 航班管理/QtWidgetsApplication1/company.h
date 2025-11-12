#pragma once
#ifndef COMPANY_H
#define COMPANY_H

#include <QString>
#include <QList>
#include "Flight.h"
#include "Plane.h"
#include "Admin.h"

class Company {
private:
    int m_id;
    QString m_name;
    QList<Flight*> m_flights;      // 航班列表
    QList<Plane*> m_planes;        // 飞机列表
    QList<Admin*> m_admins;        // 管理员列表
    QList<QString> m_manageRecords; // 管理记录

public:
    Company(int id, const QString& name);

    // Getter/Setter
    int getId() const { return m_id; }
    QString getName() const { return m_name; }

    // 管理方法
    void addFlight(Flight* flight);
    void addPlane(Plane* plane);
    void addAdmin(Admin* admin);
    void addManageRecord(const QString& record);

    QList<Flight*> getFlights() const { return m_flights; }
    QList<Plane*> getPlanes() const { return m_planes; }
};
#endif