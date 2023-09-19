#include "json_data.h"
#include <QVector>
#include <QJsonObject>
#include <iostream>
#include <QJsonDocument>
#include <QFile>
#include <QTextStream>
#include <QDebug>


Json_Data::Json_Data(QObject *parent) : QObject(parent)
{

}

struct Settings_data{
    QString Game_name;
    QString Dificult;
    int interval;
    int Widght_field;
    int High_field;
    Settings_data(QString G_N,QString Complex, int interv,int w,int h){
        Game_name= G_N;
        Dificult = Complex;
        interval = interv;
        Widght_field = w;
        High_field = h;
    }
    Settings_data(){};
};


struct Body_part{
    int body_id;
    int bode_direction;
    int body_type;
    int x;
    int y;
    Body_part* next;
    Body_part* down;
    Body_part(Body_part* last){
      qDebug()<<"Last= "<<last->x;
      body_id =  last->body_id+1;
      bode_direction = last->bode_direction;
      body_type = last->body_type;
      x = last->x;
      y = last->y;
      next = last;
      down = nullptr;
    }
    Body_part(){};
};

bool Json_Data::Read_Json(){

}
void Json_Data::update_part(Body_part part){
   part.bode_direction = part.next->bode_direction;
   part.body_type = part.next->body_type;
   part.x = part.next->x;
   part.y = part.next->y;
   qDebug()<<part.x;
   qDebug()<<part.y;
   return;
}
bool Json_Data::Write_Json(){

   QJsonObject Settings_Data;
   Settings_Data.insert("Name",Settings->Game_name);
   Settings_Data.insert("Dificult",Settings->Dificult);
   Settings_Data.insert("interval",QString::number(Settings->interval));
   Settings_Data.insert("Widght_field",QString::number(Settings->Widght_field));
   Settings_Data.insert("High_field",QString::number(Settings->High_field));
   QJsonObject content;
   content.insert( "Settings", Settings_Data );

   QJsonDocument document;
       document.setObject( content );
       QByteArray bytes = document.toJson( QJsonDocument::Indented );
       QFile file(File_data);
       if( file.open( QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate ) )
       {
           QTextStream iStream( &file );
           iStream.setCodec( "utf-8" );
           iStream << bytes;
           file.close();
       }
       else
       {
           std::cout << "file open failed: " << File_data.toStdString() << std::endl;
           return false;
       }
  return true;
}

void Json_Data::Set_Settings(Settings_data *data){
    qDebug()<<"Start create";
    this->Settings = new Settings_data;
    this->Settings->Game_name = data->Game_name;
    this->Settings->Dificult = data->Dificult;
    this->Settings->interval = data->interval;
    this->Settings->Widght_field = data->Widght_field;
    this->Settings->High_field = data->High_field;
    qDebug()<<"End create";
}
