#include "../mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_ChangeName_SettingsScreen_clicked()
{
    ui->stackedWidget->setCurrentIndex(CHANGE_NAME_SCREEN);
}


void MainWindow::on_ChangeEmail_SettingsScreen_clicked()
{
    ui->stackedWidget->setCurrentIndex(CHANGE_EMAIL_SCREEN);
}


void MainWindow::on_ChangePassword_SettingsScreen_clicked()
{
    ui->stackedWidget->setCurrentIndex(CHANGE_PASSWORD_SCREEN);
}


void MainWindow::on_BackButton_SettingsScreen_clicked()
{
    DashboardScreen();
}

