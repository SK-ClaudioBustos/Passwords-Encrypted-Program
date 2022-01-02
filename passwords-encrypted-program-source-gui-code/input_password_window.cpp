#include "input_password_window.h"
#include "ui_input_password_window.h"
#include <QMessageBox>
Input_Password_Window::Input_Password_Window(QWidget *parent, QString actpass) :
    QDialog(parent),
    ui(new Ui::Input_Password_Window)
{
    ui->setupUi(this);
    this->actualPassword = actpass;
    this->ui->passLineEdit->setEchoMode(QLineEdit::Password);
}

Input_Password_Window::~Input_Password_Window()
{
    delete ui;
}

void Input_Password_Window::on_changeButton_clicked()
{
    this->close();
    emit changeActualPassword();
}

void Input_Password_Window::on_acceptButton_clicked()
{
    QString pass = this->ui->passLineEdit->text();
    if(actualPassword == pass){
        emit sendPassword();
        this->close();
    }
    else{
        this->hide();
        this->ui->passLineEdit->setText("");
        QMessageBox * criticalMessageBox = new QMessageBox(this);
        criticalMessageBox->setWindowTitle("Wrong Password");
        criticalMessageBox->addButton(QMessageBox::Ok);
        criticalMessageBox->addButton(QMessageBox::Cancel);
        criticalMessageBox->setInformativeText("The password input is wrong");
        criticalMessageBox->setStyleSheet("QMessageBox{background-color:#55aaff ;color: black;}"
                                          "QPushButton{background-color:#ee6c4d;color: black;}");
        criticalMessageBox->setFont(QFont("Reem Kufi",11));
        criticalMessageBox->show();
        if(criticalMessageBox->exec() == QMessageBox::Cancel){
            this->close();
        }
        else{
         this->show();
        }
    }
}

