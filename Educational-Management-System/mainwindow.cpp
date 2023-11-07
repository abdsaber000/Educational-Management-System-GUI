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

        DashboardScreen();
    }else{
        QMessageBox::information(this, "Error" , error);
    }
}


void MainWindow::DashboardScreen(){


    QString welcomeMessage = "Welcome ";
    if(middleware->get_user_type() == STUDENT){
        welcomeMessage = welcomeMessage + STUDENT + " ";
    }else welcomeMessage = welcomeMessage + TEACHER +" ";
    QString userName = middleware->get_user_name();
    welcomeMessage += userName;
    ui->WelcomeLabel_DashboardScreen->setText(welcomeMessage);
    ui->stackedWidget->setCurrentIndex(DASHBOARD_SCREEN);
}
