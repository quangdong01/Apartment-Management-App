QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addnewfamilys.cpp \
    choose_option_login.cpp \
    databaseconnection.cpp \
    deletefamily.cpp \
    deletemember.cpp \
    enternewmember.cpp \
    family.cpp \
    family_addnewstaff.cpp \
    family_billpay.cpp \
    family_chooseservice.cpp \
    family_complementaddnew.cpp \
    family_servicebuy.cpp \
    family_showinf4.cpp \
    inf4full.cpp \
    login.cpp \
    main.cpp \
    manage_addnewservice.cpp \
    manage_deletestaff.cpp \
    manage_delservice.cpp \
    manage_servicebebuy.cpp \
    manage_showservice.cpp \
    manage_showstaffs.cpp \
    manage_showsumserpay.cpp \
    management.cpp \
    seachtocomplement_addordel.cpp \
    searchtocomlement.cpp \
    showfamilys.cpp \
    staff.cpp \
    staff_showcalendar.cpp \
    staff_showinf4.cpp \
    updatefamily.cpp

HEADERS += \
    addnewfamilys.h \
    choose_option_login.h \
    databaseconnection.h \
    deletefamily.h \
    deletemember.h \
    enternewmember.h \
    family.h \
    family_addnewstaff.h \
    family_billpay.h \
    family_chooseservice.h \
    family_complementaddnew.h \
    family_servicebuy.h \
    family_showinf4.h \
    inf4full.h \
    login.h \
    manage_addnewservice.h \
    manage_deletestaff.h \
    manage_delservice.h \
    manage_servicebebuy.h \
    manage_showservice.h \
    manage_showstaffs.h \
    manage_showsumserpay.h \
    management.h \
    seachtocomplement_addordel.h \
    searchtocomlement.h \
    showfamilys.h \
    staff.h \
    staff_showcalendar.h \
    staff_showinf4.h \
    updatefamily.h

FORMS += \
    addnewfamilys.ui \
    choose_option_login.ui \
    deletefamily.ui \
    deletemember.ui \
    enternewmember.ui \
    family.ui \
    family_addnewstaff.ui \
    family_billpay.ui \
    family_chooseservice.ui \
    family_complementaddnew.ui \
    family_servicebuy.ui \
    family_showinf4.ui \
    inf4full.ui \
    login.ui \
    manage_addnewservice.ui \
    manage_deletestaff.ui \
    manage_delservice.ui \
    manage_servicebebuy.ui \
    manage_showservice.ui \
    manage_showstaffs.ui \
    manage_showsumserpay.ui \
    management.ui \
    seachtocomplement_addordel.ui \
    searchtocomlement.ui \
    showfamilys.ui \
    staff.ui \
    staff_showcalendar.ui \
    staff_showinf4.ui \
    updatefamily.ui
QMAKE_CXXFLAGS += -std=gnu++14
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
