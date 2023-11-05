#include "teacher.h"

Teacher::Teacher(QString name , QString email , QString password , int id) :
    User(name , email , password , id)
{
    this->type = "teacher";
}
