#include "change_password_window.h"
#include "ui_change_password_window.h"
#include <QMessageBox>
#include <regex>
Change_Password_Window::Change_Password_Window(QWidget *parent, QString actualPassword) :
    QDialog(parent),
    ui(new Ui::Change_Password_Window)
{
    ui->setupUi(this);
    this->actualPassword = actualPassword;
    this->ui->oldPassLineEdit->setEchoMode(QLineEdit::Password);
    this->ui->newPassLineEdit->setEchoMode(QLineEdit::Password);
}

Change_Password_Window::~Change_Password_Window()
{
    delete ui;
}

void Change_Password_Window::on_acceptButton_clicked()
{
    std::regex str_expr("^[0-9]+$");
    this->hide();
    QString actPass = this->ui->oldPassLineEdit->text();
    QString newPass = this->ui->newPassLineEdit->text(); 
    QMessageBox * criticalMessageBox = new QMessageBox(this);
    criticalMessageBox->setWindowTitle("Wrong Password");
    criticalMessageBox->addButton(QMessageBox::Ok);
    criticalMessageBox->addButton(QMessageBox::Cancel);
    criticalMessageBox->setStyleSheet("QMessageBox{background-color:#55aaff ;color: black;}"
                                      "QPushButton{background-color:#ee6c4d;color: black;}");
    criticalMessageBox->setFont(QFont("Reem Kufi",11));
    if(std::regex_match(newPass.toUtf8().constData(),str_expr)){
        if(actPass == this->actualPassword){
            emit sendPassword(newPass);
            this->close();
        }
        else{
            criticalMessageBox->setInformativeText("The old password input is wrong");
            criticalMessageBox->show();
            if(criticalMessageBox->exec() == QMessageBox::Cancel){
                this->close();
            }
            else{
            this->show();
            }
        }
    }
    else{
        criticalMessageBox->setInformativeText("The new password is not a number");
        criticalMessageBox->show();
        if(criticalMessageBox->exec() == QMessageBox::Cancel){
            this->close();
        }
        else{
        this->show();
        }
    }
    this->ui->oldPassLineEdit->setText("");
    this->ui->newPassLineEdit->setText("");
}


void Change_Password_Window::on_cancelButton_clicked()
{
    this->hide();
    emit closeProgram();
}

