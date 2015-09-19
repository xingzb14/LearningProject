QT       += core gui network concurrent multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT       += sql

QT     +=    opengl
TARGET = BaiduTranslationDemo
TEMPLATE = app

CONFIG += c++11
SOURCES += \
    main.cpp \
    loginwindow.cpp \
    registerwindow.cpp \
    tranwindow.cpp \
    mainwindow.cpp \
    translatewindow.cpp \
    userwindow.cpp \
    newwordmanagewindow.cpp \
    dialog.cpp \
    learningwindow.cpp \
    morewindow.cpp \
    phrasewindow.cpp \
    user.cpp \
    singleword.cpp \
    singlephrase.cpp \
    singlenewword.cpp \
    newwordsuccess.cpp \
    wordsuccess.cpp \
    phrasesuccess.cpp \
    userdata.cpp \
    Net.cpp \
    Trans.cpp \
    about.cpp \
    newword.cpp \
    phrase.cpp \
    words.cpp

HEADERS += \
    loginwindow.h \
    registerwindow.h \
    tranwindow.h \
    mainwindow.h \
    translatewindow.h \
    userwindow.h \
    newwordmanagewindow.h \
    dialog.h \
    learningwindow.h \
    morewindow.h \
    phrasewindow.h \
    user.h \
    singleword.h \
    singlephrase.h \
    singlenewword.h \
    newwordsuccess.h \
    data.h \
    wordsuccess.h \
    phrasesuccess.h \
    userdata.h \
    Net.h \
    Trans.h \
    about.h \
    CONNECTION.h \
    newword.h \
    phrase.h \
    words.h

RESOURCES += \
    src.qrc
