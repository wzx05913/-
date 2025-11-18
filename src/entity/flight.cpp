#include "flight.h"

Flight::Flight() {}

Flight::~Flight(){}

void Flight::setFlightID(int _fid){
    FlightID=_fid;
}
void Flight::setCompanyID(int _cid){
    CompanyID=_cid;
}
void Flight::setPlaneID(int _pid){
    PlaneID=_pid;
}
void Flight::setSeatCnt(int _seatcnt){
    SeatCnt=_seatcnt;
}
void Flight::setStartCity(const QString& _cityname){
    StartCity=_cityname;
}
void Flight::setEndCity(const QString& _cityname){
    EndCity=_cityname;
}
void Flight::setStartTime(const QDateTime& _time){
    StartTime=_time;
}
void Flight::setEndTime(const QDateTime& _time){
    EndTime=_time;
}
void Flight::setDuration(double _dur){
    Duration=_dur;
}

int Flight::getFlightID()const{
    return FlightID;
}
int Flight::getCompanyID()const{
    return CompanyID;
}
int Flight::getPlaneID()const{
    return PlaneID;
}
int Flight::getSeatCnt()const{
    return SeatCnt;
}
QString Flight::getStartCity()const{
    return StartCity;
}
QString Flight::getEndCity()const{
    return EndCity;
}
QDateTime Flight::getStartTime()const{
    return StartTime;
}
QDateTime Flight::getEndTime()const{
    return EndTime;
}
double Flight::getDuration()const{
    return Duration;
}
