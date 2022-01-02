#ifndef CHANGE_PASSWORD_WINDOW_H
#define CHANGE_PASSWORD_WINDOW_H

#include <QDialog>

namespace Ui {
class Change_Password_Window;
}

class Change_Password_Window : public QDialog
{
    Q_OBJECT

signals:
    void sendPassword(QString password);
    void closeProgram();

public:
    explicit Change_Password_Window(QWidget *parent = nullptr,QString actualPassword="");
    ~Change_Password_Window();

private slots:
    void on_acceptButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::Change_Password_Window *ui;
    QString actualPassword;
};

#endif // CHANGE_PASSWORD_WINDOW_H
