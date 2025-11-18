#include "controllerflight.h"

ControllerFlight::ControllerFlight(QObject* parent,FlightModel *model)
    : QObject(parent),flightmodel(model){}

bool ControllerFlight::AddFlight(const Flight& flight,QString& err){
    if(flight.getDuration()<=0){
        err="到达时间应晚于出发时间！";
        return 0;
    }
    if(!flightmodel->CheckAddConflict(flight,err)) return 0;
    if(!flightmodel->AppendRow(flight,err)) return 0;
    err="";
    return 1;
}
bool ControllerFlight::RemoveFlight(int row,QString& err){
    if(!flightmodel->RemoveRow(row,err)) return 0;
    err="";
    return 1;
}
bool ControllerFlight::ModifyFlight(int row,const Flight& flight,QString& err){
    if(flight.getDuration()<=0){
        err="到达时间应晚于出发时间！";
        return 0;
    }
    if(!flightmodel->CheckUpdConflict(flight,err)) return 0;
    if(!flightmodel->ModifyRow(row,flight,err)) return 0;
    err="";
    return 1;
}
