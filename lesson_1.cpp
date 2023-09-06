#include "lesson_1.h"
#include "ui_lesson_1.h"
#include <iostream>

Lesson_1::Lesson_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lesson_1)
{
    ui->setupUi(this);
    New_Window = nullptr;

}

Lesson_1::~Lesson_1()
{
    delete ui;
}

void Lesson_1::on_Open_1_Question_clicked()
{
    if(New_Window != nullptr){
        New_Window->deleteLater();
    }
    New_Window = new Question_1_1();
    this->Change_Window();
}
void Lesson_1::on_Open_2_Question_clicked()
{
    if(New_Window != nullptr){
        New_Window->deleteLater();
    }
    New_Window = new Question_1_2();
    this->Change_Window();
}
void Lesson_1::on_Open_3_Question_clicked()
{
    if(New_Window != nullptr){
        New_Window->deleteLater();
    }
    New_Window = new Question_1_3();
    this->Change_Window();
}
void Lesson_1::on_Open_4_Question_clicked()
{
    if(New_Window != nullptr){
        New_Window->deleteLater();
    }
    New_Window = new Question_4();
    this->Change_Window();
}

void Lesson_1::Change_Window()
{

    New_Window->show();
}


void Lesson_1::on_pushButton_clicked()
{
    this->close();
}





