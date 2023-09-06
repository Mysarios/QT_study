#include "question_3_2.h"
#include "ui_question_3_2.h"
#include <iostream>

question_3_2::question_3_2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::question_3_2)
{
    ui->setupUi(this);
    this->setMouseTracking(true);
    SearchPoint.setX(rand() % this->size().width());
    SearchPoint.setY(rand() % this->size().height());
    std::cout<<SearchPoint.x()<<std::endl;
    std::cout<<SearchPoint.y()<<std::endl;

    if(SearchPoint.x() + SearchPoint.y() > this->size().width() - SearchPoint.x() + this->size().height() - SearchPoint.y()){
        MaxDist = SearchPoint.x() + SearchPoint.y();
    }else{
        MaxDist = this->size().width() - SearchPoint.x() + this->size().height() - SearchPoint.y();
    }

    color = QColor(Red,0,Blue);
    pen = QPen(color);
}

question_3_2::~question_3_2()
{
    delete ui;
}
void question_3_2::paintEvent(QPaintEvent *event){
    QPainter *painter = new QPainter(this);

    color = QColor(Red,0,Blue);
    pen = QPen(color);
    pen.setWidth(500);
    painter->setPen(pen);

    painter->drawRect(0,0,this->size().width(),this->size().height());
    Blue = 255*(abs(mousePoint.x() - SearchPoint.x()) + abs(mousePoint.y() - SearchPoint.y()))/ MaxDist;
    Red = 255 - 255*(abs(mousePoint.x() - SearchPoint.x()) + abs(mousePoint.y() - SearchPoint.y()))/ MaxDist;

    if(Blue > 255){ Blue = 255;}
    if(Red > 255){ Red = 255;}
    painter->end();

}
void question_3_2::mouseMoveEvent(QMouseEvent *event){
    mousePoint = event->pos();
    update();
}
