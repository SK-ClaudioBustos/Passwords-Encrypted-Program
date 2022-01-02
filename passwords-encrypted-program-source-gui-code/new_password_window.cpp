#include "new_password_window.h"
#include "ui_new_password_window.h"
#include <regex>
#include <qmessagebox.h>

new_password_window::new_password_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::new_password_window)
{
    ui->setupUi(this);
    this->ui->newPasswordLineEdit->setEchoMode(QLineEdit::Password);
}

new_password_window::~new_password_window()
{
    delete ui;
}

void new_password_window::on_acceptButton_clicked()
{
    QString aux = this->ui->newPasswordLineEdit->text();
    std::regex str_expr("^[0-9]+$");
    if(std::regex_match(aux.toUtf8().constData(),str_expr)){
        emit sendPassword(aux);
        this->close();
    }else{
        QMessageBox * criticalMessageBox = new QMessageBox(this);
        criticalMessageBox->setWindowTitle("Wrong Password");
        criticalMessageBox->addButton(QMessageBox::Ok);
        criticalMessageBox->addButton(QMessageBox::Cancel);
        criticalMessageBox->setStyleSheet("QMessageBox{background-color:#55aaff ;color: black;}"
                                          "QPushButton{background-color:#ee6c4d;color: black;}");
        criticalMessageBox->setFont(QFont("Reem Kufi",11));
        criticalMessageBox->setInformativeText("Use Only Numbers");
        this->hide();
        criticalMessageBox->show();
        if(criticalMessageBox->exec() == QMessageBox::Cancel){
            this->close();
        }
        else{
        this->show();
        }
    }
}

void new_password_window::on_cancelButton_clicked()
{
    this->hide();
    emit cancelButton();
}

