#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QWidget>
#include <figure.h>

class GameField : public QWidget {
  Q_OBJECT
 public:
  explicit GameField(QWidget *parent = nullptr);
  GameField(int,int);

 public:
  int GetCellHigh();
  int GetCellWidht();
  int GetCountRows();
  int GetCountColumns();
  int getScore();
  int DeleteFullLines();

  bool CheckLine(int indexLine);
  bool checkStopFigure();
  bool checkMoveSide(int);

  void moveFigure(int);
  void moveFigureDown();
  void GameStep(int&);
  void getField(QVector<QVector<int>>&);
  void SetCells();
  void SetCellSize(int,int);
  void showCells();
  void SetMoveDirection(int);
  Figure* getNextFigure();

  Figure* createFigure(int);

 private:
  int rowsNumber = 0;
  int columnsNumber = 0;

  int cellWidht = 40;
  int cellHigh = 40;

  bool checkStop = true;

  QVector<QVector<int>> cells;
  Figure* activeFigure;
  Figure* nextFigure;
  QVector<QPair<int,int>> figurePoints;
  int score = 0;
};

#endif  // GAMEFIELD_H
