QT       += core gui
QT       += network
QT       += printsupport
QT       += charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Forms/chooseform.cpp \
    Forms/dataform.cpp \
    Forms/graphicform.cpp \
    Forms/statisticsform.cpp \
    Forms/tableform.cpp \
    Forms/typeinfostructform.cpp \
    Objects/account.cpp \
    Objects/hourinfo.cpp \
    Objects/program.cpp \
    Objects/user.cpp \
    Objects/usermanager.cpp \
    Tests/testentiretydata.cpp \
    Windows/logwindow.cpp \
    Windows/mainwindow.cpp \
    main.cpp

HEADERS += \
    Forms/chooseform.h \
    Forms/dataform.h \
    Forms/graphicform.h \
    Forms/statisticsform.h \
    Forms/tableform.h \
    Forms/typeinfostructform.h \
    Objects/account.h \
    Objects/hourinfo.h \
    Objects/program.h \
    Objects/user.h \
    Objects/usermanager.h \
    Tests/testentiretydata.h \
    Windows/logwindow.h \
    Windows/mainwindow.h

FORMS += \
    Forms/chooseform.ui \
    Forms/dataform.ui \
    Forms/graphicform.ui \
    Forms/statisticsform.ui \
    Forms/tableform.ui \
    Forms/typeinfostructform.ui \
    Windows/logwindow.ui \
    Windows/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
