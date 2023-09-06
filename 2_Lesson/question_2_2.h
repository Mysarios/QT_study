#ifndef QUESTION_2_2_H
#define QUESTION_2_2_H

#include <QDialog>
#include <QTimer>
#include <QTime>

namespace Ui {
class Question_2_2;
}

class Question_2_2 : public QDialog
{
    Q_OBJECT

public:
    explicit Question_2_2(QWidget *parent = nullptr);
    ~Question_2_2();

private slots:
    void Set_Time_To_Label();
    void TimerKick();

signals:
    void Set_Time();


private:
    Ui::Question_2_2 *ui;
    QTimer *qtimer;
    QTime qtime;
};

#endif // QUESTION_2_2_H
