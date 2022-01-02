#include "add_credential_window.h"
#include "ui_add_credential_window.h"
#include <regex>
#include <QMessageBox>
Add_Credential_Window::Add_Credential_Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_Credential_Window)
{
    ui->setupUi(this);
    this->ui->passLineEdit->setEchoMode(QLineEdit::Password);
}

Add_Credential_Window::~Add_Credential_Window()
{
    delete ui;
}

void Add_Credential_Window::on_addButton_clicked()
{
    std::regex str_expr("[^ ].*");
    QString origin = this->ui->originLineEdit->text();
    QString user = this->ui->userLineEdit->text();
    QString pass = this->ui->passLineEdit->text();
    this->hide();
    if(std::regex_match(origin.toUtf8().constData(),str_expr)){
        emit newCredential(origin,user,pass);
    }
    else{
        QMessageBox * criticalMessageBox = new QMessageBox(this);
        criticalMessageBox->setWindowTitle("Wrong Origin Name");
        criticalMessageBox->addButton(QMessageBox::Ok);
        criticalMessageBox->setStyleSheet("QMessageBox{background-color:#55aaff ;color: black;}"
                                          "QPushButton{background-color:#ee6c4d;color: black;}");
        criticalMessageBox->setFont(QFont("Reem Kufi",11));
        criticalMessageBox->setInformativeText("Enter a Valid Origin");
        criticalMessageBox->show();
        if(criticalMessageBox->exec() == QMessageBox::Ok){
            this->show();
        }
    }
    this->ui->originLineEdit->setText("");
    this->ui->userLineEdit->setText("");
    this->ui->passLineEdit->setText("");
}

void Add_Credential_Window::on_cancelButton_clicked()
{
    emit closeProgram();
}

