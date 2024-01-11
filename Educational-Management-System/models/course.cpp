#include "course.h"

Course::Course()
{

}

Course::Course(int courseId, int teacherId, QString courseName){
    this->courseId = courseId;
    this->teacherId = teacherId;
    this->courseName = courseName;
}

int Course::get_courseId(){
    return courseId;
}

int Course::get_teacherId(){
    return teacherId;
}

QString Course::get_courseName(){
    return courseName;
}
