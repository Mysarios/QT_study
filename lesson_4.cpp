#include "lesson_4.h"
#include "ui_lesson_4.h"

Lesson_4::Lesson_4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lesson_4)
{
    ui->setupUi(this);
    New_Window = nullptr;
}

Lesson_4::~Lesson_4()
{
    delete ui;
}

void Lesson_4::on_Open_1_Question_clicked()
{
    if(New_Window != nullptr){
        New_Window->deleteLater();
    }
    New_Window = new Question_4_1();
    this->Change_Window();
}
void Lesson_4::Change_Window(){
    New_Window->show();
}

