#ifndef LIMITATION_H
#define LIMITATION_H

#include <QObject>
#include <QString>
#include <QVector>
#include <QMap>
#include <QDebug>

class Limitation
{
public:
    Limitation();
    Limitation(QString,QString,int);

    double Get_ValByKey(QString);
    double Get_Equal_val();
    double Get_rezerve(QString key);

    void Set_dataFromCriteria(double price,double assign,QMap<QString,double> map,int index_limit);
    void Change_Basic(QString key);
    void Add_Basic(int index_limit);
    void Add_key(QString key);
    void reverse_limit();
    void parse_string(QString);
    void show(int index);
    void New_row(double main_val);
    void New_row_byAnother(Limitation*,QVector<QString>,QString);

    QString show();
    QString get_basicKey();

private:
    double equal_val;
    QString basic_key;

    QString equal_type;
    QString nums = "0123456789";
    QMap<QString,double> Param_val;

};

#endif // LIMITATION_H
