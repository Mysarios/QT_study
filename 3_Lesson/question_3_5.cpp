#include "question_3_5.h"
#include "ui_question_3_5.h"
#include <iostream>

Question_3_5::Question_3_5(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Question_3_5),
    qtimer(new QTimer())
{
    ui->setupUi(this);

    //update();
    IntervalMSec = ui->spinBox->value();
    qtimer->setInterval(IntervalMSec);
    connect(qtimer,&QTimer::timeout,this,&Question_3_5::TimerKick);
    qtimer->start();


    TypeMove = 0;
    PictIndex = 21;

}

Question_3_5::~Question_3_5()
{
    delete ui;
}
void Question_3_5::TimerKick(){
    update();
}

void Question_3_5::mouseMoveEvent(QMouseEvent *event){

}

void Question_3_5::keyPressEvent(QKeyEvent *event){
    int key=event->key();

    if (key == 16777249) {
        std::cout<<"keyPress CTRL"<<std::endl;
        TypeMove=0;
        PictIndex = 21;
     }
    if (key == 16777251) {
        std::cout<<"keyPress ALT"<<std::endl;
        TypeMove=1;
        PictIndex = 0;
     }

}

void Question_3_5::paintEvent(QPaintEvent *event){
    QPainter *painter = new QPainter(this);
    QPixmap pixmap("C:/QT/QT_Study/3_Lesson/Pictures_src/halloween-skeleton-" + QString::number(PictIndex++) + ".jpg");

    painter->drawPixmap(10,10,this->size().width(),this->size().height(),pixmap);
    painter->end();

    //std::cout<<PictIndex<<std::endl;
    if(TypeMove){
        PictIndex = PictIndex % 20;
    }else{
        if(PictIndex == 40){
           PictIndex = 21;
        }
    }

}

void Question_3_5::on_spinBox_valueChanged(int arg1)
{
   IntervalMSec = ui->spinBox->value();
   qtimer->setInterval(IntervalMSec);
}

