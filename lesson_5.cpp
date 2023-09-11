#include "lesson_5.h"
#include "ui_lesson_5.h"

lesson_5::lesson_5(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lesson_5)
{
    ui->setupUi(this);
    New_Window = nullptr;
}

lesson_5::~lesson_5()
{
    delete ui;
}

void lesson_5::on_Open_1_Question_clicked()
{
    if(New_Window != nullptr){
        New_Window->deleteLater();
    }
    New_Window = new question_5_1();
    this->Change_Window();
}

void lesson_5::Change_Window(){
    New_Window->show();
}
