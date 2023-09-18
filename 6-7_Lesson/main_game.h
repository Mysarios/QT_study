#ifndef MAIN_GAME_H
#define MAIN_GAME_H

#include <QDialog>
#include <QTimer>
#include "json_data.h"
#include <QVector>

namespace Ui {
class Main_game;
}

class Main_game : public QDialog
{
    Q_OBJECT

public:
    explicit Main_game(QWidget *parent = nullptr);
    ~Main_game();

private slots:
    void Update_position();
    void Next_step_head();
    void Create_fruit();
    void GameLoop();

signals:
    void New_iter();

private:
    Ui::Main_game *ui;
    QTimer *qtimer;
    QVector<Json_Data::Body_part> body;
    int Keyboard_key;
    Json_Data Data;
    Json_Data::Settings_data Setting;
};

#endif // MAIN_GAME_H
