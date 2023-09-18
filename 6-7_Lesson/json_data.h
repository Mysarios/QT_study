#ifndef JSON_DATA_H
#define JSON_DATA_H

#include <QObject>
#include <QVector>

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
        void update(){}
    };
    bool Read_Json();
    bool Write_Json();
    void Set_Settings(Settings_data*);
signals:
private:
    QString File_data = "F:/My Files/Git Files/QT_study/6-7_Lesson/Data_hold/Json_data.json";
    Settings_data* Settings;
};

#endif // JSON_DATA_H
