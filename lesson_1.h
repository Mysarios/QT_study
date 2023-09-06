#ifndef LESSON_1_H
#define LESSON_1_H

#include <QDialog>
#include <1_Lesson/question_1_1.h>
#include <1_Lesson/question_1_2.h>
#include <1_Lesson/question_1_3.h>
#include <1_Lesson/question_4.h>

namespace Ui {
class Lesson_1;
}

class Lesson_1 : public QDialog
{
    Q_OBJECT

public:
    explicit Lesson_1(QWidget *parent = nullptr);
    ~Lesson_1();

private slots:
    void on_Open_1_Question_clicked();
    void on_Open_2_Question_clicked();
    void on_Open_3_Question_clicked();
    void on_pushButton_clicked();
    void Change_Window();





    void on_Open_4_Question_clicked();

private:
    Ui::Lesson_1 *ui;
    QDialog *New_Window;
};

#endif // LESSON_1_H
