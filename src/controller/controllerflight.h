#ifndef CONTROLLERFLIGHT_H
#define CONTROLLERFLIGHT_H
#include <QObject>
#include "../model/flightmodel.h"
class ControllerFlight:public QObject{
    Q_OBJECT
public:
    explicit ControllerFlight(QObject* parent = nullptr,FlightModel *model = nullptr);
private:
    FlightModel *flightmodel;
};

#endif // CONTROLLERFLIGHT_H
