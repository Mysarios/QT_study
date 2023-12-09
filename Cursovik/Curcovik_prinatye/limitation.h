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
    void parse_string(QString);
    QString show();
    void show(int index);

private:
    QString equal_type;
    int equal_val;
    QMap<QString,int> Param_val;
    QString nums = "0123456789";
};

#endif // LIMITATION_H
