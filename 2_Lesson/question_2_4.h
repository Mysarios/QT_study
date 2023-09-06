#ifndef QUESTION_2_4_H
#define QUESTION_2_4_H

#include <QDialog>

namespace Ui {
class Question_2_4;
}

class Question_2_4 : public QDialog
{
    Q_OBJECT

public:
    explicit Question_2_4(QWidget *parent = nullptr);
    ~Question_2_4();


private slots:
    void Add_Symbol(QString);
    void Get_Result(int);



private:
    Ui::Question_2_4 *ui;
};

#endif // QUESTION_2_4_H
