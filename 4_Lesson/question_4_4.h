#ifndef QUESTION_4_4_H
#define QUESTION_4_4_H

#include <QDialog>
#include <QMap>
#include <QVector>

namespace Ui {
class Question_4_4;
}

class Question_4_4 : public QDialog
{
    Q_OBJECT

public:
    explicit Question_4_4(QWidget *parent = nullptr);
    ~Question_4_4();
    struct Data_save{
        QString Login;
        QString Password;
    };

private slots:
    void on_Create_clicked();

    void on_Create_data_clicked();

    void on_Next_clicked();

    void on_Back_clicked();

    void on_Edit_clicked();

    void on_Save_edit_clicked();

    void on_Random_pass_clicked();

private:
    Ui::Question_4_4 *ui;
    QMap<QString,Data_save> Array;
    QVector<QString> Vector_site_names;
    int Vector_El_Index;
};

#endif // QUESTION_4_4_H
