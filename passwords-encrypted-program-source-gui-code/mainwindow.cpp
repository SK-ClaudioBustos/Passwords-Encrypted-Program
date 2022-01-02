#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString actualPassword = "";
    if(this->pass.existenceOfFile()){
        this->pass.recoveryPassword();
        actualPassword = QString::fromStdString(this->pass.getPassword());
    }
    this->inputPasswordWindow = new Input_Password_Window(this,actualPassword);
    this->newPasswordWindow = new new_password_window(this);
    this->changePasswordWindow = new Change_Password_Window(this,actualPassword);
    this->eraseCredentialWindow = new Erase_Credential_Window(this);
    this->addCredentialWindow = new Add_Credential_Window(this);
    //connections
    connect(newPasswordWindow,SIGNAL(sendPassword(QString)),this,SLOT(setPassword(QString)));
    connect(newPasswordWindow,SIGNAL(cancelButton()),this,SLOT(close()));
    connect(changePasswordWindow,SIGNAL(sendPassword(QString)),this,SLOT(setPassword(QString)));
    connect(changePasswordWindow,SIGNAL(closeProgram()),this,SLOT(closeChangeWindow()));
    connect(inputPasswordWindow,SIGNAL(changeActualPassword()),this,SLOT(changePassword()));
    connect(inputPasswordWindow,SIGNAL(sendPassword()),this,SLOT(setPassword()));
    connect(eraseCredentialWindow,SIGNAL(eraseItem(QString)),this,SLOT(eraseCredential(QString)));
    connect(eraseCredentialWindow,SIGNAL(cancelButton()),this,SLOT(closeEraseWindow()));
    connect(addCredentialWindow,SIGNAL(newCredential(QString,QString,QString)),this,SLOT(addNewCredential(QString,QString,QString)));
    connect(addCredentialWindow,SIGNAL(closeProgram()),this,SLOT(closeAddWindow()));

    this->configurationWindow();
}

//every time the program close, the credentials charged and the credentials recovered was saved
MainWindow::~MainWindow()
{
    this->manager.saveCredentials();
    delete ui;
}
//the main function
void MainWindow::configurationWindow()
{
    this->setWindowTitle("Passwords Encrpyted Program");
    this->ui->tableWidget->setRowCount(1);
    this->ui->tableWidget->setColumnCount(3);
    this->ui->tableWidget->resizeColumnsToContents();
    this->ui->tableWidget->setHorizontalHeaderLabels(QString("Origin;User;Password").split(";"));
    this->ui->tableWidget->setEditTriggers(QTableWidget::NoEditTriggers);
    this->ui->tableWidget->verticalHeader()->setVisible(false);
    this->ui->tableWidget->setStyleSheet("QTableView::item:selected { color:white; background: orange; font-weight:900; }"
                                         "QTableCornerButton::section { background-color: white; }"
                                         "QHeaderView::section { color:white; background-color: blue; }");
    this->ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QString buttonStyle = "QPushButton{background-color:#ee6c4d;color: black;}"
                    "QPushButton:pressed{background-color: #f77f00; color: black}";
    this->ui->agregarButton->setStyleSheet(buttonStyle);
    this->ui->borrarButton->setStyleSheet(buttonStyle);
    this->ui->contraseniaButton->setStyleSheet(buttonStyle);

    if(this->pass.existenceOfFile()){
        this->inputPasswordWindow->show();
    }
    else{
        this->newPasswordWindow->show();
    }
    this->manager.recoveryOfCredentials();
    this->showCredentials();
}
//loads the credentials in the table
void MainWindow::showCredentials(){
    this->ui->tableWidget->setRowCount(0);
    std::map<std::string,Credential> aux = manager.getMap();
    this->ui->tableWidget->setRowCount(aux.size());
    if(aux.size() != 0){
        int x = 0;
        QTableWidgetItem * itemColumn1;
        QTableWidgetItem * itemColumn2;
        QTableWidgetItem * itemColumn3;
        for(auto i = aux.begin(); i != aux.end(); ++i){
            itemColumn1 = new QTableWidgetItem(QString::fromStdString(i->first));
            itemColumn2 = new QTableWidgetItem(QString::fromStdString(i->second.getUser()));
            itemColumn3 = new QTableWidgetItem(QString::fromStdString(i->second.getPassword()));
            this->ui->tableWidget->setItem(x,0,itemColumn1);
            this->ui->tableWidget->setItem(x,1,itemColumn2);
            this->ui->tableWidget->setItem(x,2,itemColumn3);
            x++;
        }
    }
}
//takes the input password and show the mainWindow
void MainWindow::setPassword(QString password)
{
    this->pass.setPassword(password.toUtf8().constData());
    this->pass.savePassword();
    this->show();
}

void MainWindow::setPassword()
{
    this->show();
}
//shows the window change password
void MainWindow::changePassword(){
    this->hide();
    this->changePasswordWindow->show();
}

void MainWindow::closeEraseWindow(){
    this->eraseCredentialWindow->close();
    this->show();
}

void MainWindow::closeAddWindow(){
    this->addCredentialWindow->close();
    this->show();
}

void MainWindow::closeChangeWindow()
{
    this->changePasswordWindow->close();
    this->show();
}
//deletes the credential entered
void MainWindow::eraseCredential(QString credential)
{
    this->eraseCredentialWindow->close();
    std::string aux = credential.toUtf8().constData();
    if(this->manager.credentialExistence(aux)){
        this->manager.eraseCredential(aux);
        this->show();
        this->showCredentials();
    }
    else{
        QMessageBox * criticalMessageBox = new QMessageBox(this);
        criticalMessageBox->setWindowTitle("Credential Existence");
        criticalMessageBox->addButton(QMessageBox::Ok);
        criticalMessageBox->setStyleSheet("QMessageBox{background-color:#55aaff ;color: black;}"
                                          "QPushButton{background-color:#ee6c4d;color: black;}");
        criticalMessageBox->setFont(QFont("Reem Kufi",11));
        criticalMessageBox->setInformativeText("The origin name does not exist");
        criticalMessageBox->show();
        if(criticalMessageBox->exec() == QMessageBox::Ok){
            this->show();
        }
    }
}
//adds a new credential
void MainWindow::addNewCredential(QString o, QString u, QString p)
{
    this->addCredentialWindow->close();
    this->show();
    this->manager.setCredential(std::make_pair(o.toUtf8().constData(),Credential(u.toUtf8().constData(),p.toUtf8().constData())));
    this->showCredentials();
}

void MainWindow::on_agregarButton_clicked()
{
    this->hide();
    this->addCredentialWindow->show();
}

void MainWindow::on_borrarButton_clicked()
{
    this->hide();
    this->eraseCredentialWindow->show();
}

void MainWindow::on_contraseniaButton_clicked()
{
    this->changePassword();
}

