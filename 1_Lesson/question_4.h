#ifndef QUESTION_4_H
#define QUESTION_4_H

#include <QDialog>

namespace Ui {
class Question_4;
}

class Question_4 : public QDialog
{
    Q_OBJECT

public:
    explicit Question_4(QWidget *parent = nullptr);
    ~Question_4();

private slots:
    void on_Test_Button_clicked();

private:
    Ui::Question_4 *ui;
};

#endif // QUESTION_4_H
