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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
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
    QLabel *C_function_label;
    QLabel *C_Validate_label;
    QLabel *C_Min_max_label;
    QLabel *C_Assigment_label;
    QLineEdit *C_function_edit;
    QLineEdit *C_Min_Max_edit;
    QLineEdit *C_Validate_edit;
    QLineEdit *C_Assigment_edit;
    QPushButton *Add;
    QPushButton *Clear;
    QLabel *Yravn_2;
    QLabel *Yravn_3;
    QLabel *Yravn_4;
    QPushButton *Change_Krit;
    QPushButton *Change_Ogran;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLineEdit *O_Equal_val;
    QLineEdit *O_function_edit;
    QLabel *O_function_label;
    QLabel *O_Equal_num_label;
    QComboBox *O_Eque_Sym_Combobox;
    QLabel *O_Equal_t_label;
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
        new QListWidgetItem(Kriterii);
        new QListWidgetItem(Kriterii);
        Kriterii->setObjectName(QString::fromUtf8("Kriterii"));
        Kriterii->setGeometry(QRect(20, 30, 371, 191));
        Ogran = new QListWidget(centralwidget);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(Ogran);
        __qlistwidgetitem->setForeground(brush);
        new QListWidgetItem(Ogran);
        Ogran->setObjectName(QString::fromUtf8("Ogran"));
        Ogran->setGeometry(QRect(400, 30, 311, 191));
        C_function_label = new QLabel(centralwidget);
        C_function_label->setObjectName(QString::fromUtf8("C_function_label"));
        C_function_label->setGeometry(QRect(30, 330, 131, 31));
        C_Validate_label = new QLabel(centralwidget);
        C_Validate_label->setObjectName(QString::fromUtf8("C_Validate_label"));
        C_Validate_label->setGeometry(QRect(440, 330, 111, 31));
        C_Min_max_label = new QLabel(centralwidget);
        C_Min_max_label->setObjectName(QString::fromUtf8("C_Min_max_label"));
        C_Min_max_label->setGeometry(QRect(360, 330, 51, 31));
        C_Assigment_label = new QLabel(centralwidget);
        C_Assigment_label->setObjectName(QString::fromUtf8("C_Assigment_label"));
        C_Assigment_label->setGeometry(QRect(560, 330, 151, 31));
        C_function_edit = new QLineEdit(centralwidget);
        C_function_edit->setObjectName(QString::fromUtf8("C_function_edit"));
        C_function_edit->setGeometry(QRect(30, 360, 321, 31));
        C_Min_Max_edit = new QLineEdit(centralwidget);
        C_Min_Max_edit->setObjectName(QString::fromUtf8("C_Min_Max_edit"));
        C_Min_Max_edit->setGeometry(QRect(360, 360, 71, 31));
        C_Validate_edit = new QLineEdit(centralwidget);
        C_Validate_edit->setObjectName(QString::fromUtf8("C_Validate_edit"));
        C_Validate_edit->setGeometry(QRect(440, 360, 61, 31));
        C_Assigment_edit = new QLineEdit(centralwidget);
        C_Assigment_edit->setObjectName(QString::fromUtf8("C_Assigment_edit"));
        C_Assigment_edit->setGeometry(QRect(560, 360, 131, 31));
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
        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(180, 310, 151, 17));
        radioButton->setChecked(false);
        radioButton_2 = new QRadioButton(centralwidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(40, 310, 131, 17));
        radioButton_2->setChecked(true);
        O_Equal_val = new QLineEdit(centralwidget);
        O_Equal_val->setObjectName(QString::fromUtf8("O_Equal_val"));
        O_Equal_val->setGeometry(QRect(440, 360, 61, 31));
        O_function_edit = new QLineEdit(centralwidget);
        O_function_edit->setObjectName(QString::fromUtf8("O_function_edit"));
        O_function_edit->setGeometry(QRect(30, 360, 321, 31));
        O_function_label = new QLabel(centralwidget);
        O_function_label->setObjectName(QString::fromUtf8("O_function_label"));
        O_function_label->setGeometry(QRect(30, 330, 131, 31));
        O_Equal_num_label = new QLabel(centralwidget);
        O_Equal_num_label->setObjectName(QString::fromUtf8("O_Equal_num_label"));
        O_Equal_num_label->setGeometry(QRect(440, 330, 111, 31));
        O_Eque_Sym_Combobox = new QComboBox(centralwidget);
        O_Eque_Sym_Combobox->addItem(QString());
        O_Eque_Sym_Combobox->addItem(QString());
        O_Eque_Sym_Combobox->addItem(QString());
        O_Eque_Sym_Combobox->setObjectName(QString::fromUtf8("O_Eque_Sym_Combobox"));
        O_Eque_Sym_Combobox->setGeometry(QRect(360, 360, 69, 22));
        O_Equal_t_label = new QLabel(centralwidget);
        O_Equal_t_label->setObjectName(QString::fromUtf8("O_Equal_t_label"));
        O_Equal_t_label->setGeometry(QRect(360, 330, 51, 31));
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

        const bool __sortingEnabled = Kriterii->isSortingEnabled();
        Kriterii->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = Kriterii->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "Rang | assigment | function Min/Max", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = Kriterii->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MainWindow", "________________________________________________________________________________________________________", nullptr));
        Kriterii->setSortingEnabled(__sortingEnabled);


        const bool __sortingEnabled1 = Ogran->isSortingEnabled();
        Ogran->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem2 = Ogran->item(0);
        ___qlistwidgetitem2->setText(QApplication::translate("MainWindow", "Function        |      Equal type            |                 num", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = Ogran->item(1);
        ___qlistwidgetitem3->setText(QApplication::translate("MainWindow", "_______________________________________________________________________________________________________", nullptr));
        Ogran->setSortingEnabled(__sortingEnabled1);

        C_function_label->setText(QApplication::translate("MainWindow", "\320\243\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265 \320\272\321\200\320\270\321\202\320\265\321\200\320\270\321\217", nullptr));
        C_Validate_label->setText(QApplication::translate("MainWindow", "\320\222\320\260\320\266\320\275\320\276\321\201\321\202\321\214 \320\272\321\200\320\270\321\202\320\265\321\200\320\270\321\217", nullptr));
        C_Min_max_label->setText(QApplication::translate("MainWindow", "Min/Max", nullptr));
        C_Assigment_label->setText(QApplication::translate("MainWindow", "\320\243\321\201\321\202\321\203\320\277\320\272\320\260 \320\262 \320\277\321\200\320\276\321\206\320\265\320\275\321\202\320\260\321\205 0.\320\245\320\245\320\245....", nullptr));
        C_function_edit->setText(QApplication::translate("MainWindow", "2x1", nullptr));
        C_Min_Max_edit->setText(QApplication::translate("MainWindow", "Max", nullptr));
        C_Validate_edit->setText(QApplication::translate("MainWindow", "1", nullptr));
        C_Assigment_edit->setText(QApplication::translate("MainWindow", "0.25", nullptr));
        Add->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        Clear->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        Yravn_2->setText(QApplication::translate("MainWindow", "\320\232\321\200\320\270\321\202\320\265\321\200\320\270\320\270", nullptr));
        Yravn_3->setText(QApplication::translate("MainWindow", "\320\236\320\263\321\200\320\260\320\275\320\270\321\207\320\265\320\275\320\270\321\217", nullptr));
        Yravn_4->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        Change_Krit->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        Change_Ogran->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        radioButton->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\276\320\263\321\200\320\260\320\275\320\270\321\207\320\265\320\275\320\270\320\265", nullptr));
        radioButton_2->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\272\321\200\320\270\321\202\320\265\321\200\320\270\320\271", nullptr));
        O_Equal_val->setText(QApplication::translate("MainWindow", "1", nullptr));
        O_function_edit->setText(QApplication::translate("MainWindow", "2x1", nullptr));
        O_function_label->setText(QApplication::translate("MainWindow", "\320\243\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265 \320\276\320\263\321\200\320\260\320\275\320\270\321\207\320\265\320\275\320\270\320\265", nullptr));
        O_Equal_num_label->setText(QApplication::translate("MainWindow", "\320\240\320\260\320\262\320\265\320\275\321\201\321\202\320\262\320\276", nullptr));
        O_Eque_Sym_Combobox->setItemText(0, QApplication::translate("MainWindow", ">=", nullptr));
        O_Eque_Sym_Combobox->setItemText(1, QApplication::translate("MainWindow", "<=", nullptr));
        O_Eque_Sym_Combobox->setItemText(2, QApplication::translate("MainWindow", "=", nullptr));

        O_Equal_t_label->setText(QApplication::translate("MainWindow", "Equal type", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
