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
        int nameIndex = query.record().indexOf("name");
        int emailIndex = query.record().indexOf("email");
        int passwordIndex = query.record().indexOf("password");
        int idIndex = query.record().indexOf("id");
        int typeIndex = query.record().indexOf("type");

        while(query.next()){

            QString name = codec->toUnicode(query.value(nameIndex).toByteArray());
            QString email = codec->toUnicode(query.value(emailIndex).toByteArray());
            QString password = codec->toUnicode(query.value(passwordIndex).toByteArray());
            int id = query.value(idIndex).toInt();
            QString type = codec->toUnicode(query.value(typeIndex).toByteArray());

            if(type == "student"){
                query_results.push_back(new Student(name , email , password , id));
            }else if(type == "teacher"){
                query_results.push_back(new Teacher(name , email , password , id));
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

void DB_Manager::addCourse(QString courseName , int teacherId){
    QSqlQuery query;

    query.prepare("INSERT INTO Course (courseName , teacherId) VALUES (:courseName , :teacherId)");
    query.bindValue(":courseName" , courseName);
    query.bindValue(":teacherId" , teacherId);
    if(!query.exec()){
        throw query.lastError();
    }
}
