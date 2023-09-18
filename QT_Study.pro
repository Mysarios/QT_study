QT       += core gui
QT       += qml
QT       += quick
QT       += quickcontrols2
QT       += quickwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    1_Lesson/question_1_1.cpp \
    1_Lesson/question_1_2.cpp \
    1_Lesson/question_1_3.cpp \
    1_Lesson/question_4.cpp \
    2_Lesson/question_2_1.cpp \
    2_Lesson/question_2_2.cpp \
    2_Lesson/question_2_3.cpp \
    2_Lesson/question_2_4.cpp \
    3_Lesson/question_3_1.cpp \
    3_Lesson/question_3_2.cpp \
    3_Lesson/question_3_3.cpp \
    3_Lesson/question_3_4.cpp \
    3_Lesson/question_3_5.cpp \
    4_Lesson/question_4_1.cpp \
    4_Lesson/question_4_2.cpp \
    4_Lesson/question_4_3.cpp \
    4_Lesson/question_4_4.cpp \
    5_Lesson/cardcreator.cpp \
    5_Lesson/question_5_1.cpp \
    6-7_Lesson/json_data.cpp \
    6-7_Lesson/main_game.cpp \
    6-7_Lesson/menu_6_7.cpp \
    6-7_Lesson/settings.cpp \
    6-7_Lesson/table.cpp \
    lesson_1.cpp \
    lesson_2.cpp \
    lesson_3.cpp \
    lesson_4.cpp \
    lesson_5.cpp \
    lesson_6.cpp \
    main.cpp \
    main_window.cpp

HEADERS += \
    1_Lesson/question_1_1.h \
    1_Lesson/question_1_2.h \
    1_Lesson/question_1_3.h \
    1_Lesson/question_4.h \
    2_Lesson/question_2_1.h \
    2_Lesson/question_2_2.h \
    2_Lesson/question_2_3.h \
    2_Lesson/question_2_4.h \
    3_Lesson/question_3_1.h \
    3_Lesson/question_3_2.h \
    3_Lesson/question_3_3.h \
    3_Lesson/question_3_4.h \
    3_Lesson/question_3_5.h \
    4_Lesson/question_4_1.h \
    4_Lesson/question_4_2.h \
    4_Lesson/question_4_3.h \
    4_Lesson/question_4_4.h \
    5_Lesson/cardcreator.h \
    5_Lesson/question_5_1.h \
    6-7_Lesson/json_data.h \
    6-7_Lesson/main_game.h \
    6-7_Lesson/menu_6_7.h \
    6-7_Lesson/settings.h \
    6-7_Lesson/table.h \
    lesson_1.h \
    lesson_2.h \
    lesson_3.h \
    lesson_4.h \
    lesson_5.h \
    lesson_6.h \
    main_window.h

FORMS += \
    1_Lesson/question_1_1.ui \
    1_Lesson/question_1_2.ui \
    1_Lesson/question_1_3.ui \
    1_Lesson/question_4.ui \
    2_Lesson/question_2_1.ui \
    2_Lesson/question_2_2.ui \
    2_Lesson/question_2_3.ui \
    2_Lesson/question_2_4.ui \
    3_Lesson/question_3_1.ui \
    3_Lesson/question_3_2.ui \
    3_Lesson/question_3_3.ui \
    3_Lesson/question_3_4.ui \
    3_Lesson/question_3_5.ui \
    4_Lesson/question_4_1.ui \
    4_Lesson/question_4_2.ui \
    4_Lesson/question_4_3.ui \
    4_Lesson/question_4_4.ui \
    5_Lesson/question_5_1.ui \
    6-7_Lesson/main_game.ui \
    6-7_Lesson/menu_6_7.ui \
    6-7_Lesson/settings.ui \
    6-7_Lesson/table.ui \
    lesson_1.ui \
    lesson_2.ui \
    lesson_3.ui \
    lesson_4.ui \
    lesson_5.ui \
    lesson_6.ui \
    main_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    3_Lesson/Pictures.qrc \
    Res.qrc \
    Snake.qrc

DISTFILES += \
    5_Lesson/lesson_5_1_QtQuick.qml \
    6-7_Lesson/Data_hold/Json_data.json
