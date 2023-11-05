#ifndef MIDDLEWARE_H
#define MIDDLEWARE_H

#include "db_manager.h"
#include "user.h"
#include <QApplication>
class MiddleWare
{
private:

    static DB_Manager DB;
    static User user;
public:
    MiddleWare();
};

#endif // MIDDLEWARE_H
