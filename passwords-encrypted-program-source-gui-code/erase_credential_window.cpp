#include "erase_credential_window.h"
#include "ui_erase_credential_window.h"

Erase_Credential_Window::Erase_Credential_Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Erase_Credential_Window)
{
    ui->setupUi(this);
}

Erase_Credential_Window::~Erase_Credential_Window()
{
    delete ui;
}

void Erase_Credential_Window::on_acceptButton_clicked()
{
    this->hide();
    QString credentialToErase = this->ui->itemEraseLineEdit->text();
    emit eraseItem(credentialToErase);
    this->ui->itemEraseLineEdit->setText("");
}

void Erase_Credential_Window::on_cancelButton_clicked()
{
    emit cancelButton();
}

