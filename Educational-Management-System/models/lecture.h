#ifndef LECTURE_H
#define LECTURE_H

#include<QApplication>

class Lecture
{
    int lectureId;
    int courseId;
    QString title;
    QString content;
public:
    Lecture();
    Lecture(int lectureId , int courseId , QString title , QString content);
    int get_lectureId();
    int get_courseId();
    QString get_title();
    QString get_content();
};

#endif // LECTURE_H
