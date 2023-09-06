#include "question_2_4.h"
#include "ui_question_2_4.h"
#include <string>
#include <vector>
#include <iostream>
#include <QThread>

Question_2_4::Question_2_4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Question_2_4)
{
    ui->setupUi(this);

    connect(ui->PB_0,&QPushButton::clicked,this,[=](){Question_2_4::Add_Symbol("0");});
    connect(ui->PB_1,&QPushButton::clicked,this,[=](){Question_2_4::Add_Symbol("1");});
    connect(ui->PB_2,&QPushButton::clicked,this,[=](){Question_2_4::Add_Symbol("2");});
    connect(ui->PB_3,&QPushButton::clicked,this,[=](){Question_2_4::Add_Symbol("3");});
    connect(ui->PB_4,&QPushButton::clicked,this,[=](){Question_2_4::Add_Symbol("4");});
    connect(ui->PB_5,&QPushButton::clicked,this,[=](){Question_2_4::Add_Symbol("5");});
    connect(ui->PB_6,&QPushButton::clicked,this,[=](){Question_2_4::Add_Symbol("6");});
    connect(ui->PB_7,&QPushButton::clicked,this,[=](){Question_2_4::Add_Symbol("7");});
    connect(ui->PB_8,&QPushButton::clicked,this,[=](){Question_2_4::Add_Symbol("8");});
    connect(ui->PB_9,&QPushButton::clicked,this,[=](){Question_2_4::Add_Symbol("9");});

    connect(ui->PB_Dev,&QPushButton::clicked,this,[=](){Question_2_4::Add_Symbol("/");});
    connect(ui->PB_Mul,&QPushButton::clicked,this,[=](){Question_2_4::Add_Symbol("*");});
    connect(ui->PB_Plu,&QPushButton::clicked,this,[=](){Question_2_4::Add_Symbol("+");});
    connect(ui->PB_Min,&QPushButton::clicked,this,[=](){Question_2_4::Add_Symbol("-");});

    connect(ui->Clear,&QPushButton::clicked,this,[=](){Question_2_4::Get_Result(1);});
    connect(ui->PB_Res,&QPushButton::clicked,this,[=](){Question_2_4::Get_Result(2);});

}

Question_2_4::~Question_2_4()
{
    delete ui;
}
float Get_Result_Exp(QString exp){
    std::string Expression = exp.toStdString();
    std::string s;
    int i;
    std::vector<float> Number_Array;
    std::vector<std::string> Symbol_Array;

    std::vector<float> Buffer_Number_Array;
    std::vector<std::string> Buffer_Symbol_Array;

    int Indicator_New_Num = 1;
    int NumberBuffer;
    float Result = 0;

    foreach(s,Expression){
        if(s == "/" || s == "*" || s == "-" || s == "+"){
            Symbol_Array.push_back(s);
            if(NumberBuffer != -1){
                Number_Array.push_back(NumberBuffer);
                NumberBuffer = -1;
                Indicator_New_Num = 1;
            }
            continue;
        }
        if(Indicator_New_Num){
            NumberBuffer = std::stoi(s);
            Indicator_New_Num = 0;
        }else{
            NumberBuffer = NumberBuffer*10 + std::stoi(s);
        }
    }
    if(NumberBuffer != -1){
        Number_Array.push_back(NumberBuffer);
        NumberBuffer = -1;
        Indicator_New_Num = 1;
    }

    int Has_Prioritet_Expression;
    std::cout<<"Start Calc"<<std::endl;

    do{
        Has_Prioritet_Expression = 0;
        foreach(s,Symbol_Array){
            if(s == "/" || s== "*"){
                Has_Prioritet_Expression = 1;
            }
        }

        int Last_Prioritet_Symbol = 0;
        if(Has_Prioritet_Expression){
            int index = 0;

            foreach(s,Symbol_Array){
                if(s == "+" || s== "-"){
                    Buffer_Number_Array.push_back(Number_Array[index]);
                    Buffer_Symbol_Array.push_back(s);
                    Last_Prioritet_Symbol=0;
                    index++;
                    continue;
                }

                if(Last_Prioritet_Symbol){
                    Buffer_Number_Array.push_back(Number_Array[index]);
                    Buffer_Symbol_Array.push_back(s);
                    Last_Prioritet_Symbol=0;
                }else{
                    if(s == "/"){
                       Buffer_Number_Array.push_back(Number_Array[index] / Number_Array[index+1]);
                       index++;
                       Last_Prioritet_Symbol=1;
                    }
                    if(s == "*"){
                       Buffer_Number_Array.push_back(Number_Array[index] * Number_Array[index+1]);
                       index++;
                       Last_Prioritet_Symbol=1;
                    }
                }
                index++;
            }
            Number_Array = Buffer_Number_Array;
            Symbol_Array = Buffer_Symbol_Array;
            Buffer_Number_Array.clear();
            Buffer_Symbol_Array.clear();
        }
    }while(Has_Prioritet_Expression != 0);

    int index = 1;
    Result = Number_Array[0];

    foreach(s,Symbol_Array){
        if(s == "+"){
           Result += Number_Array[index];
           index++;
        }
        if(s == "-"){
           Result -= Number_Array[index];
           index++;
        }
    }

    return Result;
}
void Question_2_4::Add_Symbol(QString symbol){
    ui->Expression->setText(ui->Expression->text() + symbol);
}
void Question_2_4::Get_Result(int key){
    switch(key){
    case 1:
        ui->Expression->setText("");
        ui->Result->setText("");
        break;
    case 2:

        float Result = Get_Result_Exp(ui->Expression->text());
        ui->Expression->setText("");

        ui->Result->setText(QString::number(Result));
        break;
    }
}

