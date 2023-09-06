#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <lesson_1.h>
#include <lesson_2.h>
#include <lesson_3.h>
#include <lesson_4.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Main_Window; }
QT_END_NAMESPACE

class Main_Window : public QMainWindow
{
    Q_OBJECT

public:
    Main_Window(QWidget *parent = nullptr);
    ~Main_Window();

private slots:
    void on_Open_Lesson_1_clicked();
    void Change_Window();

    void on_Open_Lesson_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Main_Window *ui;
    QDialog *New_Window;
};
#endif // MAIN_WINDOW_H
