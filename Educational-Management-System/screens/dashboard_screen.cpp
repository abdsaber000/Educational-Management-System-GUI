#include "../mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::DashboardScreen(){

    /* reset dashboard screen */

    ui->ViewCreatedCoursesButton_Dashboard->hide();
    ui->ViewEnrolledCoursesButton_Dashboard->hide();
    ui->CreateCourseButton_Dashboard->hide();
    ui->ExploreCoursesButton_Dashboard->hide();
    ui->WelcomeLabel_DashboardScreen->hide();

    if(middleware->get_user_type() == STUDENT){
        DashboardStudent();
    }else{
        DashboardTeacher();
    }

    ui->stackedWidget->setCurrentIndex(DASHBOARD_SCREEN);

}

void MainWindow::DashboardStudent(){
    QString welcomeMessage = "Welcome student ";
    welcomeMessage += middleware->get_user_name();
    ui->WelcomeLabel_DashboardScreen->setText(welcomeMessage);

    ui->WelcomeLabel_DashboardScreen->show();
    ui->ViewEnrolledCoursesButton_Dashboard->show();
    ui->ExploreCoursesButton_Dashboard->show();

}

void MainWindow::DashboardTeacher(){
    QString welcomeMessage = "Welcome teacher ";
    welcomeMessage += middleware->get_user_name();
    ui->WelcomeLabel_DashboardScreen->setText(welcomeMessage);

    ui->WelcomeLabel_DashboardScreen->show();
    ui->ViewCreatedCoursesButton_Dashboard->show();
    ui->CreateCourseButton_Dashboard->show();
}

void MainWindow::on_LogoutButton_DashboardScreen_clicked()
{
    middleware->logout();

    ui->stackedWidget->setCurrentIndex(WELCOME_SCREEN);
}


void MainWindow::on_SettingsButton_DashboardScreen_clicked()
{
    ui->stackedWidget->setCurrentIndex(SETTINGS_SCREEN);
}


void MainWindow::on_BackButton_SettingsScreen_clicked()
{
    DashboardScreen();
}



void MainWindow::on_CreateCourseButton_Dashboard_clicked()
{
    ui->stackedWidget->setCurrentIndex(CREATE_COURSE_SCREEN);
}
