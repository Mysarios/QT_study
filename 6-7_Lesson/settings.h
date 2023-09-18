#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include "json_data.h"

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();
    //void Set_Data_Jason(Json_Data::Settings_data);
    Json_Data::Settings_data* Data;

private slots:
    void on_Cancel_clicked();
    QString Get_Dificult();
    int Get_Speed();
    void on_Accept_clicked();

private:
    Ui::Settings *ui;

};

#endif // SETTINGS_H
