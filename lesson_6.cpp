#include "lesson_6.h"
#include "ui_lesson_6.h"

Lesson_6::Lesson_6(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lesson_6)
{
    ui->setupUi(this);
    New_Window = nullptr;
}

Lesson_6::~Lesson_6()
{
    delete ui;
}

void Lesson_6::on_pushButton_clicked()
{
    if(New_Window != nullptr){
        New_Window->deleteLater();
    }
    New_Window = new Menu_6_7();
    New_Window->show();
}

