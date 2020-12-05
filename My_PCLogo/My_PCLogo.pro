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
    CmdFileWidget.cpp \
    CodEditor.cpp \
    HttpRequest.cpp \
    LineEdit.cpp \
    friendList.cpp \
    homepage.cpp \
    main.cpp \
    mainwindow.cpp \
    pvpwidget.cpp \
    qlistwidgetitem.cpp \
    qscilexerLogo.cpp \
    region.cpp \
    searchbar.cpp \
    signinwidget.cpp \
    signupwidget.cpp \
    singlewidget.cpp \
    token.cpp \
    userinfo.cpp \
    canvas.cpp \
    console.cpp

HEADERS += \
    CmdFileWidget.h \
    CodEditor.h \
    HttpRequest.h \
    LineEdit.h \
    Network.h \
    friendList.h \
    homepage.h \
    mainwindow.h \
    pvpwidget.h \
    qlistwidgetitem.h \
    qscilexerLogo.h \
    region.h \
    searchbar.h \
    signinwidget.h \
    signupwidget.h \
    singlewidget.h \
    token.h \
    user.h \
    userinfo.h \
    canvas.h \
    console.h \
    window.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

# Add Code Texter QScintilla

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/QScintilla-2.11.5/build-Debug/release/ -lqscintilla2_qt5d
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/QScintilla-2.11.5/build-Debug/debug/ -lqscintilla2_qt5d
#else:unix: LIBS += -L$$PWD/QScintilla-2.11.5/build-Debug/ -lqscintilla2_qt5d

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/QScintilla-2.11.5/build-Debug/release/ -lqscintilla2_qt5
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/QScintilla-2.11.5/build-Debug/debug/ -lqscintilla2_qt5
else:unix: LIBS += -L$$PWD/QScintilla-2.11.5/build-Debug/ -lqscintilla2_qt5

INCLUDEPATH += $$PWD/QScintilla-2.11.5/Qt4Qt5
DEPENDPATH += $$PWD/QScintilla-2.11.5/Qt4Qt5
