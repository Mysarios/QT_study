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
    price = 0;
}
void Criteria::Change_keys(QString Basic_key, QString noneBasic_key){

    for(int i =0;i<Basic_title.size();i++){
        if(Basic_title[i] == Basic_key){
            Basic_title[i] = noneBasic_key;
        }
    }
    for(int i =0;i<NoneBasic_title.size();i++){
        if(NoneBasic_title[i] == noneBasic_key){
            NoneBasic_title[i] = Basic_key;
        }
    }
}
double Criteria::Get_price_by_Vals(QMap<QString, double> map){
    double result = 0;
    QString buf = "";
    foreach(buf,map){
        result+= Param_val[buf]*map[buf];
    }
    return result;
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
    //qDebug()<<sign;
    if(int_buf.toInt() == 0){
        int_buf = "1";
    }
    Param_val[x_buf] += int_buf.toInt() * sign;

    QMap<QString, double>::iterator it;
    for (it = Param_val.begin(); it != Param_val.end(); ++it) {
        //qDebug()<<it.value() <<" "<< it.key();
    }
}
void Criteria::add_limits(Limitation* l){
    limits_array.append(l);
}
void Criteria::resolve_optima(){

}

QMap<QString,double> Criteria::getParamVal(){
    return this->Param_val;
}
QString Criteria::getMinMax(){
    return this->min_max;
}
double Criteria::Get_assign(){
    return this->assignment;
}
QString Criteria::show(){
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

    /*qDebug()<<"Function =";
    qDebug()<<buf;
    qDebug()<<"Min/Max =";
    qDebug()<<min_max;
    qDebug()<<"Assigment =";
    qDebug()<<assignment;
    qDebug()<<"Validate =";
    qDebug()<<validate;*/

    Result += QString::number(validate) + " | " + QString::number(assignment) + " | " + buf+ " -> " + min_max;
    return Result;

}
QString Criteria::Get_key_ValtoBasic(){
    QString key;
    int search_val = 0;
    QString search_key = "none";

    foreach(key,NoneBasic_title){
        if(this->min_max == "max"){
            if(search_val < Param_val[key]){
                search_val = Param_val[key];
                search_key = key;
            }
        }else{
            if(search_val > Param_val[key]){
                search_val = Param_val[key];
                search_key = key;
            }
        }
    }
    return search_key;
}

void Criteria::show(int index){
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

    Result +="Criteria_" +QString::number(index) +" "+ buf+ " -> " + min_max;
    qDebug()<<Result;
}
void Criteria::show_step(){
    qDebug()<<"Cont limits ="<<limits_array.size();
    QMap<QString, double>::iterator it;
    QString print_str = "Basic: |";
    QString buf;

    foreach(buf,keys){
        print_str +=buf + " | ";
    }
    qDebug()<<print_str;
    print_str = "";

    for(int i = 0;i<limits_array.size();i++){
        QString print_str = Basic_title[i] + "    : |";
        foreach(buf,keys){
            double buf_val =limits_array[i]->Get_ValByKey(buf);
            //qDebug()<<"Get_val = "<<buf_val;
            print_str += QString::number(buf_val) + "  | ";
        }
        print_str +=QString::number(limits_array[i]->Get_Equal_val());
        qDebug()<<print_str;
    }

    print_str = "z    : |";

    for (it = Param_val.begin(); it != Param_val.end(); ++it) {
        print_str +=QString::number(it.value()) + "  | ";
    }
    print_str +=QString::number(this->price);
    qDebug()<<print_str;


}
void Criteria::Add_key(QString key){
    Param_val[key] = 0;
    keys.append(key);
}
void Criteria::Get_Result(){
    //Запись всех переменных
    QMap<QString, double>::iterator it;
    for (it = Param_val.begin(); it != Param_val.end(); ++it) {
        keys.append(it.key());
    }

    //Запись всех xi для не базовых
    QString buf;
    foreach(buf,keys){
        NoneBasic_title.append(buf);
    }

    // Добавление базовых
    for(int i = 0;i<limits_array.size();i++){
        limits_array[i]->Add_Basic(i+1);
        this->Add_key(limits_array[i]->get_basicKey());
    }

    //Запись всех yi для вывода
    for(int i = 0;i<limits_array.size();i++){
        Basic_title.append(limits_array[i]->get_basicKey());
    }
    qDebug()<<"All keys ="<<keys;
    qDebug()<<"Start Basic title ="<<Basic_title;
    qDebug()<<"Start None Basic title ="<<NoneBasic_title;

    bool end =0;

    //Симплекс метод
    while(!end){
        this->show_step();

        //поиск критерия -> базисные
        QString basic_key = this->Get_key_ValtoBasic();
        if(basic_key == "none"){
            end =1;
            break;
        }

        int index_FromBasic = 0;
        double min_fromBasic = limits_array[0]->Get_rezerve(basic_key);
        for(int i = 1;i<limits_array.size();i++){
            double rezerve = limits_array[i]->Get_rezerve(basic_key);
            if(rezerve != 0 && rezerve >0 && min_fromBasic >rezerve){
                qDebug()<<i<<" res ="<<rezerve;
                min_fromBasic = rezerve;
                index_FromBasic = i;
            }
        }
        QString noneBasic_key = Basic_title[index_FromBasic];
        qDebug()<<"Basic ="<<basic_key<<" none Basic ="<<noneBasic_key;
        this->Change_keys(noneBasic_key,basic_key);

        //поиск нового базисного решения
        double main_val = limits_array[index_FromBasic]->Get_ValByKey(basic_key);

        limits_array[index_FromBasic]->Change_Basic(basic_key);
        qDebug()<<"main val = "<<main_val;
        limits_array[index_FromBasic]->New_row(main_val);
        for(int i = 0;i<limits_array.size();i++){
            if(i != index_FromBasic){
                limits_array[i]->New_row_byAnother(limits_array[index_FromBasic],keys,basic_key);
            }
        }
        double coef_main = Param_val[basic_key];
        qDebug()<<"Coef for main ="<<coef_main;
        foreach(buf,keys){
            this->Param_val[buf] -= coef_main*limits_array[index_FromBasic]->Get_ValByKey(buf);
        }
        this->price += coef_main*limits_array[index_FromBasic]->Get_Equal_val();
        this->show_step();

    }
}

double Criteria::Get_price(){
    return price;
}
