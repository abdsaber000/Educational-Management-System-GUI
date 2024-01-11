#ifndef DB_MANAGER_H
#define DB_MANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QMessageBox>
#include <QtDebug>
#include <QDebug>
#include <QApplication>
#include <QStringDecoder>
#include <QStringEncoder>
#include <QTextCodec>
#include <QSqlQueryModel>
#include <vector>
#include "models/user.h"
#include "models/student.h"
#include "models/teacher.h"
#include "models/course.h"

class DB_Manager
{
public:
    DB_Manager();
    DB_Manager(QString path);
    bool isUserExist(QString email);
    bool isCourseExist(int courseId);
    bool isUserCreatedCourse(int userId , int courseId);
    void addUser(QString name, QString email , QString password , QString type);
    void addCourse(QString courseName , int teacherId);
    void addEnrollment(int courseId , int userId);
    QSqlQueryModel * getAllCourses();
    QSqlQueryModel * getLecturesInCourse(int courseId);
    QSqlQueryModel * getEnrolledCourses(int userId);
    QSqlQueryModel * getEnrolledStudents(int courseId);
    QSqlQueryModel * getCreatedCourses(int userId);
    std::vector<User*> getUser_EmailPassword(QString email , QString password);
    std::vector<Course *> getCourse(int courseId);
    void updateUserName(int userId , QString newName);
    void updateUserEmail(int userId , QString newEmail);
    void updateUserPassword(int userId , QString newPassword);
    void deleteCreatedCourse(int courseId);
    void deleteEnrollment(int userId , int courseId);
    bool isOpen();
    QString lastError();
private:
    QSqlDatabase db;
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
};



#endif // DB_MANAGER_H
