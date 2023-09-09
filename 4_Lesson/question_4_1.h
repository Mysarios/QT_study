#ifndef QUESTION_4_1_H
#define QUESTION_4_1_H

#include <QDialog>
#include <QVector>

namespace Ui {
class Question_4_1;
}

class Question_4_1 : public QDialog
{
    Q_OBJECT

public:
    explicit Question_4_1(QWidget *parent = nullptr);
    ~Question_4_1();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_Clear_clicked();

private:
    Ui::Question_4_1 *ui;
    QVector<int> SortedVector;
};

#endif // QUESTION_4_1_H
