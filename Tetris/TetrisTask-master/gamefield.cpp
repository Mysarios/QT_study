#include "gamefield.h"

#include <QDebug>
#include <random>

GameField::GameField(QWidget *parent) : QWidget{parent} {

}
GameField::GameField(int row,int column){
    this->rowsNumber = row;
    this->columnsNumber = column;
    QVector<int> buf;

    for(int c = 0;c<column;c++){
        cells.append(buf);
        for(int r = 0;r<row;r++){
            cells[c].append(0);
        }
    }
    qDebug() << rowsNumber << " " << columnsNumber << "|";
    int indexFigure = rand() % 5;
    nextFigure = this->createFigure(indexFigure);
}



bool GameField::checkStopFigure(){
    bool stop = false;
    int size = figurePoints.size();
    for(int i =0;i<size;i++){
        //qDebug()<<"figurePoints["<<i<<"] = "<<figurePoints[i].first;
        if(figurePoints[i].first == 0){
            stop = true;
        }
    }
    if(!stop){
        int maxDeepFigure =100;
        for(int i =0;i<size;i++){
            if(figurePoints[i].first < maxDeepFigure){
                maxDeepFigure =figurePoints[i].first;
            }
        }
        for(int i =0;i<size;i++){
            if(cells[figurePoints[i].first-1][figurePoints[i].second] && figurePoints[i].first-1 != maxDeepFigure){
                stop = true;
            }
        }
    }
    return stop;
}
bool GameField::CheckLine(int indexLine){
    bool deleteCheck = true;

    for(int i = 0;i < rowsNumber;i++){
        if(cells[indexLine][i] == 0){
            deleteCheck = false;
        }
    }

    return deleteCheck;
}
bool GameField::checkMoveSide(int dir){
    bool cantMove = true;
    int size = figurePoints.size();
    switch(dir){
        case 1:
        for(int i =0;i<size;i++){
            qDebug()<<"figurePoints["<<i<<"] = "<<figurePoints[i].second;
            if(figurePoints[i].second == 0){
                cantMove = false;
                return cantMove;
            }
        }
        break;
    case 2:
        for(int i =0;i<size;i++){
            qDebug()<<"figurePoints["<<i<<"] = "<<figurePoints[i].second;
            if(figurePoints[i].second == rowsNumber-1){
                cantMove = false;
                return cantMove;
            }
        }
    break;
    }
    return cantMove;
}

Figure* GameField::getNextFigure(){
    return nextFigure;
}
void GameField::GameStep(int& price){


    if(checkStop){
        price += this->DeleteFullLines();
        int indexFigure = rand() % 5;
        activeFigure = nextFigure;
        nextFigure = this->createFigure(indexFigure);
        QVector<QVector<int>> getVectorPoints = activeFigure->getArray();
        QPair<int,int> pair_buf;

        int columnPointStart =columnsNumber- 1;
        int rowPointStart =rowsNumber -rowsNumber/2.0 ;

        int highFigure = activeFigure->getHigh();
        int wightFigure = activeFigure->getWidght();
        figurePoints.clear();

        for(int i = 0;i <highFigure; i++){
            for(int j = 0;j <wightFigure; j++){
                if(getVectorPoints[i][j] !=0){
                    pair_buf.first = columnPointStart-i;
                    pair_buf.second = rowPointStart+j;
                    cells[columnPointStart-i][rowPointStart+j] = 1;
                    figurePoints.append(pair_buf);
                }
            }
        }
        checkStop = false;
    }else{
        //qDebug()<<"move";
        this->moveFigureDown();
        checkStop = checkStopFigure();
        //qDebug()<<checkStop;
    }
}
void GameField::moveFigureDown(){
    int size = figurePoints.size();
    for(int i =0;i<size;i++){
        cells[figurePoints[i].first][figurePoints[i].second] = 0;
    }
    for(int i =0;i<size;i++){
        figurePoints[i].first -=1;
    }
    for(int i =0;i<size;i++){
        cells[figurePoints[i].first][figurePoints[i].second] = 1;
    }
}
void GameField::moveFigure(int dir){
    bool canMove = checkMoveSide(dir);
    if(canMove){
        int size = figurePoints.size();
        switch(dir){
            case 1: //left
                for(int i =0;i<size;i++){
                    cells[figurePoints[i].first][figurePoints[i].second] = 0;
                    figurePoints[i].second -=1;
                    cells[figurePoints[i].first][figurePoints[i].second] = 1;
                }
            break;
        case 2:     //right
            for(int i =size-1;i>=0;i--){
                cells[figurePoints[i].first][figurePoints[i].second] = 0;
                figurePoints[i].second +=1;
                cells[figurePoints[i].first][figurePoints[i].second] = 1;
            }
        break;
        }
    }
}
void GameField::showCells(){
    QString buf;
    for(int i =columnsNumber-1;i > 0;i--){
        buf ="";
        for(int j =rowsNumber -1;j>0;j--){
            buf += QString::number(cells[i][j]) +" |";
        }
        qDebug()<<"Row "<<i<<" = "<<buf;
    }
}
void GameField::getField(QVector<QVector<int>> &array){
    for (int i =0;i< columnsNumber ;i++ ) {
        for (int j =0;j< rowsNumber ;j++ ) {
          array[i][j] = cells[i][j];
        }
    }
    return;
}

Figure* GameField::createFigure(int type){
    return new Figure(type);
}

int GameField::GetCellHigh(){
    return cellHigh;
}
int GameField::GetCellWidht(){
    return cellWidht;
}
int GameField::GetCountColumns(){
    int result =columnsNumber;
    return result;
}
int GameField::GetCountRows(){
    int result =rowsNumber;
    return result;
}
int GameField::DeleteFullLines(){
    bool buf;
    int price =0;
    for(int i = 0;i<columnsNumber;i++){
        buf = CheckLine(i);
        qDebug()<<"Line "<<i<<"is "<<buf;
        if(buf){
            price+=1;
            for(int j =0;j<rowsNumber;j++){
               cells[i][j] = 0;
            }

            for(int indexNextRows = i;indexNextRows < columnsNumber-1;indexNextRows++){
                for(int j =0;j<rowsNumber;j++){
                   cells[indexNextRows][j] = cells[indexNextRows+1][j];
                }
            }
            i--;
        }
    }
    return price*price;
}

