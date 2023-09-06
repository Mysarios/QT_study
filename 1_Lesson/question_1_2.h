#ifndef QUESTION_1_2_H
#define QUESTION_1_2_H

#include <QDialog>

namespace Ui {
class Question_1_2;
}

class Question_1_2 : public QDialog
{
    Q_OBJECT

public:
    explicit Question_1_2(QWidget *parent = nullptr);
    ~Question_1_2();

private slots:

    void on_First_clicked();

private:
    Ui::Question_1_2 *ui;
};

#endif // QUESTION_1_2_H
