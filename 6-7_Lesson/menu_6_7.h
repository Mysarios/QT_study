#ifndef MENU_6_7_H
#define MENU_6_7_H

#include <QDialog>
#include "json_data.h"
#include <6-7_Lesson/settings.h>

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

    void on_Settings_clicked();

private:
    Ui::Menu_6_7 *ui;
    Json_Data Data;
    Json_Data::Settings_data Setting;
    Settings *Settings_Window;

};

#endif // MENU_6_7_H
