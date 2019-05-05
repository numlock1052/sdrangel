#-------------------------------------------------
#
# Pro file for Windows MSVC builds with Qt Creator
#
#-------------------------------------------------

TEMPLATE = lib
CONFIG += plugin

QT += core gui multimedia opengl

TARGET = outputsoapysdr

CONFIG(MSVC):LIBSOAPYSDRSRC = "C:\Program Files\PothosSDR"
CONFIG(macx):LIBSOAPYSDRSRC = "../../../../deps/SoapySDR"

INCLUDEPATH += $$PWD
INCLUDEPATH += ../../../exports
INCLUDEPATH += ../../../sdrbase
INCLUDEPATH += ../../../sdrgui
INCLUDEPATH += ../../../devices
INCLUDEPATH += ../../../swagger/sdrangel/code/qt5/client
INCLUDEPATH +=

INCLUDEPATH += $$LIBSOAPYSDRSRC/include

CONFIG(Release):build_subdir = release
CONFIG(Debug):build_subdir = debug

SOURCES += soapysdroutput.cpp\
    soapysdroutputgui.cpp\
    soapysdroutputplugin.cpp\
    soapysdroutputsettings.cpp\
    soapysdroutputthread.cpp

HEADERS += soapysdroutput.h\
    soapysdroutputgui.h\
    soapysdroutputplugin.h\
    soapysdroutputsettings.h\
    soapysdroutputthread.h

FORMS += soapysdroutputgui.ui

LIBS += -L../../../sdrbase/$${build_subdir} -lsdrbase
LIBS += -L../../../sdrgui/$${build_subdir} -lsdrgui
LIBS += -L../../../swagger/$${build_subdir} -lswagger
LIBS += -L../../../devices/$${build_subdir} -ldevices

MSVC {
    LIBS += -L"C:\Program Files\PothosSDR\bin" -L"C:\Program Files\PothosSDR\lib" -lSoapySDR
}

macx {
    LIBS += -L/usr/local/lib -lSoapySDR
    QMAKE_LFLAGS_SONAME = -Wl,-install_name,@rpath/
}
