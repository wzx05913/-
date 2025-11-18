#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include "flightmodel.h"
#include "../entity/company.h"
extern std::map<int,Company*> companies;

FlightModel::FlightModel(QObject *parent)
: QSqlTableModel(parent){}

void FlightModel::init(){
    setTable("flights");
    setEditStrategy(QSqlTableModel::OnManualSubmit);
    select();
}
QVariant FlightModel::data(const QModelIndex &index, int role) const{
    if(role == Qt::DisplayRole){
        if(index.column() == 1) {//CompanyID映射成CompanyName
            int cid=QSqlTableModel::data(index, Qt::EditRole).toInt();
            if(companies.find(cid)!=companies.end()) return companies[cid]->getCompanyName();
            else return QString();
        }
        else if(index.column() == 2){//PlaneID映射成PlaneName
            QModelIndex companyIndex = index.sibling(index.row(),1);
            int cid=QSqlTableModel::data(companyIndex, Qt::EditRole).toInt();
            int pid=QSqlTableModel::data(index, Qt::EditRole).toInt();
            if(companies.find(cid)==companies.end()) return QString();
            Company* ptr=companies[cid];
            for(const auto& plane:ptr->Planes){
                if(plane.getPlaneID()==pid) return plane.getPlaneName();
            }
            return QString();
        }
        return QSqlTableModel::data(index, role);//其他情况用默认实现
    }
    return QSqlTableModel::data(index, role);//其他情况用默认实现
}
bool FlightModel::SelectByRow(int row,Flight& flight,QString& err){
    if(row<0||row>=this->rowCount()){
        err=QString("Invalid row index %1").arg(row);
        return 0;
    }
    QSqlRecord rec=this->record(row);
    flight.setFlightID(rec.value("FlightID").toInt());
    flight.setCompanyID(rec.value("CompanyID").toInt());
    flight.setPlaneID(rec.value("PlaneID").toInt());
    flight.setSeatCnt(rec.value("SeatCnt").toInt());
    flight.setStartCity(rec.value("StartCity").toString());
    flight.setEndCity(rec.value("EndCity").toString());
    flight.setStartTime(rec.value("StartTime").toDateTime());
    flight.setEndTime(rec.value("EndTime").toDateTime());
    flight.setDuration(rec.value("Duration").toDouble());
    err="";
    return 1;
}
bool FlightModel::AppendRow(const Flight& flight,QString& err){
    int row=this->rowCount();
    this->insertRow(row);
    this->setData(this->index(row,1),flight.getCompanyID());
    this->setData(this->index(row,2),flight.getPlaneID());
    this->setData(this->index(row,3),flight.getSeatCnt());
    this->setData(this->index(row,4),flight.getStartCity());
    this->setData(this->index(row,5),flight.getEndCity());
    this->setData(this->index(row,6),flight.getStartTime());
    this->setData(this->index(row,7),flight.getEndTime());
    this->setData(this->index(row,8),flight.getDuration());
    if(!this->submitAll()){
        err=this->lastError().text();
        this->revertAll();
        return 0;
    }
    err="";
    return 1;
}
bool FlightModel::RemoveRow(int row,QString& err){
    if(!this->removeRow(row)){
        err=this->lastError().text();
        this->revertAll();
        return 0;
    }
    if(!this->submitAll()){
        err=this->lastError().text();
        this->revertAll();
        return 0;
    }
    err="";
    return 1;
}
bool FlightModel::ModifyRow(int row,const Flight&flight,QString& err){
    this->setData(this->index(row,1),flight.getCompanyID());
    this->setData(this->index(row,2),flight.getPlaneID());
    this->setData(this->index(row,3),flight.getSeatCnt());
    this->setData(this->index(row,4),flight.getStartCity());
    this->setData(this->index(row,5),flight.getEndCity());
    this->setData(this->index(row,6),flight.getStartTime());
    this->setData(this->index(row,7),flight.getEndTime());
    this->setData(this->index(row,8),flight.getDuration());
    if(!this->submitAll()){
        err=this->lastError().text();
        this->revertAll();
        return 0;
    }
    err="";
    return 1;
}
bool FlightModel::CheckAddConflict(const Flight& flight,QString& err)const{
    QSqlDatabase db=QSqlDatabase::database();
    QSqlQuery qryfli(db);
    qryfli.prepare("SELECT StartTime,EndTime FROM flights WHERE PlaneID=:pid AND (StartTime<=:etim AND EndTime>=:stim) LIMIT 1");
    qryfli.bindValue(":pid",flight.getPlaneID());
    qryfli.bindValue(":etim",flight.getEndTime());
    qryfli.bindValue(":stim",flight.getStartTime());
    if(!qryfli.exec()){
        err="查询冲突航班失败："+qryfli.lastError().text();
        return 0;
    }
    if(qryfli.next()){
        err=QString("飞机在 %1 - %2 时间段有其他飞行任务")
                  .arg(qryfli.value("StartTime").toDateTime().toString("yyyy-MM-dd hh:mm")
                  ,qryfli.value("EndTime").toDateTime().toString("yyyy-MM-dd hh:mm"));
        return 0;
    }
    err="";
    return 1;
}
bool FlightModel::CheckUpdConflict(const Flight& flight,QString& err)const{
    QSqlDatabase db=QSqlDatabase::database();
    QSqlQuery qryfli(db);
    qryfli.prepare("SELECT StartTime,EndTime FROM flights WHERE PlaneID=:pid AND (StartTime<=:etim AND EndTime>=:stim) AND FlightID!=:fid LIMIT 1");
    qryfli.bindValue(":pid",flight.getPlaneID());
    qryfli.bindValue(":etim",flight.getEndTime());
    qryfli.bindValue(":stim",flight.getStartTime());
    qryfli.bindValue(":fid",flight.getFlightID());
    if(!qryfli.exec()){
        err="查询冲突航班失败："+qryfli.lastError().text();
        return 0;
    }
    if(qryfli.next()){
        err=QString("飞机在 %1 - %2 时间段有其他飞行任务")
                  .arg(qryfli.value("StartTime").toDateTime().toString("yyyy-MM-dd hh:mm")
                       ,qryfli.value("EndTime").toDateTime().toString("yyyy-MM-dd hh:mm"));
        return 0;
    }
    err="";
    return 1;
}
