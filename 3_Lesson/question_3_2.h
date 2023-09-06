#ifndef QUESTION_3_2_H
#define QUESTION_3_2_H

#include <QDialog>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintEvent>
#include <random>
#include <QMainWindow>

namespace Ui {
class question_3_2;
}

class question_3_2 : public QDialog
{
    Q_OBJECT

public:
    explicit question_3_2(QWidget *parent = nullptr);
    ~question_3_2();

    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    Ui::question_3_2 *ui;
    QPoint mousePoint;
    QPoint SearchPoint;
    QPen pen;
    QColor color;
    int Red = 0;
    int Blue= 255;
    int MaxDist = 0;
};

#endif // QUESTION_3_2_H
