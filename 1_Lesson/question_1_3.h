#ifndef QUESTION_1_3_H
#define QUESTION_1_3_H

#include <QDialog>

namespace Ui {
class Question_1_3;
}

class Question_1_3 : public QDialog
{
    Q_OBJECT

public:
    explicit Question_1_3(QWidget *parent = nullptr);
    ~Question_1_3();

private slots:
    void on_Change_Label_clicked();

private:
    Ui::Question_1_3 *ui;
    QPalette NewQpalette;
    QPalette StandartQpalette;
    int IndexLabel;
};

#endif // QUESTION_1_3_H
