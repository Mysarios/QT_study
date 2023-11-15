#ifndef CRITERIA_H
#define CRITERIA_H

#include <QObject>
#include <QString>
#include <QVector>
#include <QMap>
#include <limitation.h>

class Criteria
{
public:
    Criteria();
    Criteria(QString,QString,double,int);
    void parse_string(QString);
    void add_limits(Limitation);
    void resolve_optima();
    void show();
private:
    double assignment;
    int validate;
    QString min_max;
    QMap<QString,int> Param_val;
    QVector<Limitation> limits_array;
    QString nums = "123456789";
};

#endif // CRITERIA_H
