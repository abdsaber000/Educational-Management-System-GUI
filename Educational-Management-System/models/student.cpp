#include "student.h"

Student::Student(QString name , QString email , QString password , int id)  :
    User(name , email , password , id)
{
    this->type = "student";
}
