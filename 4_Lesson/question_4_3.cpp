#include "question_4_3.h"
#include "ui_question_4_3.h"

Question_4_3::Question_4_3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Question_4_3)
{
    ui->setupUi(this);
}

Question_4_3::~Question_4_3()
{
    delete ui;
}
