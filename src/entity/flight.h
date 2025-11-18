#ifndef FLIGHT_H
#define FLIGHT_H
#include <QString>
#include <QDateTime>
class Flight
{
private:
    int FlightID;
    int CompanyID;
    int PlaneID;
    int SeatCnt;//剩余座位数
    QString StartCity;
    QString EndCity;
    QDateTime StartTime;
    QDateTime EndTime;
    double Duration;

public:
    Flight();
    virtual ~Flight();
    void setFlightID(int _fid);
    void setCompanyID(int _cid);
    void setPlaneID(int _pid);
    void setSeatCnt(int _seatcnt);
    void setStartCity(const QString& _cityname);
    void setEndCity(const QString& _cityname);
    void setStartTime(const QDateTime& _time);
    void setEndTime(const QDateTime& _time);
    void setDuration(double _dur);
    int getFlightID()const;
    int getCompanyID()const;
    int getPlaneID()const;
    int getSeatCnt()const;
    QString getStartCity()const;
    QString getEndCity()const;
    QDateTime getStartTime()const;
    QDateTime getEndTime()const;
    double getDuration()const;
};

#endif // FLIGHT_H
