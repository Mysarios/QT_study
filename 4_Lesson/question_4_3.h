#ifndef QUESTION_4_3_H
#define QUESTION_4_3_H

#include <QDialog>
#include <QMap>
#include <QVector>

namespace Ui {
class Question_4_3;
}

class Question_4_3 : public QDialog
{
    Q_OBJECT

public:
    explicit Question_4_3(QWidget *parent = nullptr);
    ~Question_4_3();
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

private:
    Ui::Question_4_3 *ui;
    QMap<QString,Data_save> Array;
    QVector<QString> Vector_site_names;
    int Vector_El_Index;
};

#endif // QUESTION_4_3_H
