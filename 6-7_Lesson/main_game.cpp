#include "main_game.h"
#include "ui_main_game.h"
#include <random>
#include <iostream>
#include <QtDebug>

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
  qDebug()<<Setting.Widght_field;
  qDebug()<<Setting.High_field;
  this->setFixedSize(Setting.Widght_field,Setting.High_field);
  //this->setBaseSize(Setting.Widght_field,Setting.High_field);
  body[0].x = Setting.Widght_field/2;
  body[0].y = Setting.High_field/2;


  qtimer->setInterval(1000);
  connect(qtimer,&QTimer::timeout,this,&Main_game::GameLoop);
  qtimer->start();
  connect(this,&Main_game::New_iter,this,&Main_game::Next_step_head);
  connect(this,&Main_game::New_iter,this,&Main_game::Update_position);
  connect(this,&Main_game::New_iter,this,&Main_game::Create_fruit);
  connect(this,&Main_game::New_iter,this,&Main_game::Redraw);
}

Main_game::Main_game(Json_Data::Settings_data Sett,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Main_game),
    qtimer(new QTimer())
{
  ui->setupUi(this);
  Setting =Sett;
  qDebug()<<"My_onst";
  ui->pushButton->setVisible(0);
  ui->pushButton->setGeometry(0,0,Setting.Widght_field,Setting.High_field);

  Json_Data::Body_part buf;
  buf.body_id = 0;
  buf.bode_direction = 1;
  buf.body_type = 1;
  buf.down = nullptr;
  buf.next = nullptr;
  body.push_back(buf);
  qDebug()<<Setting.Widght_field;
  qDebug()<<Setting.High_field;
  this->setFixedSize(Setting.Widght_field,Setting.High_field);
  body[0].x = Setting.Widght_field/2;
  body[0].y = Setting.High_field/2;

  if(Setting.Dificult == "Easy"){
    Create_fruit();
    Create_fruit();
    Create_fruit();
  }
  if(Setting.Dificult == "Normal"){
    Create_fruit();
    Create_fruit();
  }
  if(Setting.Dificult == "Hard"){
    Create_fruit();
  }


  qtimer->setInterval(Setting.interval);
  connect(qtimer,&QTimer::timeout,this,&Main_game::GameLoop);
  qtimer->start();
  connect(this,&Main_game::New_iter,this,&Main_game::Update_position);
  connect(this,&Main_game::New_iter,this,&Main_game::Next_step_head);
  //connect(this,&Main_game::New_iter,this,&Main_game::Create_fruit);
  connect(this,&Main_game::New_iter,this,&Main_game::Redraw);
}

Main_game::~Main_game()
{
    delete ui;
}
void Main_game::GameLoop(){
    emit New_iter();
}
void Main_game::Redraw(){
    emit update();
}

void Main_game::Create_fruit(){
    Fruit buf;
    int buf_num = (rand() % int(Setting.Widght_field/20-1));
    buf.x = 20*buf_num;
    buf_num = (rand() % int(Setting.High_field/20-1));
    buf.y = 20*buf_num;
    fruits.push_back(buf);
}
void Main_game::Create_new_body_part(){
    qDebug()<<"New_body num[" + QString::number(body.length()) + "]";

    Json_Data::Body_part buf(&body[0]);
    buf.body_id =  body[body.length()-1].body_id+1;
    qDebug()<<buf.body_id;
    buf.bode_direction = body[body.length()-1].bode_direction;
    buf.body_type = body[body.length()-1].body_type;
    buf.x = body[body.length()-1].x;
    buf.y = body[body.length()-1].y;
    qDebug()<<buf.x;
    buf.next = &body[body.length()-1];
    buf.down = nullptr;

    body.push_back(buf);
}
void Main_game::Check_Eat_fruit(int Head_x, int Head_y,QVector<Fruit> fruts){
    Fruit buf;
    int index = 0;
    foreach(buf,fruts){
        if(Head_x == buf.x && Head_y == buf.y){
            fruits.remove(index);
            score++;
            qtimer->setInterval(Setting.interval - score*1.7);
            ui->label->setText(QString::number(score));
            Create_fruit();
            Create_new_body_part();
            break;
        }
        index++;
    }
}
void Main_game::Check_die(){
   for(int i = 1;i<body.length();i++){
       if(body[0].x == body[i].x && body[0].y == body[i].y){
           qDebug()<<"DIE!";
           qtimer->stop();
           ui->pushButton->setVisible(1);
       }
   }
}

void Main_game::Next_step_head(){
    switch(Keyboard_key){
        case 1:
            body[0].bode_direction = 3;
        break;
        case 2:
            body[0].bode_direction = 2;
        break;
        case 3:
            body[0].bode_direction = 1;
        break;
        case 4:
            body[0].bode_direction = 4;
        break;
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
    if(body[0].x > Setting.Widght_field-20){
       body[0].x=0;
    }
    if(body[0].x < 0){
       body[0].x= Setting.Widght_field;
    }
    if(body[0].y > Setting.Widght_field-20){
       body[0].y=0;
    }
    if(body[0].y < 0){
       body[0].y=Setting.High_field;
    }
    Check_die();
    Check_Eat_fruit(body[0].x,body[0].y,fruits);
}
void Main_game::Update_position(){
    Json_Data::Body_part part;
    for(int i = body.length()-1 ;i>0;i--){
        body[i].x = body[i-1].x;
        body[i].y = body[i-1].y;
        body[i].bode_direction = body[i-1].bode_direction;
    }
}

void Main_game::keyPressEvent(QKeyEvent *event){
    int key=event->key();
    switch(key){
        case 16777235:
            std::cout<<"keyPress up"<<std::endl;
            if(Keyboard_key != 3){
               Keyboard_key =1;
            }

        break;
        case 16777236:
            std::cout<<"keyPress right"<<std::endl;
            if(Keyboard_key != 4){
               Keyboard_key =2;
            }
        break;
        case 16777237:
            std::cout<<"keyPress down"<<std::endl;
            if(Keyboard_key != 1){
               Keyboard_key =3;
            }
        break;
        case 16777234:
            std::cout<<"keyPress left"<<std::endl;
            if(Keyboard_key != 2){
               Keyboard_key =4;
            }
        break;
    }
}
void Draw_body_part(Json_Data::Body_part part,QPainter *painter){
    painter->drawRect(part.x,part.y,20,20);
    //std::cout<<"draw"<<std::endl;
}
void Draw_fruits(QPainter *painter,QVector<Fruit> fruts){
    Fruit buf;
    foreach(buf,fruts){
        painter->drawRect(buf.x,buf.y,20,20);
    }
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
    color = QColor(0,255,0);
    painter->setBrush(color);
    painter->setPen(color);

    Draw_fruits(painter,fruits);
    painter->end();
}


void Main_game::on_pushButton_clicked()
{
    this->close();
}

