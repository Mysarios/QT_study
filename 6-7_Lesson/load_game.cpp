#include "load_game.h"
#include "ui_load_game.h"
#include <QJsonObject>

Load_game::Load_game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Load_game)
{
    ui->setupUi(this);
    Setting = new Json_Data::Settings_data;
}

Load_game::~Load_game()
{
    delete ui;
}
void Load_game::Load_all_saves(){
    for(int i = 0; i<Names.size();i++){
        ui->comboBox->addItem(Names[i]);
    }

}
void Load_game::set_Names(QVector<QString> n){
    this->Names = n;
}

void Load_game::on_pushButton_clicked()
{
    QString Game_name = ui->comboBox->currentText();
    Json_Data JS_Data;
    QJsonObject buffer_json;
    JS_Data.Read_Json(buffer_json);
    int Get_direction = 0;

    qDebug()<<"Start parse";
    int Score = JS_Data.Parse_by_GameName(buffer_json,*Setting,Body,Fruits,Get_direction,Game_name);

    for(int i = 0;i<Body.size();i++){
        qDebug()<<"Body "<<i<<"  "<<Body[i].x;
    }
    for(int i = 0;i<Fruits.size();i++){
        qDebug()<<"Fruits "<<i<<"  "<<Fruits[i].x;
    }
    qDebug()<<"Start create";
    Body[0].bode_direction = Get_direction;
    qDebug()<<"FD = "<<Get_direction;
    Main_game* Main_Window_snake = new Main_game(*Setting,Fruits,Body);
    qDebug()<<"Set score";
    Main_Window_snake->Set_Score(Score);
    Main_Window_snake->show();
}


