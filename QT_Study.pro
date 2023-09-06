QT       += core gui

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
    lesson_1.cpp \
    lesson_2.cpp \
    lesson_3.cpp \
    lesson_4.cpp \
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
    lesson_1.h \
    lesson_2.h \
    lesson_3.h \
    lesson_4.h \
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
    lesson_1.ui \
    lesson_2.ui \
    lesson_3.ui \
    lesson_4.ui \
    main_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    3_Lesson/Pictures.qrc
