#include "lesson_2.h"
#include "ui_lesson_2.h"

Lesson_2::Lesson_2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lesson_2)
{
    ui->setupUi(this);
    New_Window = nullptr;
}

Lesson_2::~Lesson_2()
{
    delete ui;
}

void Lesson_2::on_Open_1_Question_clicked()
{
    if(New_Window != nullptr){
        New_Window->deleteLater();
    }
    New_Window = new Question_2_1();
    this->Change_Window();
}
void Lesson_2::on_Open_2_Question_clicked()
{
    if(New_Window != nullptr){
        New_Window->deleteLater();
    }
    New_Window = new Question_2_2();
    this->Change_Window();
}
void Lesson_2::on_Open_3_Question_clicked()
{
    if(New_Window != nullptr){
        New_Window->deleteLater();
    }
    New_Window = new Question_2_3();
    this->Change_Window();
}
void Lesson_2::on_Open_4_Question_clicked()
{
    if(New_Window != nullptr){
        New_Window->deleteLater();
    }
    New_Window = new Question_2_4();
    this->Change_Window();
}

void Lesson_2::Change_Window()
{

    New_Window->show();
}

