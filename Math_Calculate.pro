#-------------------------------------------------
#
# Project created by QtCreator 2018-03-26T18:29:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Math_Calculate
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    help_integral.cpp \
    integral.cpp \
    matrix.cpp \
    matrix_det.cpp \
    matrix_det_2x2.cpp \
    matrix_det_3x3.cpp \
    matrix_det_4x4.cpp \
    matrix_det_5x5.cpp \
    matrix_inverse.cpp \
    help.cpp \
    matrix_inverse_2x2.cpp \
    matrix_inverse_3x3.cpp \
    matrix_inverse_4x4.cpp \
    matrix_inverse_5x5.cpp \
    matrix_multiplication.cpp

HEADERS += \
        mainwindow.h \
    help_integral.h \
    integral.h \
    matrix.h \
    matrix_det.h \
    matrix_det_2x2.h \
    matrix_det_3x3.h \
    matrix_det_4x4.h \
    matrix_det_5x5.h \
    matrix_inverse.h \
    help.h \
    matrix_inverse_2x2.h \
    matrix_inverse_3x3.h \
    matrix_inverse_4x4.h \
    matrix_inverse_5x5.h \
    matrix_multiplication.h

FORMS += \
    matrix.ui \
    matrix_det.ui \
    matrix_det_2x2.ui \
    matrix_det_3x3.ui \
    matrix_det_4x4.ui \
    matrix_det_5x5.ui \
    matrix_inverse.ui \
    help_integral.ui \
    integral.ui \
    mainwindow.ui \
    help.ui \
    matrix_inverse_2x2.ui \
    matrix_inverse_3x3.ui \
    matrix_inverse_4x4.ui \
    matrix_inverse_5x5.ui \
    matrix_multiplication.ui

RESOURCES += \
    icons.qrc


