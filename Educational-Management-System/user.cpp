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
