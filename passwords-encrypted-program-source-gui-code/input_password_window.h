#ifndef INPUT_PASSWORD_WINDOW_H
#define INPUT_PASSWORD_WINDOW_H

#include <QDialog>

namespace Ui {
class Input_Password_Window;
}

class Input_Password_Window : public QDialog
{
    Q_OBJECT

signals:
    void sendPassword();
    void changeActualPassword();

public:
    explicit Input_Password_Window(QWidget *parent = nullptr,QString actpass="");
    ~Input_Password_Window();


private slots:
    void on_changeButton_clicked();
    void on_acceptButton_clicked();

private:
    Ui::Input_Password_Window *ui;
    QString actualPassword;
};

#endif // INPUT_PASSWORD_WINDOW_H
