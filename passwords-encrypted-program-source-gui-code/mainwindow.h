#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTableWidgetItem>
#include <QtWidgets>
#include <credential.h>
#include <credentials_manager.h>
#include <password.h>
#include <input_password_window.h>
#include <new_password_window.h>
#include <change_password_window.h>
#include <erase_credential_window.h>
#include <map>
#include <iostream>
#include <QTableWidgetItem>
#include <add_credential_window.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void configurationWindow();

public slots:
    void setPassword(QString password);
    void setPassword();
    void changePassword();
    void eraseCredential(QString credential);
    void closeEraseWindow();
    void closeAddWindow();
    void closeChangeWindow();
    void addNewCredential(QString o,QString u,QString p);
    void showCredentials();

private slots:
    void on_agregarButton_clicked();
    void on_borrarButton_clicked();
    void on_contraseniaButton_clicked();

private:
    Ui::MainWindow *ui;
    Credentials_Manager manager;
    Password pass;
    Input_Password_Window * inputPasswordWindow;
    new_password_window * newPasswordWindow;
    Change_Password_Window * changePasswordWindow;
    Erase_Credential_Window * eraseCredentialWindow;
    Add_Credential_Window * addCredentialWindow;
};
#endif // MAINWINDOW_H
