#include "../mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::on_BackButton_ChangeEmail_clicked()
{
    ui->EnterEmailTextEdit_ChangeEmailScreen->setText("");
    ui->PasswordTextEdit_ChangeEmailScreen->setText("");
    ui->stackedWidget->setCurrentIndex(SETTINGS_SCREEN);
}


void MainWindow::on_ChangeButton_ChangeEmail_clicked()
{
    QString newEmail = ui->EnterEmailTextEdit_ChangeEmailScreen->toPlainText();
    QString password = ui->PasswordTextEdit_ChangeEmailScreen->toPlainText();

    QString error = middleware->changeUserEmail(newEmail , password);
    if(error.size()){
        QMessageBox::information(this , "Error" , error);
    }else{
        QMessageBox::information(this , "Done" , "Email is changed.");
        ui->EnterEmailTextEdit_ChangeEmailScreen->setText("");
        ui->PasswordTextEdit_ChangeEmailScreen->setText("");
        ui->stackedWidget->setCurrentIndex(WELCOME_SCREEN);
    }
}
