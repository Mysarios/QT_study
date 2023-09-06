#ifndef QUESTION_3_1_H
#define QUESTION_3_1_H

#include <QDialog>
#include <QPainter>
#include <QColor>
#include <QPen>
#include <cmath>

namespace Ui {
class Question_3_1;
}

class Question_3_1 : public QDialog
{
    Q_OBJECT

public:
    explicit Question_3_1(QWidget *parent = nullptr);
    ~Question_3_1();
    void paintEvent(QPaintEvent *event) override;

private slots:
    void DrawLine(int count, int lenght,int Rotate,int StartX, int StartY,int PenWidht, QPainter *paint);


private:
    Ui::Question_3_1 *ui;
    QPen pen;
    QColor color;
    int HeightWindow = 0;
    int WidghtWindow = 0;
    int lenghtLine = 0;
    int Rotation = 0;

};

#endif // QUESTION_3_1_H
