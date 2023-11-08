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
#include <vector>
#include "user.h"
#include "student.h"
#include "teacher.h"
class DB_Manager
{
public:
    DB_Manager();
    DB_Manager(QString path);
    std::vector<User*> getUser_EmailPassword(QString email , QString password);
    bool isUserExist(QString email);
    void addUser(QString name, QString email , QString password , QString type);
    void addCourse(QString courseName , int teacherId);
    bool isOpen();
    QString lastError();
private:
    QSqlDatabase db;
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
};



#endif // DB_MANAGER_H
