#ifndef QUESTION_1_1_H
#define QUESTION_1_1_H

#include <QDialog>

namespace Ui {
class Question_1_1;
}

class Question_1_1 : public QDialog
{
    Q_OBJECT

public:
    explicit Question_1_1(QWidget *parent = nullptr);
    ~Question_1_1();

private slots:
    void on_Right_To_Left_clicked();
    void on_Left_To_Rgiht_clicked();

private:
    Ui::Question_1_1 *ui;
};

#endif // QUESTION_1_1_H
