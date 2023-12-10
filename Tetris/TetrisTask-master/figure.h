#ifndef FIGURE_H
#define FIGURE_H

#include <QObject>
#include <QVector>

class Figure : public QObject
{
    Q_OBJECT
public:
    explicit Figure(QObject *parent = nullptr);
    Figure(int);
    QVector<QVector<int>> getArray();
    int getHigh();
    int getWidght();
signals:
private:
    int widght;
    int high;
    int rotate = 0;

    QVector<QVector<int>> figure_array;
};

#endif // FIGURE_H
