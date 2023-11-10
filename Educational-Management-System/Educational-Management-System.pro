QT       += core gui sql
QT += core5compat
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    db_manager.cpp \
    main.cpp \
    mainwindow.cpp \
    middleware.cpp \
    screens/change_email_screen.cpp \
    screens/change_name_screen.cpp \
    screens/change_password_screen.cpp \
    screens/create_course_screen.cpp \
    screens/dashboard_screen.cpp \
    screens/explore_courses_screen.cpp \
    screens/login_screen.cpp \
    screens/settings_screen.cpp \
    screens/signup_screen.cpp \
    screens/welcome_screen.cpp \
    student.cpp \
    teacher.cpp \
    user.cpp \

HEADERS += \
    db_manager.h \
    mainwindow.h \
    middleware.h \
    student.h \
    teacher.h \
    user.h

FORMS += \
    mainwindow.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
