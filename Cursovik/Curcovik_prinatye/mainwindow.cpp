#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->O_Equal_num_label->setVisible(0);
    ui->O_Equal_t_label->setVisible(0);
    ui->O_Equal_val->setVisible(0);
    ui->O_Eque_Sym_Combobox->setVisible(0);
    ui->O_function_edit->setVisible(0);
    ui->O_function_label->setVisible(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::check_data_Crit(QString f,QString mm ,QString a,QString v){
    bool result = true;
    if(mm != "Min" && mm !="min" && mm!="max" && mm!="Max"){
        qDebug()<<"MinMax";
        result =false;
    }

    if(!a.toDouble()){
        qDebug()<<"toDouble";
        result = false;
    }

    if(!v.toInt()){
        qDebug()<<"toInt";
        result = false;
    }
    return result;
}
bool MainWindow::check_data_Ogran(QString f,QString val){
    if(val == ""){
        return false;
    }
    if(f == ""){
        return false;
    }
    return true;
}
void MainWindow::on_Add_clicked(){
    bool krit = ui->radioButton_2->isChecked();

    if(krit){
        QString function = ui->C_function_edit->text();
        QString min_max = ui->C_Min_Max_edit->text();
        QString assigment = ui->C_Assigment_edit->text();
        QString validate = ui->C_Validate_edit->text();

        int Krit_flag = check_data_Crit(function,min_max,assigment,validate);

        QString Combobox_data ="";
        if(Krit_flag != 0){
            Criteria* criter = new Criteria(function,min_max,assigment.toDouble(),validate.toInt());
            Combobox_data = criter->show();
            ui->Kriterii->addItem(Combobox_data);

            criterias.append(criter);
            for(int i =0;i<criterias.size();i++){
               qDebug()<<i;
               criterias[i]->show(i+1);
            }
        }
    }else{
        QString function = ui->O_function_edit->text();
        QString value = ui->O_Equal_val->text();
        QString Equal_type = ui->O_Eque_Sym_Combobox->currentText();

        qDebug()<<function;
        qDebug()<<value;
        qDebug()<<Equal_type;

        int Krit_flag = check_data_Ogran(function,value);

        QString Combobox_data ="";
        if(Krit_flag != 0){
            Limitation* limit = new Limitation(function,Equal_type,value.toInt());
            Combobox_data = limit->show();
            ui->Ogran->addItem(Combobox_data);

            limits.append(limit);
            for(int i =0;i<limits.size();i++){
               limits[i]->show(i+1);
            }
            for(int i =0;i<criterias.size();i++){
               criterias[i]->add_limits(limit);
            }
        }
    }
}


void MainWindow::on_Clear_clicked()
{
    ui->C_function_edit->clear();
    ui->C_Validate_edit->clear();
    ui->C_Min_Max_edit->clear();
    ui->C_Assigment_edit->clear();

    ui->O_function_edit->clear();
    ui->O_Equal_val->clear();
}


void MainWindow::on_radioButton_2_clicked()
{
    //Click krit
    ui->O_Equal_num_label->setVisible(0);
    ui->O_Equal_t_label->setVisible(0);
    ui->O_Equal_val->setVisible(0);
    ui->O_Eque_Sym_Combobox->setVisible(0);
    ui->O_function_edit->setVisible(0);
    ui->O_function_label->setVisible(0);

    ui->C_Assigment_edit->setVisible(1);
    ui->C_Assigment_label->setVisible(1);
    ui->C_Min_Max_edit->setVisible(1);
    ui->C_Min_max_label->setVisible(1);
    ui->C_Validate_edit->setVisible(1);
    ui->C_Validate_label->setVisible(1);
    ui->C_function_edit->setVisible(1);
    ui->C_function_label->setVisible(1);
}


void MainWindow::on_radioButton_clicked()
{
    //Click ogran
    ui->C_Assigment_edit->setVisible(0);
    ui->C_Assigment_label->setVisible(0);
    ui->C_Min_Max_edit->setVisible(0);
    ui->C_Min_max_label->setVisible(0);
    ui->C_Validate_edit->setVisible(0);
    ui->C_Validate_label->setVisible(0);
    ui->C_function_edit->setVisible(0);
    ui->C_function_label->setVisible(0);

    ui->O_Equal_num_label->setVisible(1);
    ui->O_Equal_t_label->setVisible(1);
    ui->O_Equal_val->setVisible(1);
    ui->O_Eque_Sym_Combobox->setVisible(1);
    ui->O_function_edit->setVisible(1);
    ui->O_function_label->setVisible(1);
}


void MainWindow::on_Get_result_clicked()
{
    criterias[0]->Get_Result();
}

