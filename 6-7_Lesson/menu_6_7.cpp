#include "menu_6_7.h"
#include "ui_menu_6_7.h"
#include <QDebug>
#include <QJsonObject>


Menu_6_7::Menu_6_7(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu_6_7),
    Data(new Json_Data)
{
    ui->setupUi(this);

    Setting = new Json_Data::Settings_data("Anonim","Easy",100,600,600);
}

Menu_6_7::~Menu_6_7()
{
    delete ui;
}
void msg(QString text){
    qDebug()<<text;
}
void Menu_6_7::on_Exit_1_clicked()
{

}
void Menu_6_7::on_Exit_2_clicked()
{

}


void Menu_6_7::on_Show_table_clicked()
{
    QVector<QString> Names;
    QVector<int> Scores;
    load_data_to_table(Names,Scores);
    qDebug()<<"Names ="<<Names.size();

    Table_Window = new Table();
    Table_Window->Set_Data(Names,Scores);
    Table_Window->Set_records();
    Table_Window->show();
}

void Menu_6_7::on_Load_game_clicked()
{
    QVector<QString> Names;
    QVector<int> Scores;
    load_data_to_table(Names,Scores);
    qDebug()<<"Names ="<<Names.size();

    Load_game_Window = new Load_game();
    Load_game_Window->set_Names(Names);
    Load_game_Window->Load_all_saves();
    Load_game_Window->show();
}


void Menu_6_7::on_New_game_clicked()
{

    Main_game* Main_Window_snake = new Main_game(*Setting);
    Main_Window_snake->show();
}


void Menu_6_7::on_Settings_clicked()
{
    Settings_Window = new Settings();
    Settings_Window->Data = Setting;
    Settings_Window->show();
}
void Menu_6_7::load_data_to_table(QVector<QString> &Names,QVector<int> &Scores){
    QJsonObject buffer_json;
    Data.Read_Json(buffer_json);
    QVector<Name_Score> Table_Data;
    Data.Parse_to_NameAndScore(buffer_json,Table_Data);

    for(int i = 0;i<Table_Data.size();i++){
        Names.append(Table_Data[i].name);
        Scores.append(Table_Data[i].score);
    }
}

