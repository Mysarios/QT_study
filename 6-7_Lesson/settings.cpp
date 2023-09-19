#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    ui->Name->setText("Anonim");
}

Settings::~Settings()
{
    delete ui;
}


void Settings::on_Cancel_clicked()
{
    emit on_Accept_clicked();
    this->close();
}
QString Settings::Get_Dificult(){
    QString buf = "none";
    if(ui->D_Easy->isChecked()){
        buf= "Easy";
    }
    if(ui->D_norm->isChecked()){
        buf= "Normal";
    }
    if(ui->D_hard->isChecked()){
        buf= "Hard";
    }
    return buf;
}
int Settings::Get_Speed(){
    int buf = 0;
    if(ui->S_1->isChecked()){
        buf= 100;
    }
    if(ui->S_3->isChecked()){
        buf= 300;
    }
    if(ui->S_5->isChecked()){
        buf= 500;
    }
    return buf;
}


void Settings::on_Accept_clicked()
{
   if(ui->Name->text() == ""){
       Data->Game_name = "Anonim+";
   }else{
       Data->Game_name = ui->Name->text();
   }

   Data->Dificult = Get_Dificult();
   Data->interval = Get_Speed();
   Data->Widght_field = ui->W_size->value();
   Data->High_field = ui->H_size->value();
   this->close();
}

