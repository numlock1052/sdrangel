#--------------------------------------------------------
#
# Pro file for Android and Windows builds with Qt Creator
#
#--------------------------------------------------------

TEMPLATE = lib
CONFIG += plugin

QT += core gui widgets multimedia opengl

TARGET = inputairspy

CONFIG(MINGW32):LIBAIRSPYSRC = "C:\softs\libairspy"
CONFIG(MSVC):LIBAIRSPYSRC = "C:\softs\libairspy"
CONFIG(macx):INCLUDEPATH += /usr/local/Cellar/airspy/1.0.9/include

INCLUDEPATH += $$PWD
INCLUDEPATH += ../../../exports
INCLUDEPATH += ../../../sdrbase
INCLUDEPATH += ../../../sdrgui
INCLUDEPATH += ../../../swagger/sdrangel/code/qt5/client
INCLUDEPATH += $$LIBAIRSPYSRC

DEFINES += LIBAIRSPY_DYN_RATES
DEFINES += USE_SSE2=1
QMAKE_CXXFLAGS += -msse2
DEFINES += USE_SSE4_1=1
QMAKE_CXXFLAGS += -msse4.1
QMAKE_CXXFLAGS += -std=c++11

CONFIG(Release):build_subdir = release
CONFIG(Debug):build_subdir = debug

SOURCES += airspygui.cpp\
  airspyinput.cpp\
  airspyplugin.cpp\
  airspysettings.cpp\
  airspythread.cpp

HEADERS += airspygui.h\
  airspyinput.h\
  airspyplugin.h\
  airspysettings.h\
  airspythread.h

FORMS += airspygui.ui

LIBS += -L../../../sdrbase/$${build_subdir} -lsdrbase
LIBS += -L../../../sdrgui/$${build_subdir} -lsdrgui
LIBS += -L../../../swagger/$${build_subdir} -lswagger
LIBS += -L../../../libairspy/$${build_subdir} -llibairspy
macx {
    LIBS -= -L../../../libairspy/$${build_subdir} -llibairspy
    LIBS += -L/opt/local/lib -lairspy
    QMAKE_LFLAGS_SONAME = -Wl,-install_name,@rpath/
}
LIBS += -L/usr/local/Cellar/airspy/1.0.9/lib -lairspy

RESOURCES = ../../../sdrgui/resources/res.qrc
