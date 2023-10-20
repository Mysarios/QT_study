#ifndef TABLE_H
#define TABLE_H

#include <QDialog>
#include <QLabel>


struct IndexValue{
    int value;
    int index;
};

namespace Ui {
class Table;
}

class Table : public QDialog
{
    Q_OBJECT

public:
    explicit Table(QWidget *parent = nullptr);
    ~Table();
    void Set_records();
    void Set_Data(QVector<QString>,QVector<int>);
    QVector<int> sort_array(QVector<int> &Start_array);

private:
    Ui::Table *ui;
    QVector<QString> Names;
    QVector<int> Scores;
    QVector<QLabel*> labels;
};

#endif // TABLE_H
