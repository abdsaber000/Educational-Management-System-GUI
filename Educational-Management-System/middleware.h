#ifndef MIDDLEWARE_H
#define MIDDLEWARE_H

#include "db_manager.h"
#include "models/user.h"
#include "models/course.h"
#include <QApplication>

#define PATH  "C:\\Users\\Dell\\Documents\\Educational-Management-System-GUI\\Educational-Management-System\\database.db"

class MiddleWare
{
private:

    static DB_Manager DB;
    static User *user;
    static bool isLogged;
    static Course *selectedCourse;
    static bool isCourseSelected;
public:
    MiddleWare();
    QString login(QString email , QString password);
    QString Signup(QString name , QString email , QString password
                   , QString confirmPassword , QString type);
    void logout();
    QString createCourse(QString courseName);
    QString enrollCourse(int courseId);
    QString selectCourse(QString courseId);
    QString getAllCourses(QSqlQueryModel * & model);
    QString getEnrolledCourses(QSqlQueryModel * & model);
    QString getStudentsInSelectedCourse(QSqlQueryModel * & model);
    QString getCreatedCourses(QSqlQueryModel * & model);
    QString changeUserName(QString newName , QString password);
    QString changeUserEmail(QString newEmail , QString password);
    QString changeUserPassword(QString oldPassword , QString newPassword , QString confirmPassword);
    QString deleteUserCreatedCourse(QString userId);
    QString deleteStudentInCourse(int userId , int courseId);

    void set_isLogged(bool status);
    void set_user(User * user);
    void set_isCourseSelected(bool status);
    void set_selectedCourse(Course * course);
    bool get_isLogged();
    bool get_isCourseSelected();
    User * get_user();
    QString get_user_name();
    QString get_user_type();
    Course * get_selectedCourse();
};



#endif // MIDDLEWARE_H
