#ifndef MIDDLEWARE_H
#define MIDDLEWARE_H

#include "db_manager.h"
#include "user.h"
#include <QApplication>

#define PATH  "C:\\Users\\Dell\\Documents\\Educational-Management-System-GUI\\Educational-Management-System\\database.db"
class MiddleWare
{
private:

    static DB_Manager DB;
    static User *user;
    static bool isLogged;

public:
    MiddleWare();
    QString login(QString email , QString password);
    QString Signup(QString name , QString email , QString password
                   , QString confirmPassword , QString type);
    void logout();
    QString createCourse(QString courseName);
    void set_isLogged(bool status);
    void set_user(User * user);
    bool get_isLogged();
    User * get_user();
    QString get_user_name();
    QString get_user_type();
};



#endif // MIDDLEWARE_H
