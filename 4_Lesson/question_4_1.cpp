#include "question_4_1.h"
#include "ui_question_4_1.h"
#include <random>
#include <iostream>
#include <QtDebug>

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

QVector<int> Sort_Array(QVector<int> VectorArr)
{
    QVector<int> Vector_buf_Left;
    QVector<int> Vector_buf_Right;
    int Lenght_Max = VectorArr.length();
    int in;
    std::cout<<"Vector ="<<std::endl;
    foreach(in,VectorArr){
        std::cout<<in<<std::endl;
    }


    if(Lenght_Max > 2){
        for( int i = 0;i< Lenght_Max/2;i++){
            Vector_buf_Left.push_back(VectorArr[i]);
            Vector_buf_Right.push_back(VectorArr[i+int(Lenght_Max/2)]);
        }

        if(Lenght_Max % 1 == 1){
            Vector_buf_Right.push_back(VectorArr[Lenght_Max-1]);
        }

        //std::cout<< Vector_buf_Left.length()<<std::endl;
        //std::cout<< Vector_buf_Right.length()<<std::endl;

        QVector<int> Vector_buf = Vector_buf_Left;
        Vector_buf_Left.clear();
        Vector_buf_Left = Sort_Array(Vector_buf);

        Vector_buf.clear();
        Vector_buf = Vector_buf_Right;
        Vector_buf_Right.clear();
        Vector_buf_Right = Sort_Array(Vector_buf);

        std::cout<<"Left ="<<std::endl;
        foreach(in,Vector_buf_Left){
            std::cout<<in<<std::endl;
        }
        std::cout<<"Right ="<<std::endl;
        foreach(in,Vector_buf_Right){
            std::cout<<in<<std::endl;
        }

    }



    if(Lenght_Max == 2){
        QVector<int> Buf = VectorArr;
        VectorArr.clear();
        if(Buf[0] > Buf[1]){
            VectorArr.push_back(Buf[1]);
            VectorArr.push_back(Buf[0]);
        }else{
            VectorArr.push_back(Buf[0]);
            VectorArr.push_back(Buf[1]);
        }
        return VectorArr;
    }



    int index_1 = 0;
    int index_2 = 0;
    VectorArr.clear();

    std::cout<<Vector_buf_Left.length()<<std::endl;
    std::cout<<Vector_buf_Left.length()<<std::endl;

    for( int i = 0;i<Lenght_Max;i++){
        std::cout<<index_1<<std::endl;
        std::cout<<index_2<<std::endl;
        if(index_1 == Vector_buf_Left.length() ){
            VectorArr.push_back(Vector_buf_Right[index_2]);
            index_2++;
            continue;
        }
        if(index_2 == Vector_buf_Right.length()){
            VectorArr.push_back(Vector_buf_Left[index_1]);
            index_1++;
            continue;
        }

        if(Vector_buf_Left[index_1] < Vector_buf_Right[index_2]){
            VectorArr.push_back(Vector_buf_Left[index_1++]);
        }else{
            VectorArr.push_back(Vector_buf_Right[index_2++]);
        }
    }

    return VectorArr;

}
void Question_4_1::on_pushButton_clicked()
{
    SortedVector.push_back(ui->lineEdit->text().toInt());
    ui->label->setText(ui->label->text() +" "+ QString::number(ui->lineEdit->text().toInt()));
}


void Question_4_1::on_pushButton_2_clicked()
{
    SortedVector = Sort_Array(SortedVector);

    QVector<int> Vector_buf;
    QString Text;

    for(int i = 0;i < SortedVector.length();i++){
           Text +=" "+ QString::number(SortedVector[i]);
    }
    ui->label_2->setText(Text);
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

