#ifndef FLIGHTWIDGET_H
#define FLIGHTWIDGET_H

#include <QWidget>
#include <QDataWidgetMapper>
#include "../model/flightmodel.h"
#include "../controller/controllerflight.h"

namespace Ui {
class FlightWidget;
}

class FlightWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FlightWidget(QWidget *parent = nullptr);
    ~FlightWidget();
private:
    void update_cbxPlaneName(int cid);
public slots:
    void SetTouristMode();
    void SetAdminMode(const QString& name);
    void SetClientMode(const QString& name);
private slots:
    void onFlightSelectionChanged(const QModelIndex &current, const QModelIndex &previous);
    void on_cbxCompanyName_currentIndexChanged(int index);
    void on_cbxPlaneName_currentIndexChanged(int index);
    void on_btnAddFlight_clicked();
    void on_btnDeleteFlight_clicked();
    void on_btnModifyFlight_clicked();

private:
    Ui::FlightWidget *ui;
    FlightModel *flightmodel;
    ControllerFlight *controllerflight;
    QDataWidgetMapper *flightmodelmapper;
};

#endif // FLIGHTWIDGET_H
