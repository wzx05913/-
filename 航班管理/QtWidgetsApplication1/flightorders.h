#pragma once
#ifndef FLIGHTORDERS_H
#define FLIGHTORDERS_H

#include <QString>
#include <QList>
#include <QDateTime>

class FlightOrders {
private:
    int m_id;
    int m_flightID;
    int m_clientID;
    QList<int> m_luggageIDs;        // 行李ID列表
    QList<QString> m_foods;         // 餐食选择
    QString m_specialDemands;       // 特殊需求
    QDateTime m_orderTime;          // 下单时间
    QString m_orderStatus;         // 订单状态
    double m_totalPrice;           // 总价格
    QString m_seatNumber;          // 座位号
    QString m_paymentStatus;       // 支付状态

public:
    FlightOrders(int id, int flightID, int clientID);

    // Getter方法
    int getId() const { return m_id; }
    int getFlightID() const { return m_flightID; }
    int getClientID() const { return m_clientID; }
    QString getSpecialDemands() const { return m_specialDemands; }
    QDateTime getOrderTime() const { return m_orderTime; }
    QString getOrderStatus() const { return m_orderStatus; }
    double getTotalPrice() const { return m_totalPrice; }

    // Setter方法
    void setSpecialDemands(const QString& demands) { m_specialDemands = demands; }
    void setOrderStatus(const QString& status) { m_orderStatus = status; }
    void setSeatNumber(const QString& seat) { m_seatNumber = seat; }
    void setPaymentStatus(const QString& status) { m_paymentStatus = status; }

    // 业务方法
    void addLuggage(int luggageID);
    void addFood(const QString& food);
    void calculateTotalPrice(double flightPrice, double luggageFee);
    bool canCancel() const;  // 判断是否可以取消
    bool isPaid() const { return m_paymentStatus == "已支付"; }

    // 获取详细信息
    QString getOrderInfo() const;
    QList<int> getLuggageIDs() const { return m_luggageIDs; }
    QList<QString> getFoods() const { return m_foods; }
};

#endif // FLIGHTORDERS_H