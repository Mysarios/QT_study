#ifndef LESSON_5_H
#define LESSON_5_H

#include <QDialog>
#include <5_Lesson/question_5_1.h>

namespace Ui {
class lesson_5;
}

class lesson_5 : public QDialog
{
    Q_OBJECT

public:
    explicit lesson_5(QWidget *parent = nullptr);
    ~lesson_5();

private slots:
    void on_Open_1_Question_clicked();
    void Change_Window();

private:
    Ui::lesson_5 *ui;
    QDialog *New_Window;
};

#endif // LESSON_5_H
