#include "criteria.h"
#include <QDebug>

Criteria::Criteria()
{

}
Criteria::Criteria(QString string,QString mm,double a,int v){
    min_max = mm;
    parse_string(string);
    assignment = a;
    validate = v;
}
void Criteria::parse_string(QString string){
    QString ch;
    int sign = 1;
    int value = 1;
    QString sybmol;
    QString int_buf = 0;
    QString x_buf = "x";
    bool x_now = false;
    int index = 0;

    foreach(ch,string){
        if(x_now == false){
            if(ch =="-"){
                sign = -1;
            }
            if(ch =="+"){
                sign = 1;
            }
            if(nums.contains(ch)){
                int_buf += ch;
                qDebug()<<int_buf;
            }
            if(ch == "x"){
                x_buf = ch;
                x_now = true;
                continue;
            }
        }else{
            if(ch =="-"){
                Param_val[x_buf] = int_buf.toInt() * sign;
                sign = -1;
                x_now = false;
                int_buf = "";
            }
            if(ch =="+"){
                Param_val[x_buf] = int_buf.toInt() * sign;
                sign = 1;
                x_now = false;
                int_buf = "";
            }
            if(nums.contains(ch)){
                x_buf += ch;
            }
        }
    }
    qDebug()<<sign;
    Param_val[x_buf] = int_buf.toInt() * sign;

    QMap<QString, int>::iterator it;
    for (it = Param_val.begin(); it != Param_val.end(); ++it) {
        qDebug()<<it.value() <<" "<< it.key();
    }
}
void Criteria::add_limits(Limitation l){
    limits_array.append(l);
}
void Criteria::resolve_optima(){

}

void Criteria::show(){
    QString buf = "";

    QMap<QString, int>::iterator it;
    for (it = Param_val.begin(); it != Param_val.end(); ++it) {
        buf += QString::number(it.value()) + it.key();
    }

    qDebug()<<"Function =";
    qDebug()<<buf;
    qDebug()<<"Min/Max =";
    qDebug()<<min_max;
    qDebug()<<"Assigment =";
    qDebug()<<assignment;
    qDebug()<<"Validate =";
    qDebug()<<validate;
}
