#include <QMessageBox>
#include "flightwidget.h"
#include "ui_flightwidget.h"
#include "../entity/flight.h"
#include "../entity/company.h"
#include "../entity/user.h"
#include "../entity/admin.h"
#include "../model/flightmodel.h"
extern std::map<int,Company*> companies;
extern User* curUser;

FlightWidget::FlightWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FlightWidget)
{
    ui->setupUi(this);
    for(const auto& pr:companies){
        ui->cbxCompanyName->addItem(pr.second->getCompanyName(),QVariant(pr.second->getCompanyID()));
    }
    ui->cbxCompanyName->setCurrentIndex(-1);
    SetTouristMode();

    //创建flightmodel连接所有航班的数据表
    flightmodel=new FlightModel(this);
    flightmodel->init();

    //创建controllerflight用于管理航班
    controllerflight=new ControllerFlight(this,flightmodel);

    //tableFlight关联flightmodel
    ui->tableFlight->setModel(flightmodel);
    ui->tableFlight->setEditTriggers(QAbstractItemView::NoEditTriggers); //禁止在表格中直接编辑
    ui->tableFlight->setSelectionBehavior(QAbstractItemView::SelectRows); //整行选择
    ui->tableFlight->setSelectionMode(QAbstractItemView::SingleSelection); //单选

    //创建flightmodelmapper
    flightmodelmapper=new QDataWidgetMapper(this);
    flightmodelmapper->setModel(flightmodel);
    flightmodelmapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    //映射模型字段到详细信息控件
    flightmodelmapper->addMapping(ui->spxSeatCnt, 3);
    flightmodelmapper->addMapping(ui->txtStartCity, 4);
    flightmodelmapper->addMapping(ui->txtEndCity, 5);
    flightmodelmapper->addMapping(ui->dtmStartTime, 6);
    flightmodelmapper->addMapping(ui->dtmEndTime, 7);
    //绑定表格选择到flightmodelmapper
    connect(ui->tableFlight->selectionModel(),&QItemSelectionModel::currentRowChanged,
            this,&FlightWidget::onFlightSelectionChanged);
}

FlightWidget::~FlightWidget()
{
    delete ui;
    delete flightmodel;
    delete controllerflight;
    delete flightmodelmapper;
}
void FlightWidget::SetTouristMode(){
    ui->cbxCompanyName->setEnabled(false);
    ui->cbxPlaneName->setEnabled(false);
    ui->spxSeatCnt->setReadOnly(true);
    ui->txtStartCity->setReadOnly(true);
    ui->txtEndCity->setReadOnly(true);
    ui->dtmStartTime->setReadOnly(true);
    ui->dtmEndTime->setReadOnly(true);
    ui->btnOrder->hide();
    ui->btnAddFlight->hide();
    ui->btnDeleteFlight->hide();
    ui->btnModifyFlight->hide();
}
void FlightWidget::SetClientMode(const QString& name){
    ui->cbxCompanyName->setEnabled(false);
    ui->cbxPlaneName->setEnabled(false);
    ui->spxSeatCnt->setReadOnly(true);
    ui->txtStartCity->setReadOnly(true);
    ui->txtEndCity->setReadOnly(true);
    ui->dtmStartTime->setReadOnly(true);
    ui->dtmEndTime->setReadOnly(true);
    ui->btnOrder->show();
    ui->btnAddFlight->hide();
    ui->btnDeleteFlight->hide();
    ui->btnModifyFlight->hide();
}
void FlightWidget::SetAdminMode(const QString& name){
    ui->cbxCompanyName->setEnabled(true);
    ui->cbxPlaneName->setEnabled(true);
    ui->spxSeatCnt->setReadOnly(false);
    ui->txtStartCity->setReadOnly(false);
    ui->txtEndCity->setReadOnly(false);
    ui->dtmStartTime->setReadOnly(false);
    ui->dtmEndTime->setReadOnly(false);
    ui->btnOrder->hide();
    ui->btnAddFlight->show();
    ui->btnDeleteFlight->show();
    ui->btnModifyFlight->show();
}
void FlightWidget::onFlightSelectionChanged(const QModelIndex &current, const QModelIndex &previous){
    flightmodelmapper->setCurrentModelIndex(current);

    QString err;
    Flight flight;
    if(!flightmodel->SelectByRow(current.row(),flight,err)){
        QMessageBox::warning(this, "警告", err);
    }

    ui->cbxCompanyName->blockSignals(true);
    int cbxcid=ui->cbxCompanyName->findData(flight.getCompanyID());
    ui->cbxCompanyName->setCurrentIndex(cbxcid);
    ui->cbxCompanyName->blockSignals(false);

    update_cbxPlaneName(flight.getCompanyID());

    qDebug()<<"PlaneID="<<flight.getPlaneID();
    int cbxpid=ui->cbxPlaneName->findData(flight.getPlaneID());
    ui->cbxPlaneName->setCurrentIndex(cbxpid);
}
void FlightWidget::update_cbxPlaneName(int cid){
    ui->cbxPlaneName->clear();
    if(companies.find(cid)!=companies.end()){
        Company* ptr=companies[cid];
        for(const auto& plane:ptr->Planes){
            ui->cbxPlaneName->addItem(plane.getPlaneName(),QVariant(plane.getPlaneID()));
        }
    }
    if(curUser && curUser->getUserType()=="admin" && dynamic_cast<Admin*>(curUser)->getCompanyID()==cid){
        ui->cbxPlaneName->setEnabled(true);
    }
    else{
        ui->cbxPlaneName->setEnabled(false);
    }
}
void FlightWidget::on_cbxCompanyName_currentIndexChanged(int index)
{
    int idx=ui->cbxCompanyName->currentIndex();
    if(idx!=-1){
        int cid=ui->cbxCompanyName->itemData(idx).toInt();
        update_cbxPlaneName(cid);
    }
    else ui->cbxPlaneName->clear();
}
void FlightWidget::on_cbxPlaneName_currentIndexChanged(int index)
{
    int cidx=ui->cbxCompanyName->currentIndex();
    if(cidx==-1){ui->spxSeatCnt->setValue(-1);return;}
    int cid=ui->cbxCompanyName->itemData(cidx).toInt();
    int pidx=ui->cbxPlaneName->currentIndex();
    if(pidx==-1){ui->spxSeatCnt->setValue(-1);return;}
    int pid=ui->cbxPlaneName->itemData(pidx).toInt();
    if(companies.find(cid)==companies.end()){ui->spxSeatCnt->setValue(-1);return;}
    Company* ptr=companies[cid];
    for(const auto& plane:ptr->Planes){
        if(plane.getPlaneID()==pid){ui->spxSeatCnt->setValue(plane.getSeatCnt());return;}
    }
}

