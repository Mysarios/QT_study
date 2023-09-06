#ifndef QUESTION_3_3_H
#define QUESTION_3_3_H

#include <QDialog>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintEvent>
#include <QPixmap>

namespace Ui {
class Question_3_3;
}

class Question_3_3 : public QDialog
{
    Q_OBJECT

public:
    explicit Question_3_3(QWidget *parent = nullptr);
    ~Question_3_3();

    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private slots:
    void on_RedBtn_clicked();

    void on_BlueBtn_clicked();

    void on_GreenBtn_clicked();

    void on_W_5_Btn_clicked();

    void on_W_9_Btn_clicked();

    void on_W_15_Btn_clicked();

private:
    Ui::Question_3_3 *ui;
    QPixmap pixelmap;
    QPoint MousePoint;
    QColor color;
    int Widght;
};

#endif // QUESTION_3_3_H
