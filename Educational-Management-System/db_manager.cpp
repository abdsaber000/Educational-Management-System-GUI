#include "db_manager.h"

DB_Manager::DB_Manager()
{
    QString path = "C:\\Users\\Dell\\Documents\\Educational-Management-System-GUI\\Educational-Management-System\\database.db";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);

    if(!db.open()){
//        qDebug << "failed to connect";
    }
}


QString DB_Manager::getUser_EmailPassword(QString email , QString password){
    QSqlQuery query(db);
    QString command = "SELECT * FROM User WHERE email = :email AND password = :password";
    query.prepare(command);
    query.bindValue(":email" , email);
    query.bindValue(":password" , password);
    if(query.exec()){
        return "true";
    }

    QString res = query.lastError().text();
    return res;
}
