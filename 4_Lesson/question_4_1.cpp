#include "question_4_1.h"
#include "ui_question_4_1.h"
#include <random>

Question_4_1::Question_4_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Question_4_1)
{
    ui->setupUi(this);
}

Question_4_1::~Question_4_1()
{
    delete ui;
}

void Sort_Array(QVector<int> VectorArr,int FirstIndex,int LastIndex)
{
    if(LastIndex <= FirstIndex){ return;}
    QVector<int> Vector_buf = VectorArr;
    int MiddleIndex =FirstIndex + (LastIndex - FirstIndex)/2;
    Sort_Array(Vector_buf,FirstIndex,MiddleIndex);
    Sort_Array(Vector_buf,MiddleIndex+1,LastIndex);



}
void Question_4_1::on_pushButton_clicked()
{
    SortedVector.push_back(ui->lineEdit->text().toInt());
    ui->label->setText(ui->label->text() +" "+ QString::number(ui->lineEdit->text().toInt()));
}


void Question_4_1::on_pushButton_2_clicked()
{

}


void Question_4_1::on_pushButton_3_clicked()
{
    QVector<int> Vector_buf;
    QString Text;

    for(int i = SortedVector.length();i>0;i--){
        int Index = rand() % i;
        Vector_buf.push_back(SortedVector[Index]);
        Text +=" "+ QString::number(SortedVector[Index]);
        SortedVector.remove(Index);
    }

    SortedVector = Vector_buf;
    ui->label->setText(Text);


}

