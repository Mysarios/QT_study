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

    double Get_price();
    double Get_assign();
    double Get_price_by_Vals(QMap<QString,double>);

    void parse_string(QString);
    void add_limits(Limitation*);
    void resolve_optima();
    void show(int index);
    void show_step();
    void Get_Result();
    void Change_keys(QString Basic_key,QString noneBasic_key);
    void Add_key(QString key);

    QString getMinMax();
    QString show();
    QString Get_key_ValtoBasic();

    QMap<QString,double> getParamVal();
private:
    double assignment;
    int validate;
    double price;

    QString min_max;
    QString nums = "0123456789";

    QMap<QString,double> Param_val;
    QVector<Limitation*> limits_array;
    QVector<QString> keys;
    QVector<QString> NoneBasic_title;
    QVector<QString> Basic_title;
};

#endif // CRITERIA_H
