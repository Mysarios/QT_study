#include "json_data.h"
#include <QVector>
#include <QJsonObject>
#include <iostream>
#include <QJsonDocument>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QJsonArray>


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
        qDebug()<<"Beb";
    }
    Settings_data(){qDebug()<<"Beb";};
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

bool Json_Data::Parse_to_NameAndScore(QJsonObject Get_Data,QVector<Name_Score>& NameScores_Array){
    QJsonArray Games_Array = Get_Data["Games"].toArray();
    NameScores_Array.clear();
    for(int i = 0; i <Games_Array.size();i++){
        QJsonObject Game = Games_Array[i].toObject();
        QString Name = Game["Name"].toString();
        int Score = Game["Score"].toInt();
        Name_Score buffer;
        buffer.name = Name;
        buffer.score = Score;
        NameScores_Array.append(buffer);
    }
    qDebug()<<"NM = "<<NameScores_Array.size();
    return true;
}
int Json_Data::Parse_by_GameName(QJsonObject Get_Data,Settings_data& settings, QVector<Body_part>& body, QVector<Fruit>& fruits,int& direction,QString name){
    QJsonArray Games_Array = Get_Data["Games"].toArray();
    int i,Result_Score;

    for(i = 0; i <Games_Array.size();i++){
        QJsonObject Game = Games_Array[i].toObject();
        QString Name = Game["Name"].toString();
        qDebug()<<"Search = "<<name<<" Find = "<<Name;
        if(Name == name){
            QJsonObject Settings_Json = Game["Settings"].toObject();
            settings.Game_name = Name;
            settings.Dificult = Settings_Json["Dificult"].toString();
            settings.High_field = Settings_Json["High_field"].toInt();
            settings.Widght_field = Settings_Json["Widght_field"].toInt();
            settings.interval = Settings_Json["interval"].toInt();

            qDebug()<<"Parse Body";
            QJsonArray Body_Array = Game["Body_parts"].toArray();
            body.clear();
            for(int j = 0;j<Body_Array.size();j++){
                Body_part buffer;
                QJsonObject buf_js = Body_Array[j].toObject();
                buffer.x = buf_js["X"].toInt();
                buffer.y = buf_js["Y"].toInt();
                body.append(buffer);
            }

            qDebug()<<"Parse Fruits";
            QJsonArray Fruit_Array = Game["Fruit_coordinates"].toArray();
            fruits.clear();
            for(int j = 0;j<Fruit_Array.size();j++){
                Fruit buffer;
                QJsonObject buf_js = Fruit_Array[j].toObject();
                buffer.x = buf_js["X"].toInt();
                buffer.y = buf_js["Y"].toInt();
                fruits.append(buffer);
            }
            Result_Score = Game["Score"].toInt();
            direction = Game["Direction"].toInt();
            return Result_Score;
        }
    }

}

bool Json_Data::Read_Json(QJsonObject& content){
    QString val;
    QFile file;
    //QJsonObject content;

    file.setFileName(File_data);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();


    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8());
    content = doc.object();

    return true;
}
void Json_Data::update_part(Body_part part){
   part.bode_direction = part.next->bode_direction;
   part.body_type = part.next->body_type;
   part.x = part.next->x;
   part.y = part.next->y;
   //qDebug()<<part.x;
   //qDebug()<<part.y;
   return;
}
bool Json_Data::Write_Json(){
   QJsonObject Last_Content;
   Read_Json(Last_Content);
   QJsonArray Games_Array = Last_Content["Games"].toArray();
   QJsonArray Games_Array_new;
   int i,Result_Score;

   for(i = 0; i <Games_Array.size();i++){
       QJsonObject Game = Games_Array[i].toObject();
       QString Name = Game["Name"].toString();
        if(Name == this->Settings->Game_name){
            continue;
        }
       Games_Array_new.append(Game);
   }

   qDebug()<<"Start write Json";
   //qDebug()<<"name ="<< Settings->Game_name;
   QJsonArray Games = Last_Content["Games"].toArray();
   QJsonObject Settings_Data;
   Settings_Data.insert("Dificult",Settings->Dificult);
   Settings_Data.insert("interval",Settings->interval);
   Settings_Data.insert("Widght_field",Settings->Widght_field);
   Settings_Data.insert("High_field",Settings->High_field);
   qDebug()<<"End write Settings";

   QJsonArray Body_Data;
   //qDebug()<<"Body size = "<<Body_parts.size();
   for(int i = 0;i<Body_parts.size();i++){
       QJsonObject Body_part;
       Body_part.insert("Part",i);
       Body_part.insert("X",Body_parts[i].x);
       Body_part.insert("Y",Body_parts[i].y);
       Body_Data.append(Body_part);
   }
   QJsonArray Fruit_Data;
   //qDebug()<<"Body size = "<<Body_parts.size();
   for(int i = 0;i<fruits.size();i++){
       QJsonObject Fruit;
       Fruit.insert("X",fruits[i].x);
       Fruit.insert("Y",fruits[i].y);
       Fruit_Data.append(Fruit);
   }

   QJsonObject content;
   content.insert( "Settings", Settings_Data );
   content.insert( "Body_parts", Body_Data );
   content.insert( "Fruit_coordinates", Fruit_Data );
   content.insert( "Name",Settings->Game_name);
   content.insert( "Score",this->Score);
   content.insert( "Direction",this->direction);

   Games_Array_new.append(content);
   QJsonObject result;
   result.insert("Games",Games_Array_new);
   QJsonDocument document;
       document.setObject( result );
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
void Json_Data::Set_Body(QVector<Body_part> Bodyes){
    qDebug()<<"Start save";
    Body_parts.clear();
    for(int i = 0;i < Bodyes.size();i++){
        Body_parts.append(Bodyes[i]);
    }
    qDebug()<<"End save";
}
void Json_Data::Set_Fruits(QVector<Fruit> fruits_get){
    qDebug()<<"Start save fruits";
    qDebug()<<"Count fruits = "<<fruits_get.size();
    fruits.clear();
    for(int i = 0;i < fruits_get.size();i++){
        this->fruits.append(fruits_get[i]);
    }
    qDebug()<<"End save fruits";
}
void Json_Data::Set_Score(int s){
    Score = s;
}
void Json_Data::Set_FirstDirection(int d){
    this->direction = d;
}
