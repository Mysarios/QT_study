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
    bool check_data_eravn(QString f,QString mm ,QString a,QString v);

private:
    Ui::MainWindow *ui;
    QVector<Criteria*> criterias;

};
#endif // MAINWINDOW_H
