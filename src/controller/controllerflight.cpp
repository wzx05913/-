#include "controllerflight.h"

ControllerFlight::ControllerFlight(QObject* parent,FlightModel *model)
    : QObject(parent),flightmodel(model){}
