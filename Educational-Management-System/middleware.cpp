#include "middleware.h"

MiddleWare::MiddleWare()
{

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
        isLogged = true;
    }catch(QSqlError error){
        return error.text();
    }



    return "";
}

void MiddleWare::logout(){
    set_user(new User());
    set_isLogged(false);
}

QString MiddleWare::createCourse(QString courseName){
    try{
        DB.addCourse(courseName , user->get_id());
    }catch(QSqlError error){
        return error.text();
    }
    return "";
}

QString MiddleWare::enrollCourse(int courseId){
    try{
        if(!DB.isCourseExist(courseId)) return "course id is not valid.";
        DB.addEnrollment(courseId , user->get_id());
    }catch(QSqlError error){
        return error.text();
    }
    return "";
}

QString MiddleWare::selectCourse(QString courseId){
    try{
        std::vector<Course*> courses = DB.getCourse(courseId.toInt());
        if(courses.empty())
            return "course id is not found.";

        assert(courses.size() == 1);

        set_selectedCourse(courses.back());
        set_isCourseSelected(true);
    }catch(QSqlError error){
        return error.text();
    }
    return "";
}

QString MiddleWare::getAllCourses(QSqlQueryModel * &model){
    try{
        model = DB.getAllCourses();
    }catch(QSqlError error){
        return error.text();
    }
    return "";
}

QString MiddleWare::getEnrolledCourses(QSqlQueryModel *&model){
    try{
        model = DB.getEnrolledCourses(user->get_id());
    }catch(QSqlError error){
        return error.text();
    }
    return "";
}

QString MiddleWare::getStudentsInSelectedCourse(QSqlQueryModel *&model){
    try{
        if(!isCourseSelected) return "course is not selected!";
        model = DB.getEnrolledStudents(selectedCourse->get_courseId());

    }catch(QSqlError error){
        return error.text();
    }
    return "";
}


QString MiddleWare::getCreatedCourses(QSqlQueryModel *&model){
    try{
        model = DB.getCreatedCourses(user->get_id());
    }catch(QSqlError error){
        return error.text();
    }
    return "";
}

QString MiddleWare::changeUserName(QString newName , QString password){
    if(password != user->get_password()) return "password is wrong.";
    if(!user->isValidName(newName)) return "New name is not valid.";

    try{
        DB.updateUserName(user->get_id() , newName);
        user->set_name(newName);
    }catch(QSqlError error){
        return error.text();
    }

    return "";
}

QString MiddleWare::changeUserEmail(QString newEmail, QString password){
    if(password != user->get_password()) return "password is wrong.";
    if(!user->isValidEmail(newEmail)) return "New email is not valid.";

    try{
        DB.updateUserEmail(user->get_id() , newEmail);
        user->set_email(newEmail);
    }catch(QSqlError error){
        return error.text();
    }
    return "";
}

QString MiddleWare::changeUserPassword(QString oldPassword, QString newPassword, QString confirmPassword){
    if(oldPassword != user->get_password()) return "Old password is wrong.";
    if(newPassword != confirmPassword) return "Confirm password is not the same as the new password.";
    if(!user->isValidPassword(newPassword)) return "New password is not valid.";

    try{
        DB.updateUserPassword(user->get_id() , newPassword);
        user->set_password(newPassword);
    }catch(QSqlError error){
        return error.text();
    }
    return "";
}

QString MiddleWare::deleteUserCreatedCourse(QString courseId){

    try{
        if(!DB.isUserCreatedCourse(user->get_id() , courseId.toInt() )){
            return "Course Id doesn't exist";
        }
        DB.deleteCreatedCourse(courseId.toInt());
    }catch(QSqlError error){
        return error.text();
    }
    return "";
}

QString MiddleWare::deleteStudentInCourse(int userId, int courseId){

    try{
        DB.deleteEnrollment(userId , courseId);
    }catch(QSqlError error){
        return error.text();
    }
    return "";
}

/* getters and setters */

bool MiddleWare::get_isLogged(){
    return isLogged;
}


User * MiddleWare::get_user(){
    return user;
}

QString MiddleWare::get_user_name(){
    return user->get_name();
}

QString MiddleWare::get_user_type(){
    return user->get_type();
}

Course * MiddleWare::get_selectedCourse(){
    return selectedCourse;
}

void MiddleWare::set_isLogged(bool status){
    this->isLogged = status;
}

void MiddleWare::set_user(User *user){
    this->user = user;
}

void MiddleWare::set_isCourseSelected(bool status){
    this->isCourseSelected = status;
}

void MiddleWare::set_selectedCourse(Course *course){
    this->selectedCourse = course;
}
/* initialization */

bool MiddleWare::isLogged = false;
User* MiddleWare::user = new User();
DB_Manager MiddleWare::DB = DB_Manager(PATH);
Course* MiddleWare::selectedCourse = new Course();
bool MiddleWare::isCourseSelected = false;
