/********************************************************************************
** Form generated from reading UI file 'tetris.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TETRIS_H
#define UI_TETRIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include "gamefield.h"

QT_BEGIN_NAMESPACE

class Ui_Tetris
{
public:
    GameField *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Tetris)
    {
        if (Tetris->objectName().isEmpty())
            Tetris->setObjectName(QString::fromUtf8("Tetris"));
        Tetris->resize(164, 174);
        centralwidget = new GameField(Tetris);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setProperty("rowsNumber", QVariant(20u));
        centralwidget->setProperty("columnsNumber", QVariant(10u));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 81, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 20, 81, 21));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 50, 61, 21));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(90, 50, 61, 21));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 80, 131, 51));
        Tetris->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Tetris);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 164, 21));
        Tetris->setMenuBar(menubar);
        statusbar = new QStatusBar(Tetris);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Tetris->setStatusBar(statusbar);

        retranslateUi(Tetris);

        QMetaObject::connectSlotsByName(Tetris);
    } // setupUi

    void retranslateUi(QMainWindow *Tetris)
    {
        Tetris->setWindowTitle(QApplication::translate("Tetris", "Tetris", nullptr));
        label->setText(QApplication::translate("Tetris", "Set columns", nullptr));
        label_2->setText(QApplication::translate("Tetris", "Set rows", nullptr));
        lineEdit->setText(QApplication::translate("Tetris", "20", nullptr));
        lineEdit_2->setText(QApplication::translate("Tetris", "10", nullptr));
        pushButton->setText(QApplication::translate("Tetris", "Start Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tetris: public Ui_Tetris {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TETRIS_H
