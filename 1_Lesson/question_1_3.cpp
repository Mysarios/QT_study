#include "question_1_3.h"
#include "ui_question_1_3.h"

Question_1_3::Question_1_3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Question_1_3)
{
    ui->setupUi(this);

    StandartQpalette = ui->Label_1->palette();
    NewQpalette = ui->Label_1->palette();
    NewQpalette.setColor(ui->Label_1->foregroundRole(),Qt::green);
    IndexLabel = 0;
}

Question_1_3::~Question_1_3()
{
    delete ui;
}

void Question_1_3::on_Change_Label_clicked()
{
    ui->Change_Label->setText("Change " +  QString::number(((IndexLabel+1) % 4)+1) + " Label!");
    switch(IndexLabel)
    {
    case 0:
        ui->label_4->setPalette(StandartQpalette);
        ui->Label_1->setPalette(NewQpalette);
        break;
    case 1:
        ui->Label_1->setPalette(StandartQpalette);
        ui->label_2->setPalette(NewQpalette);
        break;
    case 2:
        ui->label_2->setPalette(StandartQpalette);
        ui->label_3->setPalette(NewQpalette);
        break;
    case 3:
        ui->label_3->setPalette(StandartQpalette);
        ui->label_4->setPalette(NewQpalette);
        break;
    }

    IndexLabel = (IndexLabel +1) % 4;
}

