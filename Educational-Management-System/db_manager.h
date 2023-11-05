#ifndef DB_MANAGER_H
#define DB_MANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QtDebug>
#include <QDebug>
#include <QApplication>
class DB_Manager
{
public:
    DB_Manager();
    QString getUser_EmailPassword(QString email , QString password);
private:
    QSqlDatabase db;
};



#endif // DB_MANAGER_H
