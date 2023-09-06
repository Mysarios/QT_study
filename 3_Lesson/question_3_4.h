#ifndef QUESTION_3_4_H
#define QUESTION_3_4_H

#include <QDialog>
#include <QPixmap>
#include <QPainter>
#include <QImage>
#include <QTimer>

namespace Ui {
class Question_3_4;
}

class Question_3_4 : public QDialog
{
    Q_OBJECT

public:
    explicit Question_3_4(QWidget *parent = nullptr);
    ~Question_3_4();

    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
private slots:
    void TimerKick();

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::Question_3_4 *ui;
    int PictIndex;
    QTimer *qtimer;
    int IntervalMSec;
};

#endif // QUESTION_3_4_H
