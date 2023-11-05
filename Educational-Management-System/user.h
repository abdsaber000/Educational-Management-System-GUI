#ifndef USER_H
#define USER_H

#include<QApplication>

class User
{
public:
    User();
    User(QString name, QString email, QString password , int id);
protected:
    QString name;
    QString email;
    QString password;
    int id;
    QString type;
};

#endif // USER_H
