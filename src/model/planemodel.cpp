#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "planemodel.h"

bool PlaneModel::GetPlanesByCompanyID(int cid,std::vector<Plane>& planes,QString& err){
    QSqlDatabase db=QSqlDatabase::database();
    QSqlQuery qrypla(db);
    qrypla.prepare("SELECT PlaneID,PlaneName,SeatCnt FROM planes WHERE CompanyID=:cid");
    qrypla.bindValue(":cid",cid);
    if(!qrypla.exec()){
        err=qrypla.lastError().text();
        return 0;
    }
    planes.clear();
    while(qrypla.next()){
        planes.push_back(Plane(qrypla.value("PlaneID").toInt(),qrypla.value("PlaneName").toString(),qrypla.value("SeatCnt").toInt()));
    }
    err="";
    return 1;
}
