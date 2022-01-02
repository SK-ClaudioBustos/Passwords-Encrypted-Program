#ifndef ADD_CREDENTIAL_WINDOW_H
#define ADD_CREDENTIAL_WINDOW_H

#include <QDialog>

namespace Ui {
class Add_Credential_Window;
}

class Add_Credential_Window : public QDialog
{
    Q_OBJECT

public:
    explicit Add_Credential_Window(QWidget *parent = nullptr);
    ~Add_Credential_Window();

signals:
    void newCredential(QString o,QString u,QString p);
    void closeProgram();

private slots:
    void on_addButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::Add_Credential_Window *ui;
};

#endif // ADD_CREDENTIAL_WINDOW_H
