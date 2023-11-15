#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::check_data_eravn(QString f,QString mm ,QString a,QString v){
    bool result = true;
    if(mm != "Min" || mm !="min" || mm!="max" || mm!="Max"){
        result =false;
    }

    if(!a.toDouble()){
        result = false;
    }

    if(!v.toInt()){
        result = false;
    }
    return result;
}
void MainWindow::on_Add_clicked()
{
    QString main_f = ui->Yrav_l->text();
    QString minmax = ui->MM_l->text();
    QString a = ui->Mis_l->text();
    QString v = ui->V_l->text();
    int b = check_data_eravn(main_f,minmax,a,v);
    qDebug()<<QString::number(b);
    if(b != 0){
        Criteria* buf = new Criteria(main_f,minmax,a.toDouble(),v.toInt());
        buf->show();
    }
}


void MainWindow::on_Clear_clicked()
{
    ui->Yrav_l->clear();
    ui->Min_max->clear();
    ui->Mis_l->clear();
    ui->V_l->clear();
}

