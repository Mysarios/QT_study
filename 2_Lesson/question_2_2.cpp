#include "question_2_2.h"
#include "ui_question_2_2.h"
#include <string>

Question_2_2::Question_2_2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Question_2_2),
    qtimer(new QTimer())
{
    ui->setupUi(this);

    qtime = QTime::currentTime();
    qtimer->setInterval(10);
    connect(qtimer,&QTimer::timeout,this,&Question_2_2::TimerKick);
    qtimer->start();

    connect(this,&Question_2_2::Set_Time,this,&Question_2_2::Set_Time_To_Label);
}

Question_2_2::~Question_2_2()
{
    delete ui;
}
void Question_2_2::TimerKick(){
    emit Set_Time();
}
void Question_2_2::Set_Time_To_Label(){
    std::string Time;

    qtime = qtime.addMSecs(10);
    int hour = qtime.hour();
    int minute = qtime.minute();
    int second = qtime.second();

    Time = std::to_string(hour) + ":" + std::to_string(minute) + ":" + std::to_string(second);

    ui->label->setText(QString::fromStdString(Time));
}



