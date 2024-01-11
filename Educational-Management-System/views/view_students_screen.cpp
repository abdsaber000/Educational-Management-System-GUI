#include "../mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::ViewStudents(){
    ui->studentIdTextEdit_ViewStudentsScreen->setText("");

    QSqlQueryModel * model;

    QString error = middleware->getStudentsInSelectedCourse(model);

    if(error.size()){
        QMessageBox::information(this , "error" , error);
        return ;
    }

    ui->studentsTableView_ViewStudentsScreen->setModel(model);
    ui->stackedWidget->setCurrentIndex(VIEW_STUDENTS_SCREEN);
}

void MainWindow::on_BackButton_ViewStudentsScreen_clicked()
{
    ui->studentIdTextEdit_ViewStudentsScreen->setText("");
    CreatedCourses();
}



void MainWindow::on_DeleteStudentButton_ViewStudentsScreen_clicked()
{
    int userId = ui->studentIdTextEdit_ViewStudentsScreen->toPlainText().toInt();
    int courseId = middleware->get_selectedCourse()->get_courseId();
    QString error = middleware->deleteStudentInCourse(userId , courseId);

    if(error.size()){
        QMessageBox::information(this , "error" , error);

    }else{
        QMessageBox::information(this , "done" , "student is removed succesfully");
        ViewStudents();
    }
}
