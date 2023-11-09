#include "../mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::on_LoginButton_WeclomeScreen_clicked()
{
    ui->stackedWidget->setCurrentIndex(LOGIN_SCREEN);
}

void MainWindow::on_SignupButton_WelcomeScreen_clicked()
{
    ui->stackedWidget->setCurrentIndex(SIGNUP_SCREEN);
}
