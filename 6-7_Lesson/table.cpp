#include "table.h"
#include "ui_table.h"
#include <QDebug>
#include <QVector>


Table::Table(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Table)
{
    ui->setupUi(this);

    labels.append(ui->N1);
    labels.append(ui->S1);

    labels.append(ui->N2);
    labels.append(ui->S2);

    labels.append(ui->N3);
    labels.append(ui->S3);

    labels.append(ui->N4);
    labels.append(ui->S4);

    labels.append(ui->N5);
    labels.append(ui->S5);

    labels.append(ui->N6);
    labels.append(ui->S6);

    labels.append(ui->N7);
    labels.append(ui->S7);

    labels.append(ui->N8);
    labels.append(ui->S8);

    labels.append(ui->N9);
    labels.append(ui->S9);

    labels.append(ui->N10);
    labels.append(ui->S10);
}

Table::~Table()
{
    delete ui;
}
bool compare_Result(IndexValue *a,IndexValue *b){
    return (a->value > b->value );
}

QVector<int> Table::sort_array(QVector<int> &Start_array){
    QVector<IndexValue*> result;
    QVector<int> ret_indexes;
    qDebug()<<"start Qsort_1";
    for(int i = 0;i<Start_array.size();i++){
        IndexValue* buf = new IndexValue;
        buf->value = Start_array[i];
        buf->index = i;
        result.append(buf);
    }
    qDebug()<<"start Qsort";
    qSort(result.begin(),result.end(),compare_Result);
    qDebug()<<"end Qsort";

    Start_array.clear();
    for(int i = 0;i<result.size();i++){
        qDebug()<<result[i]->index;
        qDebug()<<result[i]->value;
        Start_array.append(result[i]->value);
        ret_indexes.append(result[i]->index);
    }
    return ret_indexes;
}

void Table::Set_records(){
    qDebug()<<"start records";
    QVector<int> Sort_index = sort_array(Scores);
    qDebug()<<"End sort";
    for(int i = 0;i<Names.size();i++){
        labels[i*2]->setText(Names[Sort_index[i]]);
        labels[i*2+1]->setText(QString::number(Scores[i]));
    }
}
void Table::Set_Data(QVector<QString> n ,QVector<int> s){
    this->Names = n;
    this->Scores = s;
}
