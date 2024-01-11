#ifndef COURSE_H
#define COURSE_H

#include <QApplication>

class Course
{
    int courseId;
    int teacherId;
    QString courseName;
public:
    Course();
    Course(int courseId , int teacherId , QString courseName);
    int get_courseId();
    int get_teacherId();
    QString get_courseName();
};

#endif // COURSE_H
