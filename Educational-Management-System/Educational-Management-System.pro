QT       += core gui sql
QT += core5compat
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    models/course.cpp \
    db_manager.cpp \
    models/lecture.cpp \
    main.cpp \
    mainwindow.cpp \
    middleware.cpp \
    views/change_email_screen.cpp \
    views/change_name_screen.cpp \
    views/change_password_screen.cpp \
    views/create_course_screen.cpp \
    views/created_courses_screen.cpp \
    views/dashboard_screen.cpp \
    views/enrolled_courses_screen.cpp \
    views/explore_courses_screen.cpp \
    views/login_screen.cpp \
    views/settings_screen.cpp \
    views/signup_screen.cpp \
    views/view_lectures_screen.cpp \
    views/view_students_screen.cpp \
    views/welcome_screen.cpp \
    models/student.cpp \
    models/teacher.cpp \
    models/user.cpp \

HEADERS += \
    models/course.h \
    db_manager.h \
    models/lecture.h \
    mainwindow.h \
    middleware.h \
    models/student.h \
    models/teacher.h \
    models/user.h

FORMS += \
    mainwindow.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
