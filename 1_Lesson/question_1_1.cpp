#include "question_1_1.h"
#include "ui_question_1_1.h"
#include <iostream>
#include <QString>

Question_1_1::Question_1_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Question_1_1)
{
    ui->setupUi(this);
}

Question_1_1::~Question_1_1()
{
    delete ui;
}

void Question_1_1::on_Right_To_Left_clicked()
{
    ui->Left_Box->setValue(ui->Right_Box->text().toInt());
}


void Question_1_1::on_Left_To_Rgiht_clicked()
{
    std::cout<<ui->Left_Box->value()<<std::endl;
    ui->Right_Box->setText(QString::number(ui->Left_Box->value()));
}

