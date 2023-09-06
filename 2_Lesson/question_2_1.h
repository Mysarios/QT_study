#ifndef QUESTION_2_1_H
#define QUESTION_2_1_H

#include <QDialog>

namespace Ui {
class Question_2_1;
}

class Question_2_1 : public QDialog
{
    Q_OBJECT

public:
    explicit Question_2_1(QWidget *parent = nullptr);
    ~Question_2_1();

private slots:
    void on_pushButton_2_clicked();
    void Summa_Function();

private:
    Ui::Question_2_1 *ui;
    QPushButton *ResultButton;
};

#endif // QUESTION_2_1_H
