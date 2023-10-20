#ifndef JSON_DATA_H
#define JSON_DATA_H

#include <QObject>
#include <QVector>
#include <QDebug>

struct Fruit{
    int x;
    int y;
};
struct Name_Score{
    QString name;
    int score;
};

class Json_Data : public QObject
{
    Q_OBJECT
public:
    explicit Json_Data(QObject *parent = nullptr);
    struct Settings_data{
        QString Game_name;
        QString Dificult;
        int interval;
        int Widght_field;
        int High_field;
        Settings_data(QString G_N,QString Complex_get, int interv,int w,int h){
            Game_name= G_N;
            Dificult = Complex_get;
            interval = interv;
            Widght_field = w;
            High_field = h;
            qDebug()<<"Create = "<<G_N;
        }
        Settings_data(){}
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
          body_id =  last->body_id+1;
          bode_direction = last->bode_direction;
          body_type = last->body_type;
          next = last;
          down = nullptr;
        }
        Body_part(){}  
    };
    bool Read_Json(QJsonObject&);
    bool Write_Json();
    bool Parse_to_NameAndScore(QJsonObject,QVector<Name_Score>&);
    int Parse_by_GameName(QJsonObject Get_Data,Settings_data&, QVector<Body_part>&, QVector<Fruit>&,int&,QString name);
    void Set_Settings(Settings_data*);
    void Set_Body(QVector<Body_part>);
    void Set_Fruits(QVector<Fruit>);
    void Set_Score(int);
    void Set_FirstDirection(int);

signals:

public slots:
    void update_part(Body_part);
private:
    QString File_data = "F:/My Files/Git Files/QT_study/6-7_Lesson/Data_hold/Json_data.json";
    Settings_data* Settings;
    QVector<Body_part> Body_parts;
    QVector<Fruit> fruits;
    int Score;
    int direction;
};

#endif // JSON_DATA_H
