#pragma once
#ifndef PLANE_H
#define PLANE_H

#include <QString>
#include <QList>

class Plane {
private:
    int m_id;
    int m_companyId;
    QString m_planeType;
    int m_seatCnt;
    QList<QString> m_seatLevels;      // 座位等级：经济舱、商务舱等
    QList<bool> m_seatAvailability;   // 座位可用性
    int m_economySeats;              // 经济舱座位数
    int m_businessSeats;             // 商务舱座位数
    int m_firstClassSeats;          // 头等舱座位数

public:
    Plane(int id, int companyId, const QString& planeType, int seatCnt);

    // Getter方法
    int getId() const { return m_id; }
    int getCompanyId() const { return m_companyId; }
    QString getPlaneType() const { return m_planeType; }
    int getSeatCnt() const { return m_seatCnt; }

    // 座位管理
    bool bookSeat(int seatNumber);
    bool cancelSeat(int seatNumber);
    int getAvailableSeats() const;

    // 座位等级配置
    void configureSeats(int economy, int business, int firstClass);
    int getEconomySeats() const { return m_economySeats; }
    int getBusinessSeats() const { return m_businessSeats; }
    int getFirstClassSeats() const { return m_firstClassSeats; }

    QString toString() const;
};

#endif // PLANE_H