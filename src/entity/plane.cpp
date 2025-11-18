#include "plane.h"

Plane::Plane() {}

Plane::Plane(int _pid,const QString& _pname,int _seatcnt)
    :PlaneID(_pid),PlaneName(_pname),SeatCnt(_seatcnt){}

Plane::~Plane(){}

int Plane::getPlaneID()const{
    return PlaneID;
}
QString Plane::getPlaneName()const{
    return PlaneName;
}
int Plane::getSeatCnt()const{
    return SeatCnt;
}
