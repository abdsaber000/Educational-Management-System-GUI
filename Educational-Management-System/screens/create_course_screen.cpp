#include "../mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::on_BackButton_CreateCourse_clicked()
{
    ui->CourseNametextEdit_CreateCourse->setText("");
    ui->stackedWidget->setCurrentIndex(DASHBOARD_SCREEN);
}


void MainWindow::on_CreateCourseButton_CreateCourse_clicked()
{
    QString courseName = ui->CourseNametextEdit_CreateCourse->toPlainText();
    QString error = middleware->createCourse(courseName);

    if(error.size()){
        QMessageBox::information(this , "Error" , error);
    }else{
        QMessageBox::information(this , "Done" , "Your course is created !");
        ui->CourseNametextEdit_CreateCourse->setText("");
    }
}
