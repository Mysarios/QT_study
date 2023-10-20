#ifndef LOAD_GAME_H
#define LOAD_GAME_H

#include <QDialog>
#include <QString>
#include "json_data.h"
#include <6-7_Lesson/settings.h>
#include <6-7_Lesson/main_game.h>


namespace Ui {
class Load_game;
}

class Load_game : public QDialog
{
    Q_OBJECT

public:
    explicit Load_game(QWidget *parent = nullptr);
    ~Load_game();
    void set_Names(QVector<QString>);
    void Load_all_saves();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Load_game *ui;
    QVector<QString> Names;
    Json_Data::Settings_data* Setting;
    QVector<Json_Data::Body_part> Body;
    QVector<Fruit> Fruits;
    int score = 0;
};

#endif // LOAD_GAME_H
