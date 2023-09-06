#include "question_3_1.h"
#include "ui_question_3_1.h"
#include <iostream>

Question_3_1::Question_3_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Question_3_1)
{
    ui->setupUi(this);
    WidghtWindow = this->size().width();
    HeightWindow = this ->size().height();
    lenghtLine = HeightWindow/2.5;
    Rotation = 90;

}

Question_3_1::~Question_3_1()
{
    delete ui;
}

void Question_3_1::DrawLine(int count, int lenght,int Rotate,int X,int Y,int PenW, QPainter *paint){
    if(count){
        int NewX = X + lenght*cos(Rotate*3.14159/180);
        int NewY = Y - lenght*sin(Rotate*3.14159/180);
        if(!PenW){
            PenW = 1;
        }
        pen.setWidth(PenW);
        paint->setPen(pen);

        paint->drawLine(QLine(X,Y,NewX,NewY));
        DrawLine(count-1,lenght/1.5,Rotate+45,NewX,NewY,PenW-1,paint);
        DrawLine(count-1,lenght/1.5,Rotate-45,NewX,NewY,PenW-1,paint);
    }
    //update();

}
void Question_3_1::paintEvent(QPaintEvent *event){

    QPainter *painter = new QPainter(this);

    int CountIteration = 10;
    color = QColor(255,0,0);
    pen = QPen(color);
    pen.setWidth(10);
    painter->setPen(pen);
    painter->drawLine(QLine(WidghtWindow/2,HeightWindow,WidghtWindow/2,HeightWindow-lenghtLine));

    DrawLine(CountIteration,lenghtLine/2,Rotation+45,WidghtWindow/2,HeightWindow-lenghtLine,8,painter);
    DrawLine(CountIteration,lenghtLine/2,Rotation-45,WidghtWindow/2,HeightWindow-lenghtLine,8,painter);
    painter->end();

}
