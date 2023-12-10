#ifndef TETRIS_H
#define TETRIS_H

#include <QMainWindow>
#include <gamefield.h>
#include <QPainter>
#include <QDebug>
#include <QKeyEvent>
#include <figure.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class Tetris;
}
QT_END_NAMESPACE

class Tetris : public QMainWindow {
  Q_OBJECT

 public:
  Tetris(QWidget *parent = nullptr);
  ~Tetris();
  void paintEvent(QPaintEvent *event) override;
  void keyPressEvent(QKeyEvent *event) override;

  void drawField(QPainter*);
  void drawPoint(QPainter*,int,int);
  void setDrawColor(QPainter*,int,int,int);
  void Redraw();
  void showCells();
  void DoStep();
  void drawNextFigure(QPainter*);

private slots:
  void on_pushButton_clicked();

private:
  Ui::Tetris *ui;
  GameField* field;
  QTimer* qtimer;

  QVector<QVector<int>> Field_cells;

  int line_widht = 2;
  int window_h;
  int window_w;
  int top_margin;
  int left_margin;
  int game_price = 0;

  bool firstDraw = false;
  bool ClearAll = true;
};
#endif  // TETRIS_H
