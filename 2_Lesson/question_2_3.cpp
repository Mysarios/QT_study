#include "question_2_3.h"
#include "ui_question_2_3.h"
#include <string>
#include <iostream>

Question_2_3::Question_2_3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Question_2_3),
    qtimer(new QTimer())
{
    ui->setupUi(this);
    btn = ui->pushButton;
    btn->setStyleSheet("background-color: blue");

    qtime_wait = QTime(0,0,4);
    qtime = QTime::currentTime();

    qtimer->setInterval(10);
    connect(qtimer,&QTimer::timeout,this,&Question_2_3::Add_Time_Clocks);
    qtimer->start();

    connect(this,&Question_2_3::Signal_To_Clock,this,&Question_2_3::Set_Label_Time);
    connect(this,&Question_2_3::Signal_To_Timer,this,&Question_2_3::Set_Label_Time);
}


Question_2_3::~Question_2_3()
{
    delete ui;
}

void Question_2_3::on_pushButton_clicked()
{
    qtime_counter = QTime(ui->lineEdit->text().toInt(),ui->lineEdit_2->text().toInt(),ui->lineEdit_3->text().toInt());
    ui->lineEdit->setText("0");
    ui->lineEdit_2->setText("0");
    ui->lineEdit_3->setText("0");

    disconnect(qtimer,&QTimer::timeout,this,&Question_2_3::Add_Time_Clocks);
    connect(qtimer,&QTimer::timeout,this,&Question_2_3::Add_Time_Timer);
}

void Question_2_3::Add_Time_Clocks(){

    std::string Time;

    qtime = qtime.addMSecs(10);
    int hour = qtime.hour();
    int minute = qtime.minute();
    int second = qtime.second();

    Time = std::to_string(hour) + ":" + std::to_string(minute) + ":" + std::to_string(second);

    emit Signal_To_Clock(QString::fromStdString(Time));
}
void Question_2_3::Set_Label_Time(QString Time_str){
    ui->label->setText(Time_str);
}

void Question_2_3::Add_Time_Timer(){

    std::string Time;


    int hour = qtime_counter.hour();
    int minute = qtime_counter.minute();
    int second = qtime_counter.second();

    if((hour+minute+second) != 0){
        qtime_counter = qtime_counter.addMSecs(-10);
    }else{
        Question_2_3::End_Timer();
    }

    Time = std::to_string(hour) + ":" + std::to_string(minute) + ":" + std::to_string(second);
    emit Signal_To_Clock(QString::fromStdString(Time));

}
void Question_2_3::End_Timer(){

    std::cout<<qtime_wait.second()<<std::endl;

    if(qtime_wait.second() == 0){
        Set_Color(2);
        qtime = QTime::currentTime();
        disconnect(qtimer,&QTimer::timeout,this,&Question_2_3::Add_Time_Timer);
        connect(qtimer,&QTimer::timeout,this,&Question_2_3::Add_Time_Clocks);
        qtime_wait = QTime(0,0,4);
    }else{
        Set_Color(1);
        qtime_wait = qtime_wait.addMSecs(-10);
    }

}
void Question_2_3::Set_Color(int key){
    switch(key){
    case 1:
         btn->setStyleSheet("background-color: red");
         break;
    case 2:
         btn->setStyleSheet("background-color: blue");
         break;
    }
}
