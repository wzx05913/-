#ifndef CONTROLLERFLIGHT_H
#define CONTROLLERFLIGHT_H
#include <QObject>
#include "../model/flightmodel.h"
class ControllerFlight:public QObject{
    Q_OBJECT
public:
    explicit ControllerFlight(QObject* parent = nullptr,FlightModel *model = nullptr);
    bool AddFlight(const Flight& flight,QString& err);
    bool RemoveFlight(int row,QString& err);
    bool ModifyFlight(int row,const Flight& flight,QString& err);
private:
    FlightModel *flightmodel;
};

#endif // CONTROLLERFLIGHT_H
