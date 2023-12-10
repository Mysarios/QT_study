#include "tetris.h"

#include "ui_tetris.h"
#include <QTimer>

Tetris::Tetris(QWidget *parent) : QMainWindow(parent), ui(new Ui::Tetris) {
  ui->setupUi(this);
  qDebug()<<"Create";

  qtimer = new QTimer;
  qtimer->setInterval(1000);
}

Tetris::~Tetris() { delete ui; }

void Tetris::on_pushButton_clicked()
{
   firstDraw = true;
   field = new GameField(ui->lineEdit->text().toInt()+1,ui->lineEdit_2->text().toInt()+1);
   QVector<int> buf;

   for(int c = 0;c<field->GetCountColumns();c++){
       Field_cells.append(buf);
       for(int r = 0;r<field->GetCountRows();r++){
           Field_cells[c].append(0);
       }
   }
   field->showCells();
   //this->showCells();

   int highField = (field->GetCountColumns()-1) * field->GetCellHigh();
   int widhtField = field->GetCountRows() * field->GetCellWidht();
   top_margin = 50;
   left_margin = 150;
   window_h = highField + top_margin*2;
   window_w = widhtField + left_margin*2;

   ui->label->setVisible(0);
   ui->label_2->setVisible(0);
   ui->lineEdit->setVisible(0);
   ui->lineEdit_2->setVisible(0);
   ui->pushButton->setVisible(0);

   qDebug()<<"Resize";
   this->resize(window_w,window_h);
   qDebug()<<"Redraw_start";
   this->Redraw();
   qDebug()<<"Resize_end";
   connect(qtimer,&QTimer::timeout,this,&Tetris::Redraw);
   connect(qtimer,&QTimer::timeout,this,&Tetris::DoStep);

   qtimer->start();
}
void Tetris::setDrawColor(QPainter* painter,int r, int g, int b){
    QColor color = QColor(r,g,b);
    painter->setBrush(color);
    painter->setPen(color);
}
void Tetris::showCells(){
    QString buf;
    for(int i =0;i<field->GetCountColumns();i++){
        buf ="";
        for(int j =0;j<field->GetCountRows();j++){
            buf += QString::number(Field_cells[i][j]) +" |";
        }
        qDebug()<<"Row "<<i<<" = "<<buf;
    }
}
void Tetris::drawField(QPainter* painter){
    field->getField(Field_cells);
    int countColumn =field->GetCountColumns();
    int countRow = field->GetCountRows();

    qDebug()<<countColumn<<" = "<<countRow;
    for(int column =0 ;column <countColumn-1; column++ ){
        for(int row =0 ;row <countRow; row++ ){
            this->setDrawColor(painter,0,0,0);
            painter->drawRect(left_margin + row*field->GetCellWidht(),window_h - top_margin - column * field->GetCellHigh(),field->GetCellWidht(),field->GetCellHigh());
            this->setDrawColor(painter,255,255,255);
            painter->drawRect(left_margin + row*(field->GetCellWidht()) + line_widht,window_h - top_margin - column * (field->GetCellHigh()) + line_widht,field->GetCellWidht()-line_widht*2,field->GetCellHigh()-line_widht*2);
        }
    }
    return;
}
void Tetris::Redraw(){
    qDebug()<<"Redraw";
    emit update();
}
void Tetris::drawPoint(QPainter* painter,int row, int column){
    this->setDrawColor(painter,0,0,0);
    painter->drawRect(left_margin + row*field->GetCellWidht(),window_h - top_margin - column * field->GetCellHigh(),field->GetCellWidht(),field->GetCellHigh());
    this->setDrawColor(painter,10,50,200);
    painter->drawRect(left_margin + row*(field->GetCellWidht()) + line_widht,window_h - top_margin - column * (field->GetCellHigh()) + line_widht,field->GetCellWidht()-line_widht*2,field->GetCellHigh()-line_widht*2);
}
void Tetris::DoStep(){
    field->GameStep(game_price);
    ui->label_4->setText(QString::number(game_price));
}
void Tetris::paintEvent(QPaintEvent *event){
    QPainter* painter = new QPainter(this);
    if(firstDraw){
        if(ClearAll){
            ClearAll = false;
            this->drawField(painter);
        }else{
            this->drawField(painter);
            this->drawNextFigure(painter);
            int rows = field->GetCountRows();
            int columns = field->GetCountColumns();
            field->getField(Field_cells);
            this->showCells();
            for(int i =0;i<columns-1;i++){
                for(int j =0;j<rows;j++){
                    if(Field_cells[i][j] !=0){
                        drawPoint(painter,j,i);
                    }
                }
            }
        }
    }


    //drawPoint(painter,0,0);
    //drawPoint(painter,1,1);
    painter->end();
}
void Tetris::keyPressEvent(QKeyEvent *event){
    int key = event->key();
    qDebug()<<key;
    switch(key){
        case 83:
            DoStep();
            this->Redraw();
        break;
        case 65:
        //qDebug()<<"Press A";
            field->moveFigure(1);
            this->Redraw();
        break;
        case 68:
            field->moveFigure(2);
            this->Redraw();
        break;

        case 1067:
            DoStep();
            this->Redraw();
        break;
        case 1060:
        //qDebug()<<"Press A";
            field->moveFigure(1);
            this->Redraw();
        break;
        case 1042:
            field->moveFigure(2);
            this->Redraw();
        break;
    }

}
void Tetris::drawNextFigure(QPainter* painter){
    this->setDrawColor(painter,60,10,100);
    painter->drawRect(window_w - 140,20 ,120,120);
}

