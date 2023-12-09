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
    void show(int index);
    void show_step();


    QString show();
    QString Get_key_ValtoBasic();
private:
    double assignment;
    int validate;

    QString min_max;
    QString nums = "0123456789";

    QMap<QString,int> Param_val;
    QVector<Limitation> limits_array;
};

#endif // CRITERIA_H
