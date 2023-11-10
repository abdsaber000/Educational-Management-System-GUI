#include "../mainwindow.h"
#include "ui_mainwindow.h"



void MainWindow::on_BackButton_ChangeName_clicked()
{
    ui->NewNameTextEdit_ChangeName->setText("");
    ui->PasswordTextEdit_ChangeName->setText("");
    ui->stackedWidget->setCurrentIndex(SETTINGS_SCREEN);
}


void MainWindow::on_ChangeButton_ChangeName_clicked()
{
    QString newName = ui->NewNameTextEdit_ChangeName->toPlainText();
    QString password = ui->PasswordTextEdit_ChangeName->toPlainText();

    QString error = middleware->changeUserName(newName , password);

    if(error.size()){
        QMessageBox::information(this , "Error" , error);
    }else{
        QMessageBox::information(this , "Done" , "Name is changed.");
        ui->NewNameTextEdit_ChangeName->setText("");
        ui->PasswordTextEdit_ChangeName->setText("");
        DashboardScreen();
    }
}
