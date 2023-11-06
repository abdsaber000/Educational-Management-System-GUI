#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
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

    MiddleWare middleware;
    QString error = middleware.login(email , password);
    if(middleware.get_isLogged() && !error.size()){
        QMessageBox::information(this , "Logged in!" , "you logged in.");
    }else{
        QMessageBox::information(this , "Error" , error);
    }
}

