#include "question_4_3.h"
#include "ui_question_4_3.h"

Question_4_3::Question_4_3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Question_4_3)
{
    ui->setupUi(this);
    Vector_El_Index = 0;
    ui->Site->setReadOnly(1);
    ui->Login->setReadOnly(1);
    ui->Password->setReadOnly(1);

    ui->Create_data->setVisible(0);
    ui->Save_edit->setVisible(0);

    Data_save New_data;
    New_data.Login = "admin";
    New_data.Password = "admin";
    QString Site_name = "Example";

    Vector_site_names.push_back(Site_name);
    Array.insert(Site_name,New_data);

    ui->Site->setText(Vector_site_names[Vector_El_Index]);
    ui->Login->setText(Array.value(Vector_site_names[Vector_El_Index]).Login);
    ui->Password->setText(Array.value(Vector_site_names[Vector_El_Index]).Password);
}

Question_4_3::~Question_4_3()
{
    delete ui;
}

void Question_4_3::on_Create_clicked()
{
    ui->Site->setReadOnly(0);
    ui->Login->setReadOnly(0);
    ui->Password->setReadOnly(0);

    ui->Site->setText("");
    ui->Login->setText("");
    ui->Password->setText("");

    ui->Back->setVisible(0);
    ui->Edit->setVisible(0);
    ui->Next->setVisible(0);
    ui->Create->setVisible(0);
    ui->Create_data->setVisible(1);
}

void Question_4_3::on_Create_data_clicked()
{
    Data_save New_data;
    New_data.Login = ui->Login->text();
    New_data.Password = ui->Password->text();
    QString Site_name = ui->Site->text();

    Vector_site_names.push_back(Site_name);
    Array.insert(Site_name,New_data);

    ui->Back->setVisible(1);
    ui->Edit->setVisible(1);
    ui->Next->setVisible(1);
    ui->Create->setVisible(1);
    ui->Create_data->setVisible(0);

    ui->Site->setReadOnly(1);
    ui->Login->setReadOnly(1);
    ui->Password->setReadOnly(1);

    ui->Site->setText(Vector_site_names[Vector_El_Index]);
    ui->Login->setText(Array.value(Vector_site_names[Vector_El_Index]).Login);
    ui->Password->setText(Array.value(Vector_site_names[Vector_El_Index]).Password);
}


void Question_4_3::on_Next_clicked()
{
    Vector_El_Index++;
    if(Vector_El_Index<Vector_site_names.length()){
        ui->Site->setText(Vector_site_names[Vector_El_Index]);
        ui->Login->setText(Array.value(Vector_site_names[Vector_El_Index]).Login);
        ui->Password->setText(Array.value(Vector_site_names[Vector_El_Index]).Password);
    }else{
       Vector_El_Index = 0;
       ui->Site->setText(Vector_site_names[Vector_El_Index]);
       ui->Login->setText(Array.value(Vector_site_names[Vector_El_Index]).Login);
       ui->Password->setText(Array.value(Vector_site_names[Vector_El_Index]).Password);
    }
}


void Question_4_3::on_Back_clicked()
{
    Vector_El_Index--;
    if(Vector_El_Index >= 0 ){
        ui->Site->setText(Vector_site_names[Vector_El_Index]);
        ui->Login->setText(Array.value(Vector_site_names[Vector_El_Index]).Login);
        ui->Password->setText(Array.value(Vector_site_names[Vector_El_Index]).Password);
    }else{
       Vector_El_Index = Vector_site_names.length()-1;
       ui->Site->setText(Vector_site_names[Vector_El_Index]);
       ui->Login->setText(Array.value(Vector_site_names[Vector_El_Index]).Login);
       ui->Password->setText(Array.value(Vector_site_names[Vector_El_Index]).Password);
    }
}


void Question_4_3::on_Edit_clicked()
{
    ui->Back->setVisible(0);
    ui->Edit->setVisible(0);
    ui->Next->setVisible(0);
    ui->Create->setVisible(0);
    //ui->Create_data->setVisible(0);
    ui->Save_edit->setVisible(1);

    ui->Password->setReadOnly(0);
    ui->Login->setReadOnly(0);
}


void Question_4_3::on_Save_edit_clicked()
{
    Data_save New_data;
    New_data.Login = ui->Login->text();
    New_data.Password = ui->Password->text();
    QString Site_name = ui->Site->text();

    Array[Site_name] = New_data;

    ui->Back->setVisible(1);
    ui->Edit->setVisible(1);
    ui->Next->setVisible(1);
    ui->Create->setVisible(1);
    //ui->Create_data->setVisible(0);
    ui->Save_edit->setVisible(0);

    ui->Password->setReadOnly(1);
    ui->Login->setReadOnly(1);

    ui->Site->setText(Vector_site_names[Vector_El_Index]);
    ui->Login->setText(Array.value(Vector_site_names[Vector_El_Index]).Login);
    ui->Password->setText(Array.value(Vector_site_names[Vector_El_Index]).Password);
}

