#include "../mainwindow.h"
#include "ui_mainwindow.h"


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

