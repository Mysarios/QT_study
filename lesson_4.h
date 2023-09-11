#ifndef LESSON_4_H
#define LESSON_4_H

#include <QDialog>
#include <4_Lesson/question_4_1.h>
#include <4_Lesson/question_4_2.h>
#include <4_Lesson/question_4_3.h>
#include <4_Lesson/question_4_4.h>

namespace Ui {
class Lesson_4;
}

class Lesson_4 : public QDialog
{
    Q_OBJECT

public:
    explicit Lesson_4(QWidget *parent = nullptr);
    ~Lesson_4();

private slots:
    void on_Open_1_Question_clicked();
    void Change_Window();

    void on_Open_2_Question_clicked();

    void on_Open_3_Question_clicked();

    void on_Open_4_Question_clicked();

private:
    Ui::Lesson_4 *ui;
    QDialog *New_Window;
};

#endif // LESSON_4_H
