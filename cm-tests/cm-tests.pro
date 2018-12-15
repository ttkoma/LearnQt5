QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG += c++14
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += source/models

SOURCES += source/models/tst_client-tests.cpp

include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)

INCLUDEPATH += $$PWD/../cm-lib/source
DEPENDPATH += $$PWD/../cm-lib/source

DESTDIR = $$PWD/../binaries/$$DESTINATION_PATH
OBJECTS_DIR = $$PWD/build/$$DESTINATION_PATH/.obj
MOC_DIR = $$PWD/build/$$DESTINATION_PATH/.moc
RCC_DIR = $$PWD/build/$$DESTINATION_PATH/.qrc
UI_DIR = $$PWD/build/$$DESTINATION_PATH/.ui

#message($$TARGET out dir $${DESTDIR})
#INCLUDEPATH += $${MOC_DIR}



