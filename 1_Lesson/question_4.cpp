#include "question_4.h"
#include "ui_question_4.h"
#include <QRegExp>
#include <iostream>
#include <string>

Question_4::Question_4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Question_4)
{
    ui->setupUi(this);
}

Question_4::~Question_4()
{
    delete ui;
}

void Question_4::on_Test_Button_clicked()
{
    QString Text = ui->TextBox->text();
    QString Regular = ui->RegularBox->text();

    QRegExp rx(Regular);

    std::cout<<Regular.toStdString()<<std::endl;

    if(rx.indexIn(Text) != -1){
        ui->label->setText("YEEEP");
    }else{
        ui->label->setText("Noope");
    }
}

