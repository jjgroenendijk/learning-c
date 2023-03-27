TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Unity/src/unity.c \
        functions.c \
        main.c

HEADERS += \
   Unity/src/unity.h \
   Unity/src/unity_internals.h \
   functions.h
