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
                return "user not found";
            }else return "duplicate logging";
        }

        user = users.back();
        isLogged = true;
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


