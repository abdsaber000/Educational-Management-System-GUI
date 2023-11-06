#include "db_manager.h"
#include <iostream>
DB_Manager::DB_Manager(QString path)
{

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);

    if(!db.open()){

    }
}

DB_Manager::DB_Manager(){

}

std::vector<User*> DB_Manager::getUser_EmailPassword(QString email , QString password){
    QSqlQuery query;
    QString command = "SELECT * FROM User WHERE email = :email AND password = :password";
    query.prepare(command);
    query.bindValue(":email" , email);
    query.bindValue(":password" , password);

    if(query.exec()){
        std::vector<User*> query_results;

        while(query.next()){

            QString name = query.value(0).toString();
            QString email = query.value(1).toString();
            QString password = query.value(2).toString();
            int id = query.value(3).toInt();
            QString type = query.value(4).toString();

            if(type == "student"){
                Student student = Student(name , email , password , id);
                query_results.push_back(&student);
            }else if(type == "teacher"){
                Teacher teacher = Teacher(name , email , password , id);
                query_results.push_back(&teacher);
            }
        }

        return query_results;
    }else{
        throw query.lastError();
    }
    return {};
}

bool DB_Manager::isOpen(){
    return db.isOpen();
}

QString DB_Manager::lastError(){
    return db.lastError().text();
}

bool DB_Manager::isUserExist(QString email){
    QSqlQuery query;
    query.prepare("SELECT * FROM User WHERE email = :email");
    query.bindValue(":email" , email);
    if(query.exec()){
        if(query.next()){
            return true;
        }
        return false;
    }else{
        throw query.lastError();
    }
    return false;
}

void DB_Manager::addUser(QString name, QString email, QString password, QString type){
    QSqlQuery query;
    query.prepare("INSERT INTO User (name , email , password, type) VALUES (:name, :email , :password , :type)");
    query.bindValue(":name" , name);
    query.bindValue(":email" , email);
    query.bindValue(":password" , password);
    query.bindValue(":type" , type);
    if(!query.exec()){
        throw query.lastError();
    }
}
