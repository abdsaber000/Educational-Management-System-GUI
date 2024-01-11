#include "../mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::EnrolledCourses(){
    QSqlQueryModel * model;
    QString error = middleware->getEnrolledCourses(model);
    if(error.size()){
        QMessageBox::information(this , "error" , error);
        return;
    }

    ui->EnrolledCoursesTableView_ExploreCoursesScreen->setModel(model);

    ui->stackedWidget->setCurrentIndex(VIEW_ENROLLED_COURSES_SCREEN);
}


void MainWindow::on_BackButton_ExploreCoursesScreen_2_clicked()
{
    DashboardScreen();
}
