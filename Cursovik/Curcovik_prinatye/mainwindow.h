#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <criteria.h>
#include <limitation.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Add_clicked();
    void on_Clear_clicked();
    bool check_data_Crit(QString f,QString mm ,QString a,QString v);
    bool check_data_Ogran(QString f,QString Value);

    void on_radioButton_2_clicked();

    void on_radioButton_clicked();

    void on_Get_result_clicked();

private:
    Ui::MainWindow *ui;
    QVector<Criteria*> criterias;
    QVector<Limitation*> limits;

};
#endif // MAINWINDOW_H
