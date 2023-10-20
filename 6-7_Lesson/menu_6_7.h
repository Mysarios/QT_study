#ifndef MENU_6_7_H
#define MENU_6_7_H

#include <QDialog>
#include "json_data.h"
#include <6-7_Lesson/settings.h>
#include <6-7_Lesson/main_game.h>
#include <6-7_Lesson/table.h>
#include <6-7_Lesson/load_game.h>

namespace Ui {
class Menu_6_7;
}

class Menu_6_7 : public QDialog
{
    Q_OBJECT

public:
    explicit Menu_6_7(QWidget *parent = nullptr);
    ~Menu_6_7();


private slots:
    void on_Exit_1_clicked();
    void on_Exit_2_clicked();
    void on_Show_table_clicked();
    void on_Load_game_clicked();
    void on_New_game_clicked();
    void load_data_to_table(QVector<QString> &Names,QVector<int> &Scores);
    void on_Settings_clicked();

private:
    Ui::Menu_6_7 *ui;
    Settings *Settings_Window;
    Load_game *Load_game_Window;
    Table *Table_Window;
    Json_Data Data;
    Json_Data::Settings_data* Setting;

};

#endif // MENU_6_7_H
