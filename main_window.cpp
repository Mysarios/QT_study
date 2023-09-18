#include "main_window.h"
#include "ui_main_window.h"

Main_Window::Main_Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Main_Window)
{
    ui->setupUi(this);

    New_Window = nullptr;
}

Main_Window::~Main_Window()
{
    delete ui;
}


void Main_Window::on_Open_Lesson_1_clicked()
{
    if(New_Window != nullptr){
        New_Window->deleteLater();
    }
    New_Window = new Lesson_1();
    this->Change_Window();
}
void Main_Window::Change_Window()
{

    //this->hide();
    New_Window->show();
}


void Main_Window::on_Open_Lesson_2_clicked()
{
    if(New_Window != nullptr){
        New_Window->deleteLater();
    }
    New_Window = new Lesson_2();
    this->Change_Window();
}


void Main_Window::on_pushButton_clicked()
{
    if(New_Window != nullptr){
        New_Window->deleteLater();
    }
    New_Window = new Lesson_3();
    this->Change_Window();
}


void Main_Window::on_pushButton_2_clicked()
{
    if(New_Window != nullptr){
        New_Window->deleteLater();
    }
    New_Window = new Lesson_4();
    this->Change_Window();
}


void Main_Window::on_Open_Lesson_3_clicked()
{
    if(New_Window != nullptr){
        New_Window->deleteLater();
    }
    New_Window = new lesson_5();
    this->Change_Window();
}


void Main_Window::on_Open_Lesson_4_clicked()
{
    if(New_Window != nullptr){
        New_Window->deleteLater();
    }
    New_Window = new Lesson_6();
    this->Change_Window();
}

