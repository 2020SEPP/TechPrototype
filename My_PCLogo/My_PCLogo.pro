QT       += core gui
QT	 += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CodEditor.cpp \
    HttpRequest.cpp \
    homepage.cpp \
    main.cpp \
    mainwindow.cpp \
    region.cpp \
    signinwidget.cpp \
    signupwidget.cpp \
    userinfo.cpp \
    canvas.cpp \
    console.cpp \
    painter.cpp \
    lineedit_my.cpp \
    window.cpp

HEADERS += \
    CodEditor.h \
    HttpRequest.h \
    Network.h \
    homepage.h \
    mainwindow.h \
    region.h \
    signinwidget.h \
    signupwidget.h \
    user.h \
    userinfo.h \
    canvas.h \
    console.h \
    painter.h \
    lineedit_my.h \
    window.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

# Add Code Texter QScintilla

#INCLUDEPATH += ..\QScintilla-2.11.5\Qt4Qt5
#LIBS += -L..\QScintilla-2.11.5\build-qscintilla-Desktop_Qt_5_15_0_MinGW_64_bit-Debug\debug -lqscintilla2_qt5d

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/QScintilla-2.11.5/build-qscintilla-Desktop_Qt_5_14_1_clang_64bit-Debug/release/ -lqscintilla2_qt5_debug.15.0.0
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/QScintilla-2.11.5/build-qscintilla-Desktop_Qt_5_14_1_clang_64bit-Debug/debug/ -lqscintilla2_qt5_debug.15.0.0
else:unix: LIBS += -L$$PWD/QScintilla-2.11.5/build-qscintilla-Desktop_Qt_5_14_1_clang_64bit-Debug/ -lqscintilla2_qt5_debug.15.0.0

INCLUDEPATH += $$PWD/QScintilla-2.11.5/Qt4Qt5
DEPENDPATH += $$PWD/QScintilla-2.11.5/Qt4Qt5
