#ifndef QUESTION_4_2_H
#define QUESTION_4_2_H

#include <QDialog>
#include <QLinkedList>

namespace Ui {
class Question_4_2;
}

class Question_4_2 : public QDialog
{
    Q_OBJECT

public:
    explicit Question_4_2(QWidget *parent = nullptr);
    ~Question_4_2();
    struct Deal{
        QString Title;
        QString Text;
    };

private slots:
    void on_Create_clicked();

    void on_Save_clicked();

    void on_Cancel_clicked();

    void on_Last_clicked();

    void on_Next_clicked();

    void on_Delete_clicked();

private:
    Ui::Question_4_2 *ui;
    QLinkedList<Deal> Main_list;
    int Max_size =1;
    QLinkedList<Deal>::iterator Now_it;
    int Now_Deal;
};



#endif // QUESTION_4_2_H
