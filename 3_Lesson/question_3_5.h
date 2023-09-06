#ifndef QUESTION_3_5_H
#define QUESTION_3_5_H

#include <QDialog>
#include <QPixmap>
#include <QPainter>
#include <QImage>
#include <QTimer>
#include <QKeyEvent>


namespace Ui {
class Question_3_5;
}

class Question_3_5 : public QDialog
{
    Q_OBJECT

public:
    explicit Question_3_5(QWidget *parent = nullptr);
    ~Question_3_5();

    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void TimerKick();
    void on_spinBox_valueChanged(int arg1);

private:
    Ui::Question_3_5 *ui;
    int PictIndex;
    QTimer *qtimer;
    int IntervalMSec;
    int TypeMove;
};

#endif // QUESTION_3_5_H
