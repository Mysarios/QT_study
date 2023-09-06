#ifndef QUESTION_2_3_H
#define QUESTION_2_3_H

#include <QDialog>
#include <QTimer>
#include <QTime>

namespace Ui {
class Question_2_3;
}

class Question_2_3 : public QDialog
{
    Q_OBJECT

public:
    explicit Question_2_3(QWidget *parent = nullptr);
    ~Question_2_3();

private slots:
    void on_pushButton_clicked();
    void Set_Label_Time(QString);
    void Add_Time_Clocks();
    void Add_Time_Timer();
    void End_Timer();
    void Set_Color(int);

signals:
    void Signal_To_Clock(QString);
    void Signal_To_Timer(QString);



private:
    Ui::Question_2_3 *ui;
    QTimer *qtimer;
    QTime qtime_counter;
    QTime qtime_wait;
    QTime qtime;
    QPushButton *btn;
};

#endif // QUESTION_2_3_H
