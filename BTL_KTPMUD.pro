QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    choose_option_login.cpp \
    databaseconnection.cpp \
    family.cpp \
    login.cpp \
    main.cpp \
    management.cpp \
    staff.cpp

HEADERS += \
    choose_option_login.h \
    databaseconnection.h \
    family.h \
    login.h \
    management.h \
    staff.h

FORMS += \
    choose_option_login.ui \
    family.ui \
    login.ui \
    management.ui \
    staff.ui
QMAKE_CXXFLAGS += -std=gnu++14
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
