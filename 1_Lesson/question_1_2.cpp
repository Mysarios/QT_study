#include "question_1_2.h"
#include "ui_question_1_2.h"
#include <iostream>

Question_1_2::Question_1_2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Question_1_2)
{
    ui->setupUi(this);

    QPushButton *Secondbtn = ui->Second;
    std::cout<<"Hi"<<std::endl;
    Secondbtn->setGeometry(QRect(QPoint(150,200),QSize(500,250)));
    Secondbtn->setText("Hello, my friend!");
    Secondbtn->setStyleSheet("background-color: red");
}

Question_1_2::~Question_1_2()
{
    delete ui;
}



void Question_1_2::on_First_clicked()
{

}

