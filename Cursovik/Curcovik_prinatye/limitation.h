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
    Limitation(QString);
    void parse_string(QString);
    void show();

private:
    QString equal_type;
    int equal_val;
    QMap<QString,int> Param_val;
    QString nums = "123456789";
};

#endif // LIMITATION_H
