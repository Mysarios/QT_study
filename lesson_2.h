#ifndef LESSON_2_H
#define LESSON_2_H

#include <QDialog>
#include <2_Lesson/question_2_1.h>
#include <2_Lesson/question_2_2.h>
#include <2_Lesson/question_2_3.h>
#include <2_Lesson/question_2_4.h>

namespace Ui {
class Lesson_2;
}

class Lesson_2 : public QDialog
{
    Q_OBJECT

public:
    explicit Lesson_2(QWidget *parent = nullptr);
    ~Lesson_2();

private slots:
    void on_Open_1_Question_clicked();
    void on_Open_2_Question_clicked();
    void on_Open_3_Question_clicked();
    void on_Open_4_Question_clicked();
    void Change_Window();

private:
    Ui::Lesson_2 *ui;
    QDialog *New_Window;
};

#endif // LESSON_2_H
