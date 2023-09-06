#include "lesson_3.h"
#include "ui_lesson_3.h"

Lesson_3::Lesson_3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lesson_3)
{
    ui->setupUi(this);
    New_Window = nullptr;
}

Lesson_3::~Lesson_3()
{
    delete ui;
}
void Lesson_3::Change_Window()
{

    New_Window->show();
}

void Lesson_3::on_Open_1_Question_clicked()
{
    if(New_Window != nullptr){
        New_Window->deleteLater();
    }
    New_Window = new Question_3_1();
    this->Change_Window();
}


void Lesson_3::on_Open_2_Question_clicked()
{
    if(New_Window != nullptr){
        New_Window->deleteLater();
    }
    New_Window = new question_3_2();
    this->Change_Window();
}


void Lesson_3::on_Open_3_Question_clicked()
{
    if(New_Window != nullptr){
        New_Window->deleteLater();
    }
    New_Window = new Question_3_3();
    this->Change_Window();
}


void Lesson_3::on_Open_4_Question_clicked()
{
    if(New_Window != nullptr){
        New_Window->deleteLater();
    }
    New_Window = new Question_3_4();
    this->Change_Window();
}


void Lesson_3::on_pushButton_2_clicked()
{
    if(New_Window != nullptr){
        New_Window->deleteLater();
    }
    New_Window = new Question_3_5();
    this->Change_Window();
}

