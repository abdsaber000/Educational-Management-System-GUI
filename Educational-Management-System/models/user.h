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
    QString get_password();
    int get_id();
    void set_name(QString name);
    void set_email(QString email);
    void set_password(QString password);
protected:
    QString name;
    QString email;
    QString password;
    int id;
    QString type;
};

#endif // USER_H
