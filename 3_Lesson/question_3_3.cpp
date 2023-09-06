#include "question_3_3.h"
#include "ui_question_3_3.h"

Question_3_3::Question_3_3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Question_3_3)
{
    ui->setupUi(this);

    pixelmap = QPixmap(this->size().width(),this->size().height());
    pixelmap.fill(Qt::white);
    color = QColor(255,0,0);
    Widght = 10;
}

Question_3_3::~Question_3_3()
{
    delete ui;
}

void Question_3_3::mouseMoveEvent(QMouseEvent *event){
    MousePoint = event->pos();
    update();
}

void Question_3_3::paintEvent(QPaintEvent *event){
    if(!MousePoint.isNull()){
        QPainter *painter = new QPainter(&pixelmap);
        painter->setBrush(color);
        painter->setPen(color);
        painter->drawEllipse(QRect(MousePoint.x() - Widght/2,MousePoint.y() - Widght/2,Widght,Widght));
        painter->end();
    }

    QPainter WinPainter(this);
    WinPainter.drawPixmap(10,10,this->size().width(),this->size().height(),pixelmap);
    WinPainter.end();
}

void Question_3_3::on_RedBtn_clicked()
{
    color = QColor(255,0,0);
}


void Question_3_3::on_BlueBtn_clicked()
{
    color = QColor(0,0,255);
}


void Question_3_3::on_GreenBtn_clicked()
{
    color = QColor(0,255,0);
}


void Question_3_3::on_W_5_Btn_clicked()
{
   Widght=5;
}


void Question_3_3::on_W_9_Btn_clicked()
{
    Widght=9;
}


void Question_3_3::on_W_15_Btn_clicked()
{
    Widght=15;
}

