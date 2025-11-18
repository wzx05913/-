#ifndef PLANE_H
#define PLANE_H
#include <QString>
class Plane
{
private:
    int PlaneID;
    QString PlaneName;
    int SeatCnt;
public:
    Plane();
    Plane(int _pid,const QString& _pname,int _seatcnt);
    virtual ~Plane();
    int getPlaneID()const;
    QString getPlaneName()const;
    int getSeatCnt()const;
};

#endif // PLANE_H
