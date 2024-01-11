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
    ui->CourseIdTextEdit_CreatedCoursesScreen->setText("");
    ui->stackedWidget->setCurrentIndex(VIEW_CREATED_COURSES_SCREEN);
}



void MainWindow::on_DeleteButton_CreatedCoursesScreen_clicked()
{
    QString courseId = ui->CourseIdTextEdit_CreatedCoursesScreen->toPlainText();
    QString error = middleware->deleteUserCreatedCourse(courseId);
    if(error.size()){
        QMessageBox::information(this , "error" , error);
        return ;
    }

    CreatedCourses();
}



void MainWindow::on_ViewStudentsButton_CreatedCoursesScreen_clicked()
{
    QString courseId = ui->CourseIdTextEdit_CreatedCoursesScreen->toPlainText();
    QString error = middleware->selectCourse(courseId);

    if(error.size()){
        QMessageBox::information(this , "error" , error);
        return ;
    }

    ViewStudents();
}


void MainWindow::on_BackButton_CreatedCoursesScreen_clicked()
{
    DashboardScreen();
}

