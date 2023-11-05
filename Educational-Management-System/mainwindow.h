#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_LoginButton_WeclomeScreen_clicked();

    void on_BackButton_LoginScreen_clicked();

    void on_SignupButton_WelcomeScreen_clicked();

private:
    Ui::MainWindow *ui;
    enum screens {WELCOME_SCREEN , LOGIN_SCREEN , SIGNUP_SCREEN};
};
#endif // MAINWINDOW_H
