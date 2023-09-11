#ifndef QUESTION_5_1_H
#define QUESTION_5_1_H

#include <QDialog>
#include <QtQuickWidgets>
#include <5_Lesson/cardcreator.h>

namespace Ui {
class question_5_1;
}

class question_5_1 : public QDialog
{
    Q_OBJECT

public:
    explicit question_5_1(QWidget *parent = nullptr);
    ~question_5_1();
    QQuickWidget* CreateQMLFromCard(CardCreator *Card);

private:
    Ui::question_5_1 *ui;
    //QQuickWidget * rect;
};

#endif // QUESTION_5_1_H
