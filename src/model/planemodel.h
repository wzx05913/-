#ifndef PLANEMODEL_H
#define PLANEMODEL_H
#include <QString>
#include "../entity/plane.h"

class PlaneModel
{
public:
    static bool GetPlanesByCompanyID(int cid,std::vector<Plane>& planes,QString& err);
};

#endif // PLANEMODEL_H
