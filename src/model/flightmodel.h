#ifndef FLIGHTMODEL_H
#define FLIGHTMODEL_H
#include <QSqlTableModel>
#include "../entity/flight.h"

class FlightModel:public QSqlTableModel
{
public:
    explicit FlightModel(QObject *parent = nullptr);
    void init();
    bool SelectByRow(int row,Flight& flight,QString& err);
    bool AppendRow(const Flight& flight,QString& err);
    bool RemoveRow(int row,QString& err);
    bool ModifyRow(int row,const Flight&flight,QString& err);
protected:
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};

#endif // FLIGHTMODEL_H
