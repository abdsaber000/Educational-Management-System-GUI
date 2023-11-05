#ifndef TEACHER_H
#define TEACHER_H

#include "user.h"

class Teacher : User
{
public:
    Teacher(QString name , QString email , QString password , int id);
};

#endif // TEACHER_H
