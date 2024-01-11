#ifndef STUDENT_H
#define STUDENT_H

#include "user.h"

class Student : public User
{
public:
    Student(QString name , QString email , QString password , int id) ;
};

#endif // STUDENT_H
