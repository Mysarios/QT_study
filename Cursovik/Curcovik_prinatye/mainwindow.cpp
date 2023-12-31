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
            Criteria* criter_clear = new Criteria(function,min_max,assigment.toDouble(),validate.toInt());
            Combobox_data = criter->show();
            ui->Kriterii->addItem(Combobox_data);

            criterias.append(criter);
            first_criterias.append(criter_clear);
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
               first_criterias[i]->add_limits(limit);
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
    QMap<QString,double> buffer;
    for(int index = 0;index<criterias.size();index++){
        first_criterias[index]->Get_Result();
        ui->Result->clear();
        for(int i =0;i<limits.size();i++){
            double buf_val = limits[i]->Get_Equal_val();
            QString buf_str = limits[i]->get_basicKey();
            buffer[limits[i]->get_basicKey()] = limits[i]->Get_Equal_val();
            ui->Result->addItem(buf_str +"  = "+ QString::number(buf_val));
            limits[i]->Get_Equal_val();
        }
        for(int i =0;i<first_criterias.size();i++){
            double buf_val = first_criterias[i]->Get_price();
            QString buf_str = "f" + QString::number(i) + " = ";
            ui->Result->addItem(buf_str +"  = "+ QString::number(buf_val));
        }


        Limitation *buf = new Limitation();
        buf->Set_dataFromCriteria(first_criterias[index]->Get_price(),first_criterias[index]->Get_assign(),criterias[index]->getParamVal(),limits.size());
        limits.append(buf);
        QString Combobox_data = buf->show();
        ui->Ogran->addItem(Combobox_data);
        if(index + 1 <criterias.size()){
            first_criterias[index+1]->add_limits(buf);
        }
   }
    ui->Result->clear();
    for(int i =0;i<limits.size();i++){
        double buf_val = limits[i]->Get_Equal_val();
        QString buf_str = limits[i]->get_basicKey();
        ui->Result->addItem(buf_str +"  = "+ QString::number(buf_val));
        limits[i]->Get_Equal_val();
    }

    buffer = first_criterias[first_criterias.size()-1]->getParamVal();
    for(int index = 0;index<criterias.size();index++){
        double buf_val = first_criterias[index]->Get_price_by_Vals(buffer);
        QString buf_str = "f" + QString::number(index) + " = ";
        ui->Result->addItem(buf_str +"  = "+ QString::number(buf_val));
    }



}

