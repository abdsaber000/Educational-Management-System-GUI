#include "lecture.h"

Lecture::Lecture()
{

}

Lecture::Lecture(int lectureId , int courseId , QString title , QString content){
    this->lectureId = lectureId;
    this->courseId = courseId;
    this->title = title;
    this->content = content;
}

int Lecture::get_lectureId(){
    return lectureId;
}

int Lecture::get_courseId(){
    return courseId;
}

QString Lecture::get_title(){
    return title;
}

QString Lecture::get_content(){
    return content;
}
