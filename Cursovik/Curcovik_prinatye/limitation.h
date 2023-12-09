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

    int Get_ValByKey(QString);
    void parse_string(QString);
    void show(int index);
    QString show();

private:
    QString equal_type;
    int equal_val;
    QMap<QString,int> Param_val;
    QString nums = "0123456789";
};

#endif // LIMITATION_H
