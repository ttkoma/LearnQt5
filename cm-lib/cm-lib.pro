#-------------------------------------------------
#
# Project created by QtCreator 2018-12-15T17:14:38
#
#-------------------------------------------------

QT       -= gui

TARGET = cm-lib
TEMPLATE = lib
CONFIG += sharedlib c++14

DEFINES += CMLIB_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += source

SOURCES += source/models/client.cpp \
    source/controllers/master-controller.cpp \
    source/framework/command.cpp \
    source/controllers/command-controller.cpp \
    source/data/data-decorator.cpp \
    source/data/string-decorator.cpp

HEADERS += source/cm-lib_global.h  \
        source/models/client.h \
    source/controllers/master-controller.h \
    source/controllers/navigation-controller.h \
    source/framework/command.h \
    source/controllers/command-controller.h \
    source/data/data-decorator.h \
    source/data/string-decorator.h

include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)

DESTDIR = $$PWD/../binaries/$$DESTINATION_PATH
OBJECTS_DIR = $$PWD/build/$$DESTINATION_PATH/.obj
MOC_DIR = $$PWD/build/$$DESTINATION_PATH/.moc
RCC_DIR = $$PWD/build/$$DESTINATION_PATH/.qrc
UI_DIR = $$PWD/build/$$DESTINATION_PATH/.ui

#message($${TARGET} out dir $${DESTDIR})

unix {
    target.path = /usr/lib
    INSTALLS += target
}
