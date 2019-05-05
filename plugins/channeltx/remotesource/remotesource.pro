#--------------------------------------------------------
#
# Pro file for Android and Windows builds with Qt Creator
#
#--------------------------------------------------------

TEMPLATE = lib
CONFIG += plugin

QT += core gui widgets multimedia network opengl

TARGET = remotesource

CONFIG(MINGW32):LIBCM256CCSRC = "C:\softs\cm256cc"
CONFIG(MSVC):LIBCM256CCSRC = "C:\softs\cm256cc"
CONFIG(macx):LIBCM256CCSRC = "../../../../deps/cm256cc"

INCLUDEPATH += $$PWD
INCLUDEPATH += ../../../exports
INCLUDEPATH += ../../../sdrbase
INCLUDEPATH += ../../../sdrgui
INCLUDEPATH += ../../../swagger/sdrangel/code/qt5/client
macx:INCLUDEPATH += /opt/local/include
INCLUDEPATH += $$LIBCM256CCSRC

DEFINES += USE_SSE2=1
QMAKE_CXXFLAGS += -msse2
DEFINES += USE_SSSE3=1
QMAKE_CXXFLAGS += -mssse3
DEFINES += USE_SSE4_1=1
QMAKE_CXXFLAGS += -msse4.1
QMAKE_CXXFLAGS += -std=c++11

CONFIG(Release):build_subdir = release
CONFIG(Debug):build_subdir = debug

CONFIG(MINGW32):INCLUDEPATH += "C:\softs\boost_1_66_0"
CONFIG(MSVC):INCLUDEPATH += "C:\softs\boost_1_66_0"
CONFIG(macx):INCLUDEPATH += "../../../../deps/boost_1_69_0"

SOURCES += remotesource.cpp\
    remotesourcegui.cpp\
    remotesourcesettings.cpp\
    remotesourceplugin.cpp\
    remotesourcethread.cpp

HEADERS += remotesource.h\
    remotesourcegui.h\
    remotesourcesettings.h\
    remotesourceplugin.h\
    remotesourcethread.h

FORMS += remotesourcegui.ui

LIBS += -L../../../sdrbase/$${build_subdir} -lsdrbase
LIBS += -L../../../sdrgui/$${build_subdir} -lsdrgui
LIBS += -L../../../swagger/$${build_subdir} -lswagger
LIBS += -L../../../cm256cc/$${build_subdir} -lcm256cc

macx {
    LIBS -= -L../../../nanomsg/$${build_subdir} -lnanomsg
    LIBS += -L/usr/local/lib -lnanomsg
    QMAKE_LFLAGS_SONAME = -Wl,-install_name,@rpath/
}

RESOURCES = ../../../sdrgui/resources/res.qrc

CONFIG(MINGW32):DEFINES += USE_INTERNAL_TIMER=1
