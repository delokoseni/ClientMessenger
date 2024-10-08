#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "loginform.h"
#include "registrationform.h"
#include "nicknameform.h"
#include "messengerform.h"
#include "settingsform.h"
#include "chatform.h"

#include <QMainWindow>
#include <QJsonObject>
#include <QString>

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    LoginForm *loginForm;
    RegistrationForm *registrationForm;
    NicknameForm *nicknameForm;
    MessengerForm *messengerForm;
    SettingsForm *settingsForm;
    ChatForm *chatForm;
    unsigned int window_width = 500;
    unsigned int window_height = 500;
    QTcpSocket *socket;
    QString login;

    void isNicknameNewUser();

private slots:
    void showLoginForm();
    void showRegistrationForm();
    void showMessengerForm();
    void showNicknameForm();
    void onLoginSuccess();
    void receiveNicknameStatus();
    void showSettingsForm();
    void handleLogout();
    void showChatForm(QString chatId, QString userNickname);
    void onChatRequested(QString chatId, QString userNickname);

protected:
    void closeEvent(QCloseEvent *event) override;

public:
    MainWindow(QTcpSocket* socket, QWidget *parent = nullptr);

signals:
    void loginRequested();  //Сигнал для переключения на форму входа
    void checkNicknameStatus(const QString& login);  //Сигнал для проверки статуса никнейма

};
#endif // MAINWINDOW_H
