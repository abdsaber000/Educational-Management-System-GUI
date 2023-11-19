#include "../mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::CreatedCourses(){
    QSqlQueryModel * model;
    QString error = middleware->getCreatedCourses(model);
    if(error.size()){
        QMessageBox::information(this , "error" , error);
        return;
    }

    ui->CreatedCoursesTableView_CreatedCoursesScreen->setModel(model);

    ui->stackedWidget->setCurrentIndex(VIEW_CREATED_COURSES_SCREEN);
}



void MainWindow::on_BackButton_CreatedCoursesScreen_clicked()
{
    DashboardScreen();
}

