#pragma once
#ifndef LUGGAGE_H
#define LUGGAGE_H

#include <QString>
#include <QDateTime>

class Luggage {
private:
    int m_id;
    int m_flightId;
    int m_clientId;
    QDateTime m_arriveTime;
    double m_weight;           // 重量(kg)
    QString m_status;          // 状态：已托运、已到达等
    QString m_tagNumber;       // 行李标签号
    QString m_description;     // 行李描述

public:
    Luggage(int id, int flightId, int clientId, double weight);

    // Getter/Setter方法
    int getId() const { return m_id; }
    int getFlightId() const { return m_flightId; }
    int getClientId() const { return m_clientId; }
    double getWeight() const { return m_weight; }
    QString getStatus() const { return m_status; }
    QDateTime getArriveTime() const { return m_arriveTime; }

    void setStatus(const QString& status) { m_status = status; }
    void setArriveTime(const QDateTime& time) { m_arriveTime = time; }
    void setTagNumber(const QString& tag) { m_tagNumber = tag; }
    void setDescription(const QString& desc) { m_description = desc; }

    // 业务方法
    bool isOverweight() const { return m_weight > 20.0; } // 超重检查(20kg限制)
    double calculateFee() const; // 计算托运费
    QString getLuggageInfo() const;
};

#endif // LUGGAGE_H