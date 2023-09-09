#include "question_4_2.h"
#include "ui_question_4_2.h"
#include <QDebug>

Question_4_2::Question_4_2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Question_4_2)
{
    ui->setupUi(this);

    Deal New_buf;
    New_buf.Title = "First deal";
    New_buf.Text = "Here u can read main text";
    Main_list.push_back(New_buf);

    Now_it = Main_list.begin();
    Now_Deal = 1;

    ui->Save->setVisible(1);
    ui->Cancel->setVisible(0);

    ui->Create->setVisible(0);
    ui->Last->setVisible(0);
    ui->Next->setVisible(0);
    ui->Delete->setVisible(0);
    ui->Number->setText("1");
    ui->Max->setText("/ 1");
}

Question_4_2::~Question_4_2()
{
    delete ui;
}
struct Deal{
    QString Title;
    QString Text;
};

void Question_4_2::on_Create_clicked()
{
    ui->Title->setText("");
    ui->Main_text->setText("");

    ui->Save->setVisible(1);
    ui->Cancel->setVisible(1);

    ui->Create->setVisible(0);
    ui->Last->setVisible(0);
    ui->Next->setVisible(0);
    ui->Delete->setVisible(0);
}
void Question_4_2::on_Save_clicked()
{
    Deal New_buf;
    New_buf.Title = ui->Title->text();
    New_buf.Text = ui->Main_text->text();
    Main_list.push_back(New_buf);
    Max_size++;
    ui->Max->setText("/ " + QString::number(Max_size));

    ui->Save->setVisible(0);
    ui->Cancel->setVisible(0);

    ui->Create->setVisible(1);
    ui->Last->setVisible(1);
    ui->Next->setVisible(1);
    ui->Delete->setVisible(1);

    QString Buf = Now_it->Title;
    ui->Title->setText(Now_it->Title);
    ui->Main_text->setText(Now_it->Text);
}
void Question_4_2::on_Cancel_clicked()
{
    ui->Save->setVisible(0);
    ui->Cancel->setVisible(0);

    ui->Create->setVisible(1);
    ui->Last->setVisible(1);
    ui->Next->setVisible(1);
    ui->Delete->setVisible(1);


    ui->Title->setText(Now_it->Title);
    ui->Main_text->setText(Now_it->Text);
}

void Question_4_2::on_Last_clicked()
{
    Now_Deal--;
    Now_it--;
    if(Now_it != Main_list.begin()-1){
        ui->Title->setText(Now_it->Title);
        ui->Main_text->setText(Now_it->Text);
    }else{
       Now_it++;
       Now_Deal++;
    }
    ui->Number->setText(QString::number(Now_Deal));
}

void Question_4_2::on_Next_clicked()
{
    Now_Deal++;
    Now_it++;
    if(Now_it != Main_list.end()){
        ui->Title->setText(Now_it->Title);
        ui->Main_text->setText(Now_it->Text);
    }else{
       Now_it--;
       Now_Deal--;
    }
    ui->Number->setText(QString::number(Now_Deal));
}


void Question_4_2::on_Delete_clicked()
{
    Main_list.erase(Now_it++);


    Max_size--;
    ui->Max->setText("/ " + QString::number(Max_size));

    if(Now_it != Main_list.end()){
        ui->Title->setText(Now_it->Title);
        ui->Main_text->setText(Now_it->Text);
        QString Buf = Now_it->Title;
        qDebug()<<Buf;
    }else{
       Now_it--;
       Now_Deal--;
       ui->Number->setText(QString::number(Now_Deal));
       ui->Title->setText(Now_it->Title);
       ui->Main_text->setText(Now_it->Text);
       QString Buf = Now_it->Title;
       qDebug()<<Buf;
    }

}

