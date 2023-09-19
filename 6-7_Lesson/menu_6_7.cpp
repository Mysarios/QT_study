#include "menu_6_7.h"
#include "ui_menu_6_7.h"
#include <QDebug>


Menu_6_7::Menu_6_7(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu_6_7),
    Data(new Json_Data)
{
    ui->setupUi(this);

    Setting = Json_Data::Settings_data("Dima","normal",30,200,200);
    Data.Set_Settings(&Setting);
    Data.Write_Json();

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

}


void Menu_6_7::on_Load_game_clicked()
{

}


void Menu_6_7::on_New_game_clicked()
{

    Main_game* Main_Window_snake = new Main_game(Setting);
    //Main_Window_snake->Setting = Setting;
    Main_Window_snake->show();
    Data.Set_Settings(&Setting);
    Data.Write_Json();
}


void Menu_6_7::on_Settings_clicked()
{

    Settings_Window = new Settings();
    Settings_Window->Data = &Setting;
    Settings_Window->show();
}

