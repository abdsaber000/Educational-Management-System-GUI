#ifndef USER_H
#define USER_H

#include<QApplication>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
class User
{
public:
    User();
    User(QString name, QString email, QString password , int id);
    static bool isValidEmail(QString email);
    static bool isValidPassword(QString password);
    static bool isValidName(QString name);
    QString get_name();
    QString get_type();
protected:
    QString name;
    QString email;
    QString password;
    int id;
    QString type;
};

#endif // USER_H
