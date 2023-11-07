#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(WELCOME_SCREEN);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete middleware;
}




void MainWindow::on_LoginButton_WeclomeScreen_clicked()
{
    ui->stackedWidget->setCurrentIndex(LOGIN_SCREEN);
}


void MainWindow::on_BackButton_LoginScreen_clicked()
{
    ui->stackedWidget->setCurrentIndex(WELCOME_SCREEN);
}


void MainWindow::on_SignupButton_WelcomeScreen_clicked()
{
    ui->stackedWidget->setCurrentIndex(SIGNUP_SCREEN);
}


void MainWindow::on_LoginButton_LoginScreen_clicked()
{
    QString email = ui->EmailTextEdit->toPlainText();
    QString password = ui->PasswordTextEdit->toPlainText();


    QString error = middleware->login(email , password);
    if(middleware->get_isLogged() && !error.size()){
        /* reset login screen */
        ui->EmailTextEdit->setText("");
        ui->PasswordTextEdit->setText("");

        DashboardScreen();
    }else{
        QMessageBox::information(this , "Error" , error);
    }

}


void MainWindow::on_BackButton_SignUpScreen_clicked()
{
    ui->stackedWidget->setCurrentIndex(WELCOME_SCREEN);
}


void MainWindow::on_SignUpButton_SignUpScreen_clicked()
{
    QString name = ui->NameTextEdit_SignUpScreen->toPlainText();
    QString email = ui->EmailTextEdit_SignUpScreen->toPlainText();
    QString password = ui->PasswordTextEdit_SignUpScreen->toPlainText();
    QString confirmPassword = ui->ConfirmPasswordTextEdit_SignUpScreen->toPlainText();
    QString type = "";
    if(ui->StudentRadio_SignUpScreen->isChecked()){
        type = STUDENT;
    }
    if(ui->TeacherRadio_SignUpScreen->isChecked()){
        type = TEACHER;
    }

    QString error = middleware->Signup(name , email , password , confirmPassword, type);

    if(!error.size()){
        /* reset signup screen */
        ui->NameTextEdit_SignUpScreen->setText("");
        ui->EmailTextEdit_SignUpScreen->setText("");
        ui->PasswordTextEdit_SignUpScreen->setText("");
        ui->ConfirmPasswordTextEdit_SignUpScreen->setText("");

        DashboardScreen();
    }else{
        QMessageBox::information(this, "Error" , error);
    }
}


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



