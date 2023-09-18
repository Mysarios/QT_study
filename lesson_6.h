#ifndef LESSON_6_H
#define LESSON_6_H

#include <QDialog>
#include <6-7_Lesson/menu_6_7.h>

namespace Ui {
class Lesson_6;
}

class Lesson_6 : public QDialog
{
    Q_OBJECT

public:
    explicit Lesson_6(QWidget *parent = nullptr);
    ~Lesson_6();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Lesson_6 *ui;
    QDialog *New_Window;
};

#endif // LESSON_6_H
