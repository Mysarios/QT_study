#include "limitation.h"

Limitation::Limitation()
{


}
Limitation::Limitation(QString string,QString Equal_type,int value){
    this->equal_type = Equal_type;
    this->equal_val = value;
    parse_string(string);
}

void Limitation::New_row_byAnother(Limitation * anotherLimit, QVector<QString> keys, QString get_key){
    double new_coef = Param_val[get_key];

    QMap<QString, double>::iterator it;
    for (it = Param_val.begin(); it != Param_val.end(); ++it) {
        it.value() -= new_coef*anotherLimit->Get_ValByKey(it.key());
    }
    this->equal_val -= new_coef*anotherLimit->Get_Equal_val();
}
void Limitation::parse_string(QString string){
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
                //qDebug()<<int_buf;
            }
            if(ch == "x"){
                x_buf = ch;
                x_now = true;
                continue;
            }
        }else{
            if(ch =="-"){
                if(int_buf.toInt() == 0){
                    int_buf = "1";
                }
                Param_val[x_buf] += int_buf.toInt() * sign;
                sign = -1;
                x_now = false;
                int_buf = "";
            }
            if(ch =="+"){
                if(int_buf.toInt() == 0){
                    int_buf = "1";
                }
                Param_val[x_buf] += int_buf.toInt() * sign;
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
    if(int_buf.toInt() == 0){
        int_buf = "1";
    }
    Param_val[x_buf] += int_buf.toInt() * sign;

    QMap<QString, double>::iterator it;
    for (it = Param_val.begin(); it != Param_val.end(); ++it) {
        qDebug()<<it.value() <<" "<< it.key();
    }

}
void Limitation::reverse_limit(){
    QMap<QString, double>::iterator it;
    for (it = Param_val.begin(); it != Param_val.end(); ++it) {
        it.value() *= -1;
    }

}
void Limitation::Add_key(QString key){
    Param_val[key] = 0;
}
void Limitation::Add_Basic(int index_limit){
    basic_key = 'y'+ QString::number(index_limit);
    if(this->equal_type == ">="){
        this->reverse_limit();
        this->equal_type = "<=";
    }
    Param_val[basic_key] = 1;
}
void Limitation::show(int index){
    QString buf = "";
    QString Result = "";
    QString sign = "";

    QMap<QString, double>::iterator it;
    for (it = Param_val.begin(); it != Param_val.end(); ++it) {
        if(it.value() > 0){
            sign = "+";
        }else{
            sign = "";
        }
        buf +=sign + QString::number(it.value()) + it.key();
    }

    Result +="Limit_" +QString::number(index) +" "+  buf +"  "+ equal_type + "  " + QString::number(equal_val);
    qDebug()<<Result;
}
void Limitation::New_row(double main_val){
    qDebug()<<"New row main_val ="<<main_val;
    QMap<QString, double>::iterator it;
    for (it = Param_val.begin(); it != Param_val.end(); ++it) {

        it.value() = double(it.value()/main_val);
        qDebug()<<it.key()<<" = "<<it.value()<<" == "<<double(it.value()/main_val);
    }
    this->equal_val =double(this->equal_val/main_val);
}

double Limitation::Get_ValByKey(QString key){
    double val =Param_val[key];
    return val;
}
double Limitation::Get_Equal_val(){
    return this->equal_val;
}

double Limitation::Get_rezerve(QString key){
    double result = 0;
    result = double(equal_val/Param_val[key]);
    return result;
}

QString Limitation::show(){
    QString buf = "";
    QString Result = "";
    QString sign = "";

    QMap<QString, double>::iterator it;
    for (it = Param_val.begin(); it != Param_val.end(); ++it) {
        if(it.value() > 0){
            sign = "+";
        }else{
            sign = "";
        }
        buf +=sign + QString::number(it.value()) + it.key();
    }

    qDebug()<<"Function =";
    qDebug()<<buf;
    qDebug()<<"Equal type =";
    qDebug()<<this->equal_type;
    qDebug()<<"Equal value =";
    qDebug()<<this->equal_val;

    Result +=  buf +"  "+ equal_type + "  " + QString::number(equal_val);
    return Result;

}
QString Limitation::get_basicKey(){
    return this->basic_key;
}


