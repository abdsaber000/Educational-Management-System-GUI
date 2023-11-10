#include "../mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::on_BackButton_ChangePasswordScreen_clicked()
{
    ui->OldPasswordTextEdit_ChangePasswordScreen->setText("");
    ui->NewPasswordTextEdit_ChangePasswordScreen->setText("");
    ui->ConfirmPasswordTextEdit_ChangePasswordScreen->setText("");

    ui->stackedWidget->setCurrentIndex(SETTINGS_SCREEN);
}


void MainWindow::on_ChangeButton_ChangePasswordScreen_clicked()
{
    QString oldPassword = ui->OldPasswordTextEdit_ChangePasswordScreen->toPlainText();
    QString newPassword = ui->NewPasswordTextEdit_ChangePasswordScreen->toPlainText();
    QString confirmPassword = ui->ConfirmPasswordTextEdit_ChangePasswordScreen->toPlainText();

    QString error = middleware->changeUserPassword(oldPassword , newPassword , confirmPassword);

    if(error.size()){
        QMessageBox::information(this , "Error" , error);
    }else{
        QMessageBox::information(this,  "Done" , "Password is changed.");
        ui->OldPasswordTextEdit_ChangePasswordScreen->setText("");
        ui->NewPasswordTextEdit_ChangePasswordScreen->setText("");
        ui->ConfirmPasswordTextEdit_ChangePasswordScreen->setText("");
        ui->stackedWidget->setCurrentIndex(WELCOME_SCREEN);
    }
}

