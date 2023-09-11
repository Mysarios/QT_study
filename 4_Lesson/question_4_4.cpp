#include "question_4_4.h"
#include "ui_question_4_4.h"
#include <random>
#include <QtDebug>

Question_4_4::Question_4_4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Question_4_4)
{
    ui->setupUi(this);
    Vector_El_Index = 0;
    ui->Site->setReadOnly(1);
    ui->Login->setReadOnly(1);
    ui->Password->setReadOnly(1);

    ui->Create_data->setVisible(0);
    ui->Save_edit->setVisible(0);
    ui->Random_pass->setVisible(0);
    ui->checkBox->setVisible(0);
    ui->checkBox_2->setVisible(0);
    ui->checkBox_3->setVisible(0);
    ui->checkBox_4->setVisible(0);
    ui->lineEdit->setVisible(0);

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

Question_4_4::~Question_4_4()
{
    delete ui;
}

void Question_4_4::on_Create_clicked()
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

void Question_4_4::on_Create_data_clicked()
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


void Question_4_4::on_Next_clicked()
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


void Question_4_4::on_Back_clicked()
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


void Question_4_4::on_Edit_clicked()
{
    ui->Back->setVisible(0);
    ui->Edit->setVisible(0);
    ui->Next->setVisible(0);
    ui->Create->setVisible(0);

    ui->Random_pass->setVisible(1);
    ui->checkBox->setVisible(1);
    ui->checkBox_2->setVisible(1);
    ui->checkBox_3->setVisible(1);
    ui->checkBox_4->setVisible(1);
    ui->lineEdit->setVisible(1);
    ui->lineEdit->setText(QString::number(5));

    //ui->Create_data->setVisible(0);
    ui->Save_edit->setVisible(1);

    ui->Password->setReadOnly(0);
    ui->Login->setReadOnly(0);
}


void Question_4_4::on_Save_edit_clicked()
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

    ui->Random_pass->setVisible(0);
    ui->checkBox->setVisible(0);
    ui->checkBox_2->setVisible(0);
    ui->checkBox_3->setVisible(0);
    ui->checkBox_4->setVisible(0);
    ui->lineEdit->setVisible(0);

    ui->Password->setReadOnly(1);
    ui->Login->setReadOnly(1);

    ui->Site->setText(Vector_site_names[Vector_El_Index]);
    ui->Login->setText(Array.value(Vector_site_names[Vector_El_Index]).Login);
    ui->Password->setText(Array.value(Vector_site_names[Vector_El_Index]).Password);
}

void Question_4_4::on_Random_pass_clicked()
{
    bool Check_1 = ui->checkBox->isChecked();
    bool Check_2 = ui->checkBox_2->isChecked();
    bool Check_3 = ui->checkBox_3->isChecked();
    bool Check_4 = ui->checkBox_4->isChecked();
    int MinSize = ui->lineEdit->text().toInt();
    int size;

    if(Check_4){
        size = MinSize + (rand() % (30-MinSize));
    }else{
         size = rand() % (30);
    }

    QString Password;
    qDebug()<<"Size"<<size;

    for(int i = 0 ; i< size; i++){
        qDebug()<<"Step"<<i<<" Password = "<<Password;
        int check = 1;
        int key;
        do{
            key = rand() % 4;
            //qDebug()<<key<<" "<<check;

            if(key == 0 && Check_1){
                check = 0;
            }
            if(key == 1 && Check_2){
                check = 0;
            }
            if(key == 2 && Check_3){
                check = 0;
            }
            if(key == 3){
                check = 0;
            }

        }while(check);

        switch(key){
            case 0:
                Password += char(65 + rand() % (90-65));
        break;
            case 1:
                Password += char(48 + rand() % (57-48));
        break;
            case 2:
                Password += char(35 + rand() % (47-35));
        break;
            case 3:
                Password += char(97 + rand() % (122-97));
        break;
        }
    }
    ui->Password->setText(Password);

}

