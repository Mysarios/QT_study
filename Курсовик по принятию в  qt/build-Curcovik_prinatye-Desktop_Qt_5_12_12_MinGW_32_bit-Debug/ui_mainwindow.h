/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *Get_result;
    QTableView *Result;
    QListWidget *Kriterii;
    QListWidget *Ogran;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QLabel *Yravn;
    QLabel *Vashn;
    QLabel *Min_max;
    QLabel *Ystyp;
    QLineEdit *Yrav_l;
    QLineEdit *MM_l;
    QLineEdit *V_l;
    QLineEdit *Mis_l;
    QPushButton *Add;
    QPushButton *Clear;
    QLabel *Yravn_2;
    QLabel *Yravn_3;
    QLabel *Yravn_4;
    QPushButton *Change_Krit;
    QPushButton *Change_Ogran;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(935, 505);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Get_result = new QPushButton(centralwidget);
        Get_result->setObjectName(QString::fromUtf8("Get_result"));
        Get_result->setGeometry(QRect(720, 390, 191, 61));
        Result = new QTableView(centralwidget);
        Result->setObjectName(QString::fromUtf8("Result"));
        Result->setGeometry(QRect(725, 31, 181, 351));
        Kriterii = new QListWidget(centralwidget);
        Kriterii->setObjectName(QString::fromUtf8("Kriterii"));
        Kriterii->setGeometry(QRect(20, 30, 256, 191));
        Ogran = new QListWidget(centralwidget);
        Ogran->setObjectName(QString::fromUtf8("Ogran"));
        Ogran->setGeometry(QRect(430, 30, 256, 191));
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(30, 290, 131, 41));
        checkBox_2 = new QCheckBox(centralwidget);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(170, 290, 141, 41));
        Yravn = new QLabel(centralwidget);
        Yravn->setObjectName(QString::fromUtf8("Yravn"));
        Yravn->setGeometry(QRect(30, 330, 131, 31));
        Vashn = new QLabel(centralwidget);
        Vashn->setObjectName(QString::fromUtf8("Vashn"));
        Vashn->setGeometry(QRect(440, 330, 111, 31));
        Min_max = new QLabel(centralwidget);
        Min_max->setObjectName(QString::fromUtf8("Min_max"));
        Min_max->setGeometry(QRect(360, 330, 51, 31));
        Ystyp = new QLabel(centralwidget);
        Ystyp->setObjectName(QString::fromUtf8("Ystyp"));
        Ystyp->setGeometry(QRect(560, 330, 151, 31));
        Yrav_l = new QLineEdit(centralwidget);
        Yrav_l->setObjectName(QString::fromUtf8("Yrav_l"));
        Yrav_l->setGeometry(QRect(30, 360, 321, 31));
        MM_l = new QLineEdit(centralwidget);
        MM_l->setObjectName(QString::fromUtf8("MM_l"));
        MM_l->setGeometry(QRect(360, 360, 71, 31));
        V_l = new QLineEdit(centralwidget);
        V_l->setObjectName(QString::fromUtf8("V_l"));
        V_l->setGeometry(QRect(440, 360, 61, 31));
        Mis_l = new QLineEdit(centralwidget);
        Mis_l->setObjectName(QString::fromUtf8("Mis_l"));
        Mis_l->setGeometry(QRect(560, 360, 131, 31));
        Add = new QPushButton(centralwidget);
        Add->setObjectName(QString::fromUtf8("Add"));
        Add->setGeometry(QRect(570, 410, 121, 41));
        Clear = new QPushButton(centralwidget);
        Clear->setObjectName(QString::fromUtf8("Clear"));
        Clear->setGeometry(QRect(30, 410, 121, 41));
        Yravn_2 = new QLabel(centralwidget);
        Yravn_2->setObjectName(QString::fromUtf8("Yravn_2"));
        Yravn_2->setGeometry(QRect(20, 0, 131, 31));
        Yravn_3 = new QLabel(centralwidget);
        Yravn_3->setObjectName(QString::fromUtf8("Yravn_3"));
        Yravn_3->setGeometry(QRect(430, 0, 131, 31));
        Yravn_4 = new QLabel(centralwidget);
        Yravn_4->setObjectName(QString::fromUtf8("Yravn_4"));
        Yravn_4->setGeometry(QRect(730, 0, 131, 31));
        Change_Krit = new QPushButton(centralwidget);
        Change_Krit->setObjectName(QString::fromUtf8("Change_Krit"));
        Change_Krit->setGeometry(QRect(20, 230, 261, 51));
        Change_Ogran = new QPushButton(centralwidget);
        Change_Ogran->setObjectName(QString::fromUtf8("Change_Ogran"));
        Change_Ogran->setGeometry(QRect(430, 240, 261, 51));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 935, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        Get_result->setText(QApplication::translate("MainWindow", "\320\240\320\260\321\201\321\207\320\265\321\202", nullptr));
        checkBox->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\272\321\200\320\270\321\202\320\265\321\200\320\270\320\271", nullptr));
        checkBox_2->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\276\320\263\321\200\320\260\320\275\320\270\321\207\320\265\320\275\320\270\320\265", nullptr));
        Yravn->setText(QApplication::translate("MainWindow", "\320\243\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265 \320\272\321\200\320\270\321\202\320\265\321\200\320\270\321\217", nullptr));
        Vashn->setText(QApplication::translate("MainWindow", "\320\222\320\260\320\266\320\275\320\276\321\201\321\202\321\214 \320\272\321\200\320\270\321\202\320\265\321\200\320\270\321\217", nullptr));
        Min_max->setText(QApplication::translate("MainWindow", "Min/Max", nullptr));
        Ystyp->setText(QApplication::translate("MainWindow", "\320\243\321\201\321\202\321\203\320\277\320\272\320\260 \320\262 \320\277\321\200\320\276\321\206\320\265\320\275\321\202\320\260\321\205 0.\320\245\320\245\320\245....", nullptr));
        Add->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        Clear->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        Yravn_2->setText(QApplication::translate("MainWindow", "\320\232\321\200\320\270\321\202\320\265\321\200\320\270\320\270", nullptr));
        Yravn_3->setText(QApplication::translate("MainWindow", "\320\236\320\263\321\200\320\260\320\275\320\270\321\207\320\265\320\275\320\270\321\217", nullptr));
        Yravn_4->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        Change_Krit->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        Change_Ogran->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