void FlightWidget::on_btnAddFlight_clicked()
{
    QString err;
    Flight flight;
    flight.setCompanyID(ui->cbxCompanyName->itemData(ui->cbxCompanyName->currentIndex()).toInt());
    flight.setPlaneID(ui->cbxPlaneName->itemData(ui->cbxPlaneName->currentIndex()).toInt());
    flight.setSeatCnt(ui->spxSeatCnt->value());
    flight.setStartCity(ui->txtStartCity->text().trimmed());
    flight.setEndCity(ui->txtEndCity->text().trimmed());
    QDateTime t1=ui->dtmStartTime->dateTime();
    QDateTime t2=ui->dtmEndTime->dateTime();
    double dur=t1.secsTo(t2)/3600.00;
    flight.setStartTime(t1);
    flight.setEndTime(t2);
    flight.setDuration(dur);
    qDebug()<<"CompanyID="<<flight.getCompanyID()<<",PlaneID="<<flight.getPlaneID();
    if(!flightmodel->AppendRow(flight,err)){
        QMessageBox::warning(this, "警告", err);
    }
    else{
        QMessageBox::information(this, "提示", "航班增加成功！");
    }
}


void FlightWidget::on_btnDeleteFlight_clicked()
{
    QString err;
    QModelIndex viewIndex=ui->tableFlight->currentIndex();
    int viewRow=viewIndex.row();
    if(!flightmodel->RemoveRow(viewRow,err)){
        QMessageBox::warning(this, "警告", err);
    }
    else{
        QMessageBox::information(this, "提示", "航班删除成功！");
    }
}


void FlightWidget::on_btnModifyFlight_clicked()
{
    QString err;
    QModelIndex viewIndex=ui->tableFlight->currentIndex();
    int viewRow=viewIndex.row();
    Flight flight;
    flight.setCompanyID(ui->cbxCompanyName->itemData(ui->cbxCompanyName->currentIndex()).toInt());
    flight.setPlaneID(ui->cbxPlaneName->itemData(ui->cbxPlaneName->currentIndex()).toInt());
    flight.setSeatCnt(ui->spxSeatCnt->value());
    flight.setStartCity(ui->txtStartCity->text().trimmed());
    flight.setEndCity(ui->txtEndCity->text().trimmed());
    QDateTime t1=ui->dtmStartTime->dateTime();
    QDateTime t2=ui->dtmEndTime->dateTime();
    double dur=t1.secsTo(t2)/3600.00;
    flight.setStartTime(t1);
    flight.setEndTime(t2);
    flight.setDuration(dur);
    qDebug()<<"CompanyID="<<flight.getCompanyID()<<",PlaneID="<<flight.getPlaneID();
    if(!flightmodel->ModifyRow(viewRow,flight,err)){
        QMessageBox::warning(this, "警告", err);
    }
    else{
        QMessageBox::information(this, "提示", "航班修改成功！");
    }
}
