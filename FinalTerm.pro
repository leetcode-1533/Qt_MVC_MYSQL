#-------------------------------------------------
#
# Project created by QtCreator 2013-11-25T22:05:28
#
#-------------------------------------------------

QT       += core gui
QT       +=sql

TARGET = FinalTerm
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mysql_establish.cpp \
    w_login.cpp \
    w_form.cpp \
    s_form.cpp \
    sql_professor.cpp

HEADERS  += mainwindow.h \
    mysql_establish.h \
    w_form.h \
    w_login.h \
    s_form.h \
    sql_professor.h

FORMS    += mainwindow.ui \
    w_login.ui \
    w_form.ui \
    s_form.ui
