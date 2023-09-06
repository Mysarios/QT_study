#ifndef LESSON_3_H
#define LESSON_3_H

#include <QDialog>
#include <3_Lesson/question_3_1.h>
#include <3_Lesson/question_3_2.h>
#include <3_Lesson/question_3_3.h>
#include <3_Lesson/question_3_4.h>
#include <3_Lesson/question_3_5.h>

namespace Ui {
class Lesson_3;
}

class Lesson_3 : public QDialog
{
    Q_OBJECT

public:
    explicit Lesson_3(QWidget *parent = nullptr);
    ~Lesson_3();

private slots:
    void on_Open_1_Question_clicked();

    void on_Open_2_Question_clicked();

    void on_Open_3_Question_clicked();

    void on_Open_4_Question_clicked();

    void on_pushButton_2_clicked();
    void Change_Window();

private:
    Ui::Lesson_3 *ui;
    QDialog *New_Window;
};

#endif // LESSON_3_H
