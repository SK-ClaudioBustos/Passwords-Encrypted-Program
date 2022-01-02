#ifndef NEW_PASSWORD_WINDOW_H
#define NEW_PASSWORD_WINDOW_H

#include <QDialog>

namespace Ui {
class new_password_window;
}

class new_password_window : public QDialog
{
    Q_OBJECT

public:
    explicit new_password_window(QWidget *parent = nullptr);
    ~new_password_window();

signals:
    void sendPassword(QString password);
    void cancelButton();

private slots:
    void on_acceptButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::new_password_window *ui;
};

#endif // NEW_PASSWORD_WINDOW_H
