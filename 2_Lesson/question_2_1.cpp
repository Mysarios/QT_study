#include "question_2_1.h"
#include "ui_question_2_1.h"

Question_2_1::Question_2_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Question_2_1)
{
    ui->setupUi(this);
    ResultButton = ui->pushButton;
    connect(ResultButton,&QPushButton::clicked,this,&Question_2_1::Summa_Function);
}

Question_2_1::~Question_2_1()
{
    delete ui;
}
void Question_2_1::Summa_Function(){
    int First_Val = ui->First->text().toInt();
    int Second_Val = ui->Second->text().toInt();

    int Result_Val = First_Val + Second_Val;
    ui->Result->setText(QString::number(Result_Val));
}

void Question_2_1::on_pushButton_2_clicked()
{
    ui->First->setText("");
    ui->Second->setText("");
    ui->Result->setText("");
}

