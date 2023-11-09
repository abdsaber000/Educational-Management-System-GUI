#include "../mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_BackButton_LoginScreen_clicked()
{
    ui->stackedWidget->setCurrentIndex(WELCOME_SCREEN);
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
