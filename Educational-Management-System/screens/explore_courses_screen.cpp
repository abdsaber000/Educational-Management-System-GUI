#include "../mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::ExploreCourses(){
    QSqlQueryModel * model;
    QString error = middleware->getAllCourses(model);
    if(error.size()){
        QMessageBox::information(this , "error" , "something went wrong.");
        return;
    }

    ui->CoursesTableView_ExploreCoursesScreen->setModel(model);

    ui->stackedWidget->setCurrentIndex(EXPLORE_COURSES_SCREEN);
}


void MainWindow::on_BackButton_ExploreCoursesScreen_clicked()
{
    DashboardScreen();
}


void MainWindow::on_EnrollButton_ExploreCoursesScreen_clicked()
{
    int courseId = ui->EnrollTextEdit_ExploreCoursesScreen->toPlainText().toInt();

    QString error = middleware->enrollCourse(courseId);
    if(error.size()){
        QMessageBox::information(this , "error" , error);
    }else{
        QMessageBox::information(this , "Done" , "You enrolled in course successfully.");
    }
}
