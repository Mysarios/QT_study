#include "main_game.h"
#include "ui_main_game.h"
#include <random>

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

  qtimer->setInterval(10);
  connect(qtimer,&QTimer::timeout,this,&Main_game::GameLoop);
  qtimer->start();
  connect(this,&Main_game::New_iter,this,&Main_game::Next_step_head);
  connect(this,&Main_game::New_iter,this,&Main_game::Update_position);
  connect(this,&Main_game::New_iter,this,&Main_game::Create_fruit);
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
}



