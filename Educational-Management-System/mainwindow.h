#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include "middleware.h"

#define STUDENT "student"
#define TEACHER "teacher"

enum screens {WELCOME_SCREEN , LOGIN_SCREEN , SIGNUP_SCREEN , DASHBOARD_SCREEN
, SETTINGS_SCREEN, VIEW_ENROLLED_COURSES_SCREEN, EXPLORE_COURSES_SCREEN
, CREATE_COURSE_SCREEN , CHANGE_NAME_SCREEN , CHANGE_EMAIL_SCREEN
, CHANGE_PASSWORD_SCREEN};


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_LoginButton_WeclomeScreen_clicked();

    void on_BackButton_LoginScreen_clicked();

    void on_SignupButton_WelcomeScreen_clicked();

    void on_LoginButton_LoginScreen_clicked();

    void on_BackButton_SignUpScreen_clicked();

    void on_SignUpButton_SignUpScreen_clicked();

    void on_LogoutButton_DashboardScreen_clicked();

    void on_BackButton_SettingsScreen_clicked();

    void on_SettingsButton_DashboardScreen_clicked();

    void on_CreateCourseButton_Dashboard_clicked();

    void on_BackButton_CreateCourse_clicked();

    void on_CreateCourseButton_CreateCourse_clicked();

    void on_ExploreCoursesButton_Dashboard_clicked();

    void on_BackButton_ExploreCoursesScreen_clicked();

    void on_ChangeName_SettingsScreen_clicked();

    void on_ChangeEmail_SettingsScreen_clicked();

    void on_ChangePassword_SettingsScreen_clicked();

    void on_BackButton_ChangeName_clicked();

    void on_ChangeButton_ChangeName_clicked();

    void on_BackButton_ChangeEmail_clicked();

    void on_ChangeButton_ChangeEmail_clicked();

    void on_BackButton_ChangePasswordScreen_clicked();

    void on_ChangeButton_ChangePasswordScreen_clicked();

private:
    Ui::MainWindow *ui;
    MiddleWare *middleware;
    void DashboardScreen();
    void DashboardStudent();
    void DashboardTeacher();
    void ExploreCourses();

};
#endif // MAINWINDOW_H
