#include "main_game.h"
#include "ui_main_game.h"
#include <random>
#include <iostream>

Main_game::Main_game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Main_game),
    qtimer(new QTimer())
{
  ui->setupUi(this);
  Json_Data::Body_part buf;
  buf.body_id = 0;
  buf.bode_direction = 1;
  buf.body_type = 1;
  buf.down = nullptr;
  buf.next = nullptr;
  body.push_back(buf);
  this->setBaseSize(Setting.Widght_field,Setting.High_field);


  qtimer->setInterval(10);
  connect(qtimer,&QTimer::timeout,this,&Main_game::GameLoop);
  qtimer->start();
  connect(this,&Main_game::New_iter,this,&Main_game::Next_step_head);
  connect(this,&Main_game::New_iter,this,&Main_game::Update_position);
  connect(this,&Main_game::New_iter,this,&Main_game::Create_fruit);
  connect(this,&Main_game::New_iter,this,&Main_game::paintEvent);
}

Main_game::~Main_game()
{
    delete ui;
}
void Main_game::GameLoop(){
    emit New_iter();
}
void Main_game::Next_step_head(){
    switch(Keyboard_key){
        case 1:
        break;
    }
}
void Main_game::Create_fruit(){

}

void Main_game::Update_position(){
    Json_Data::Body_part part;
    for(int i = 1;i<body.length();i++){
        body[i].update();
    }
    switch(body[0].bode_direction){
        case 1:
            body[0].y +=20;
        break;
        case 2:
            body[0].x +=20;
        break;
        case 3:
            body[0].y -=20;
        break;
        case 4:
            body[0].x -=20;
        break;
    }
}

void Main_game::keyPressEvent(QKeyEvent *event){
    int key=event->key();

    if (key == 16777249) {
        std::cout<<"keyPress CTRL"<<std::endl;
     }
    if (key == 16777251) {
        std::cout<<"keyPress ALT"<<std::endl;
     }

}
void Draw_body_part(Json_Data::Body_part part,QPainter *painter){
    painter->drawRect(part.x,part.y,20,20);
}

void Main_game::paintEvent(QPaintEvent *event){
    QPainter *painter = new QPainter(this);
    QColor color = QColor(255,0,0);
    painter->setBrush(color);
    painter->setPen(color);

    Json_Data::Body_part part;
    for(int i = 0;i<body.length();i++){
        Draw_body_part(body[i],painter);
    }

    painter->end();
}




