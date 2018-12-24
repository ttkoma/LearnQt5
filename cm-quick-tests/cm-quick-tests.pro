QT += testlib
QT -= gui

CONFIG += qt console testcase qmltestcase
CONFIG += c++14
CONFIG -= app_bundle debug_and_release

TEMPLATE = app

DISTFILES += \
    source/tst_client-tests.qml \
    target_wrapper.sh

INCLUDEPATH += source

HEADERS += \
    source/tst_client-tests.h

SOURCES += \
    source/main.cpp

include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)

DESTDIR = $$PWD/../binaries/$$DESTINATION_PATH
OBJECTS_DIR = $$PWD/build/$$DESTINATION_PATH/.obj
MOC_DIR = $$PWD/build/$$DESTINATION_PATH/.moc
RCC_DIR = $$PWD/build/$$DESTINATION_PATH/.qrc
UI_DIR = $$PWD/build/$$DESTINATION_PATH/.ui

message($${TARGET} out dir $${DESTDIR})

INCLUDEPATH += $${MOC_DIR}

unix:!macx: LIBS += -L$$PWD/../binaries/$$DESTINATION_PATH -lcm-lib
win32: LIBS += -L$$PWD/../binaries/$$DESTINATION_PATH -lcm-lib


INCLUDEPATH += $$PWD/../cm-lib/source
DEPENDPATH += $$PWD/../cm-lib/source

# Additional import path used to resolve QML modules in Qt Creator's code model
#QML_IMPORT_PATH = $$PWD

# Additional import path used to resolve QML modules
#IMPORTPATH += $$PWD/../imports/my_module1


