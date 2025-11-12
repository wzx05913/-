#pragma once
#ifndef FLIGHT_H
#define FLIGHT_H

#include <QString>
#include <QDateTime>
#include <QList>

class Flight {
private:
    int m_id;
    int m_companyId;
    int m_planeId;
    QString m_startCity;
    QString m_endCity;
    QDateTime m_startTime;
    QDateTime m_endTime;
    int m_duration; // 分钟

    // 座位管理
    int m_totalSeats;
    QList<QString> m_seatOwners;    // 座位所有者
    QList<QString> m_seatLevels;    // 座位等级
    QList<int> m_clients;          // 乘客ID列表

    // 行李管理
    QList<int> m_luggageIds;

    // 餐食管理
    QList<QString> m_availableFoodTypes;
    QList<QString> m_foodTypeCategories;

public:
    Flight(int id, int companyId, int planeId,
        const QString& startCity, const QString& endCity,
        const QDateTime& startTime, const QDateTime& endTime);

    // 座位管理方法
    bool bookSeat(int clientId, const QString& seatLevel);
    bool cancelSeat(int clientId);

    // 行李和餐食管理
    void addLuggage(int luggageId);
    void setFoodTypes(const QList<QString>& foodTypes);

    int getId() const { return m_id; }
    QString getRoute() const { return m_startCity + " - " + m_endCity; }
};
#endif