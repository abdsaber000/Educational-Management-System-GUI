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
, CREATE_COURSE_SCREEN};


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

private:
    Ui::MainWindow *ui;
    MiddleWare *middleware;
    void DashboardScreen();
    void DashboardStudent();
    void DashboardTeacher();

};
#endif // MAINWINDOW_H
