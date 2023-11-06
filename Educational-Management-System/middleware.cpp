#include "middleware.h"

MiddleWare::MiddleWare()
{

}

void MiddleWare::set_isLogged(bool status){
    isLogged = status;
}

QString MiddleWare::login(QString email , QString password){
    if(!DB.isOpen()) return "Database Failed";
    try{
        std::vector<User*> users = DB.getUser_EmailPassword(email , password);
        if(users.size() != 1){
            if(users.size() == 0){
                return "user not found.";
            }else return "duplicate logging.";
        }

        user = users.back();
        isLogged = true;
    }catch(QSqlError error){
        return error.text();
    }

    return "";
}
/*
    - check if name is valid
    - check if email is valid
    - check if password is valid
    - check if password equals confirmPassword
    - check DB error
    ==> create a user
*/
QString MiddleWare::Signup(QString name, QString email, QString password, QString confirmPassword, QString type){
    if(!User::isValidName(name)) return "name is not valid.";
    if(!User::isValidEmail(email)) return "email is not valid.";
    if(!User::isValidPassword(password)) return "password is not valid.";
    if(password != confirmPassword) return "password and confirm password are not the same";

    try{
        if(DB.isUserExist(email)){
            return "user email already exist.";
        }

        DB.addUser(name , email , password , type);

        user = DB.getUser_EmailPassword(email , password).back();
    }catch(QSqlError error){
        return error.text();
    }



    return "";
}

bool MiddleWare::get_isLogged(){
    return isLogged;
}

/* initialization */

bool MiddleWare::isLogged = false;
User* MiddleWare::user = new User();
DB_Manager MiddleWare::DB = DB_Manager(PATH);


