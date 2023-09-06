#include "question_3_4.h"
#include "ui_question_3_4.h"
#include <iostream>

Question_3_4::Question_3_4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Question_3_4),
    qtimer(new QTimer())
{
    ui->setupUi(this);
    PictIndex = 0;
    //update();
    IntervalMSec = ui->spinBox->value();
    qtimer->setInterval(IntervalMSec);
    connect(qtimer,&QTimer::timeout,this,&Question_3_4::TimerKick);
    qtimer->start();

}

Question_3_4::~Question_3_4()
{
    delete ui;
}
void Question_3_4::TimerKick(){
    update();
}

void Question_3_4::mouseMoveEvent(QMouseEvent *event){

}

void Question_3_4::paintEvent(QPaintEvent *event){
    QPainter *painter = new QPainter(this);
    //QPixmap pixmap("/Pictures_src/halloween-skeleton-" + QString::number(PictIndex++) + ".jpg");
    QPixmap pixmap("W:/Study/QT/My_projects/QT_Study/3_Lesson/Pictures_src/halloween-skeleton-" + QString::number(PictIndex++) + ".jpg");

    painter->drawPixmap(10,10,this->size().width(),this->size().height(),pixmap);
    painter->end();

    //std::cout<<PictIndex<<std::endl;
    PictIndex = PictIndex % 52;
}

void Question_3_4::on_spinBox_valueChanged(int arg1)
{
   IntervalMSec = ui->spinBox->value();
   std::cout<<IntervalMSec<<std::endl;
   qtimer->setInterval(IntervalMSec);
}

