#ifndef REGISTRATIONFORM_H
#define REGISTRATIONFORM_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include <QEvent>
#include <QMouseEvent>
#include <QTcpSocket>

class RegistrationForm : public QWidget
{
    Q_OBJECT

private:
    QLabel *registerLabel;
    QLabel *titleLabel;
    QLabel* imageLabel; //Картинка открывающая информацию
    QLabel* opendEyeLabelPass; //Картинка открытого глаза
    QLabel* closedEyeLabelPass; //Картинка закрытого глаза
    QLabel* opendEyeLabelPassAgain;
    QLabel* closedEyeLabelPassAgain;
    QLineEdit *loginEdit;
    QLineEdit *passwordEdit;
    QLineEdit *passwordEditAgain;
    QPushButton *registerButton;
    QPushButton *backButton;
    QTcpSocket *socket;

    bool eventFilter(QObject *target, QEvent *event);
    void registerUser();
    bool passwordContainsRequiredCharacters(const QString &password);
    bool loginContainsOnlyAllowedCharacters(const QString &login);

private slots:
    void onImageLabelClicked();
    void backButtonClicked();
    void handleServerResponse();  //Слот для обработки ответа от сервера

public:
    explicit RegistrationForm(QTcpSocket *socket, QWidget *parent = nullptr);
    void connectSocket();

signals:
    void backRequested();

};

#endif // REGISTRATIONFORM_H
