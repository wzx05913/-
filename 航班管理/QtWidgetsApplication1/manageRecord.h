#pragma once
#ifndef MANAGERRECORD_H
#define MANAGERRECORD_H

#include <QString>
#include <QDateTime>
#include <QList>

// 操作类型枚举
enum class OperationType {
    FlightManagement,    // 航班管理
    UserManagement,      // 用户管理
    SystemSettings,      // 系统设置
    OrderProcessing,     // 订单处理
    ReportGeneration     // 报表生成
};

class ManagerRecord {
private:
    int m_id;
    int m_managerID;           // 操作的管理员ID
    QString m_managerName;     // 操作的管理员姓名
    int m_companyID;           // 所属公司ID
    OperationType m_operationType; // 操作类型
    QString m_operationDetails;   // 操作详情
    QDateTime m_operationTime;    // 操作时间
    QString m_targetObject;        // 操作目标（如航班号、用户名等）
    bool m_operationResult;        // 操作结果
    QString m_ipAddress;          // 操作IP地址

public:
    ManagerRecord(int id, int managerID, const QString& managerName,
        int companyID, OperationType opType, const QString& details);

    // Getter方法
    int getId() const { return m_id; }
    int getManagerID() const { return m_managerID; }
    QString getManagerName() const { return m_managerName; }
    int getCompanyID() const { return m_companyID; }
    OperationType getOperationType() const { return m_operationType; }
    QString getOperationDetails() const { return m_operationDetails; }
    QDateTime getOperationTime() const { return m_operationTime; }
    QString getTargetObject() const { return m_targetObject; }
    bool getOperationResult() const { return m_operationResult; }

    // Setter方法
    void setOperationResult(bool result) { m_operationResult = result; }
    void setTargetObject(const QString& target) { m_targetObject = target; }
    void setIpAddress(const QString& ip) { m_ipAddress = ip; }

    // 静态方法 - 操作类型转换
    static QString operationTypeToString(OperationType type);
    static OperationType stringToOperationType(const QString& typeStr);

    // 业务方法
    QString getRecordInfo() const;
    bool isSuccessful() const { return m_operationResult; }
    bool isRecentOperation(int minutes = 30) const; // 是否为近期操作
};

#endif // MANAGERRECORD_H