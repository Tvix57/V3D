QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

QMAKE_CXXFLAGS += -lstdc++

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TARGET = C8_3DViewer_v1_0-0

win32 {
 LIBS += -lopengl32
}
macx {
  QT +=  opengl openglwidgets
}
INCLUDEPATH += $$PWD/include

release: DESTDIR = build/release
debug:   DESTDIR = build/debug

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.qrc
UI_DIR = $$DESTDIR/.ui

SOURCES += \
    source/dialog_size.cpp \
    source/glwidget.cpp \
    source/main.cpp \
    source/mainwindow.cpp \
    source/parser.c

HEADERS += \
    include/dialog_size.h \
    include/glwidget.h \
    include/mainwindow.h \
    include/parser.h

FORMS += \
    frontend/dialog_size.ui \
    frontend/mainwindow.ui \

TRANSLATIONS += \
    translate/3DViewer_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc


include(gif_maker/gifimage/qtgifimage.pri)

DISTFILES += \
    source/a.out
