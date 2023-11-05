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

