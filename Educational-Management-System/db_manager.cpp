#include "db_manager.h"
#include <iostream>

DB_Manager::DB_Manager(QString path)
{

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);

    if(!db.open()){

    }

    db.exec("PRAGMA locking_mode = EXCLUSIVE");
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

bool DB_Manager::isCourseExist(int courseId){
    QSqlQuery query;
    query.prepare("SELECT * FROM Course WHERE courseId = :courseId");
    query.bindValue(":courseId" ,  courseId);

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

bool DB_Manager::isUserCreatedCourse(int userId, int courseId){
    QSqlQuery query;

    query.prepare("SELECT * FROM Course WHERE courseId = :courseId AND teacherId = :userId");

    query.bindValue(":courseId" , courseId);
    query.bindValue(":userId" , userId);

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

void DB_Manager::addEnrollment(int courseId , int userId){
    QSqlQuery query;
    query.prepare("INSERT INTO Enrollments (studentId , courseId) VALUES (:studentId , :courseId)");
    query.bindValue(":studentId" , userId);
    query.bindValue(":courseId" , courseId);

    if(!query.exec()){
        throw query.lastError();
    }

}

QSqlQueryModel * DB_Manager::getAllCourses(){
    QSqlQuery query;
    query.prepare("SELECT Course.courseName AS 'Course Name' , User.name AS 'Teacher' , Course.courseId AS 'Course Id'\
        FROM Course , User WHERE User.id = Course.teacherId");


    if(!query.exec()){
        throw query.lastError();
    }

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(query);
    return model;

}


QSqlQueryModel * DB_Manager::getEnrolledCourses(int userId){

    QSqlQuery query;
    query.prepare("SELECT Course.courseName AS 'Course Name' , User.name AS 'Teacher Name' , Course.courseId AS 'Course Id' \
        FROM Course , User , Enrollments  \
        WHERE Enrollments.courseId = Course.courseId AND Enrollments.studentId = :userId AND Course.teacherId = User.id");

    query.bindValue(":userId" , userId);
    if(!query.exec()){
        throw query.lastError();
    }

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(query);
    return model;
}

QSqlQueryModel * DB_Manager::getEnrolledStudents(int courseId){

    QSqlQuery query;
    query.prepare("SELECT User.name AS 'Student Name', User.id AS 'Student Id'\
        FROM User , Enrollments \
        WHERE User.id = Enrollments.studentId AND Enrollments.courseId = :courseId");

    query.bindValue(":courseId" , courseId);

    if(!query.exec()){
        throw query.lastError();
    }

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(query);
    return model;
}



QSqlQueryModel * DB_Manager::getCreatedCourses(int userId){
    QSqlQuery query;

    query.prepare("SELECT Course.courseName as 'Course Name' , Course.courseId AS 'Course Id' FROM Course WHERE Course.teacherId = :userId");

    query.bindValue(":userId" , userId);

    if(!query.exec()){
        throw query.lastError();
    }

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(query);
    return model;
}

std::vector<Course *> DB_Manager::getCourse(int courseId){
    QSqlQuery query;

    query.prepare("SELECT * FROM Course WHERE Course.courseId = :courseId");
    query.bindValue(":courseId" , courseId);
    if(query.exec()){
        std::vector<Course*> query_results;
        int courseIdIndex = query.record().indexOf("courseId");
        int teacherIdIndex = query.record().indexOf("teacherId");
        int courseNameIndex = query.record().indexOf("courseName");

        while(query.next()){

            QString name = codec->toUnicode(query.value(courseNameIndex).toByteArray());
            int course_id = query.value(courseIdIndex).toInt();
            int teacher_id = query.value(teacherIdIndex).toInt();
            query_results.push_back(new Course(courseId , teacher_id , name));
        }

        return query_results;
    }else throw query.lastError();

    return {};

}

void DB_Manager::updateUserName(int userId , QString userName){

    QSqlQuery query;

    query.prepare("UPDATE User SET name = :name WHERE id = :id");

    query.bindValue(":name" , userName);
    query.bindValue(":id" , userId);
    if(!query.exec())
        throw query.lastError();
}

void DB_Manager::updateUserEmail(int userId, QString newEmail){
    QSqlQuery query;

    query.prepare("UPDATE User SET email = :email WHERE id = :id");

    query.bindValue(":email" , newEmail);
    query.bindValue(":id" , userId);
    if(!query.exec())
        throw query.lastError();
}

void DB_Manager::updateUserPassword(int userId, QString newPassword){
    QSqlQuery query;

    query.prepare("UPDATE User SET password = :password WHERE id = :id");

    query.bindValue(":password" , newPassword);
    query.bindValue(":id" , userId);
    if(!query.exec())
        throw query.lastError();
}

void DB_Manager::deleteCreatedCourse(int courseId){
    QSqlQuery query;

    query.prepare("DELETE FROM Course WHERE Course.courseId = :courseId");
    query.bindValue(":courseId" , courseId);

    if(!query.exec())
        throw query.lastError();
}

void DB_Manager::deleteEnrollment(int userId, int courseId){
    QSqlQuery query;
    query.prepare("DELETE FROM Enrollments WHERE Enrollments.courseId = :courseId AND Enrollments.studentId = :studentId");

    query.bindValue(":courseId" , courseId);
    query.bindValue(":studentId" , userId);

    if(!query.exec())
        throw query.lastError();
}
