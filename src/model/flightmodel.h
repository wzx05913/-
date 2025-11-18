#ifndef FLIGHTMODEL_H
#define FLIGHTMODEL_H
#include <QSqlTableModel>
#include <QSortFilterProxyModel>
#include "../entity/flight.h"

class FlightModel:public QSqlTableModel
{
    Q_OBJECT
public:
    explicit FlightModel(QObject *parent = nullptr);
    void init();
    bool SelectByRow(int row,Flight& flight,QString& err);
    bool AppendRow(const Flight& flight,QString& err);
    bool RemoveRow(int row,QString& err);
    bool ModifyRow(int row,const Flight&flight,QString& err);
    bool CheckAddConflict(const Flight& flight,QString& err)const;//1表示无冲突
    bool CheckUpdConflict(const Flight& flight,QString& err)const;//1表示无冲突
protected:
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};
#endif // FLIGHTMODEL_H
