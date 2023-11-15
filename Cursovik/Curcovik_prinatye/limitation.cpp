#include "limitation.h"

Limitation::Limitation()
{


}
Limitation::Limitation(QString string){
    parse_string(string);
}

void Limitation::parse_string(QString string){
    QString ch;
    int sign = 1;
    int value = 1;
    QString sybmol;
    QString int_buf = 0;
    QString x_buf = "x";
    QString equal_buf ="";
    bool x_now = false;
    bool equal = false;
    int index = 0;

    foreach(ch,string){
        if(ch == "=" || ch == "<" || ch == ">"){
            Param_val[x_buf] = int_buf.toInt() * sign;
            equal_buf += ch;
            equal = true;
            break;
        }
        if(!equal){
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
        }else{
            if(ch == "="){
                equal_buf += ch;
            }
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
        }
    }
    qDebug()<<sign;
    equal_val = int_buf.toInt() * sign;
    eq
    Param_val[equal_buf] = int_buf.toInt() * sign;

    QMap<QString, int>::iterator it;
    for (it = Param_val.begin(); it != Param_val.end(); ++it) {
        qDebug()<<it.value() <<" "<< it.key();
    }

}
