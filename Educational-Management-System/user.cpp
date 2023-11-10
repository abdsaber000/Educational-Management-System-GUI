#include "user.h"

User::User(QString name , QString email , QString password , int id) :
    name(name) , email(email) , password(password) , id(id)
{

}

User::User(){

}

bool User::isValidEmail(QString email){
    QRegularExpression reg("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

    QRegularExpressionMatch regMatch = reg.match(email);
    return regMatch.hasMatch();
}

bool User::isValidPassword(QString password){
    QRegularExpression reg("\\w+");

    QRegularExpressionMatch regMatch = reg.match(password);

    return regMatch.hasMatch() && password.size() >= 8;
}

bool User::isValidName(QString name){
    return name.size() > 0;
}

QString User::get_name(){
    return name;
}

QString User::get_type(){
    return type;
}

int User::get_id(){
    return id;
}

QString User::get_password(){
    return password;
}

void User::set_name(QString name){
    this->name = name;
}

void User::set_email(QString email){
    this->email = email;
}

void User::set_password(QString password){
    this->password = password;
}
