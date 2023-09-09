#ifndef QUESTION_4_3_H
#define QUESTION_4_3_H

#include <QDialog>

namespace Ui {
class Question_4_3;
}

class Question_4_3 : public QDialog
{
    Q_OBJECT

public:
    explicit Question_4_3(QWidget *parent = nullptr);
    ~Question_4_3();

private:
    Ui::Question_4_3 *ui;
};

#endif // QUESTION_4_3_H
