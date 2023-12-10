#include "figure.h"
#include <QDebug>

Figure::Figure(QObject *parent) : QObject(parent)
{

}
Figure::Figure(int type){
    QVector<int> buf;
    switch(type){
        case 0:
            qDebug()<<"case ="<<type;
            widght = 3;
            high = 2;

            for(int i =0;i<high;i++){
                figure_array.append(buf);
                for(int j =0;j<widght;j++){
                   if(j == 0 && i==0){
                       figure_array[i].append(0);
                       continue;
                   }
                   if(j == 2 && i==0){
                       figure_array[i].append(0);
                       continue;
                   }
                   figure_array[i].append(1);
                }
             }
             break;

        case 1:
         widght = 3;
         high = 1;

         for(int i =0;i<high;i++){
             figure_array.append(buf);
             for(int j =0;j<widght;j++){
                figure_array[i].append(1);
             }
         }
         for(int i =0;i<high;i++){
             for(int j =0;j<widght;j++){
                 qDebug()<<"h ="<<i;
                 qDebug()<<"w ="<<j;
             }
         }

            break;
    case 2:
     widght = 2;
     high = 2;

     for(int i =0;i<high;i++){
         figure_array.append(buf);
         for(int j =0;j<widght;j++){
            figure_array[i].append(1);
         }
     }

        break;
    case 3:
     widght = 1;
     high = 2;

     for(int i =0;i<high;i++){
         figure_array.append(buf);
         for(int j =0;j<widght;j++){
            figure_array[i].append(1);
         }
     }
        break;
    case 4:
     qDebug()<<"case ="<<type;
     widght = 3;
     high = 2;

     for(int i =0;i<high;i++){
         figure_array.append(buf);
         for(int j =0;j<widght;j++){
            if(j == 0 && i==1){
                figure_array[i].append(0);
                continue;
            }
            if(j == 2 && i==1){
                figure_array[i].append(0);
                continue;
            }
            figure_array[i].append(1);
         }
     }
        break;
    }
}
QVector<QVector<int>> Figure::getArray(){
    QVector<QVector<int>> result =this->figure_array;
    qDebug()<<"Get[0][0] ="<<QString::number(figure_array[0][0]);
    return result;
}
int Figure::getHigh(){
    return high;
}
int Figure::getWidght(){
    return widght;
}
