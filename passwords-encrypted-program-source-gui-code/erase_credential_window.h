#ifndef ERASE_CREDENTIAL_WINDOW_H
#define ERASE_CREDENTIAL_WINDOW_H

#include <QDialog>

namespace Ui {
class Erase_Credential_Window;
}

class Erase_Credential_Window : public QDialog
{
    Q_OBJECT

signals:
    void eraseItem(QString credential);
    void cancelButton();

public:
    explicit Erase_Credential_Window(QWidget *parent = nullptr);
    ~Erase_Credential_Window();

private slots:
    void on_acceptButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::Erase_Credential_Window *ui;
};

#endif // ERASE_CREDENTIAL_WINDOW_H
