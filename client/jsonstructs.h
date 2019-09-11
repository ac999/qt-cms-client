#ifndef JSONSTRUCTS_H
#define JSONSTRUCTS_H
#include <QJsonDocument>
#include <QJsonObject>


class ServerRequest{
protected:
    QString  user;
    QString token;
public:
    ServerRequest();
    ServerRequest(QString user);
    virtual ~ServerRequest() = 0;
    virtual QJsonObject* exportJson();
};

class RegistrationRequest: public ServerRequest
{
private:
    QString mail;
public:
    RegistrationRequest();
    RegistrationRequest(QString mail, QString user);
    ~RegistrationRequest();
    QJsonObject* exportJson();
};

class LoginRequest: public ServerRequest
{
private:
    QString password;
public:
    LoginRequest();
    LoginRequest(QString user, QString password);
    ~LoginRequest();
    QJsonObject* exportJson();
};

class VerificationRequest: public ServerRequest
{
private:
    QString mail;
    QString verification;
public:
    VerificationRequest();
    VerificationRequest(QString mail, QString verification);
    ~VerificationRequest();
    QJsonObject* exportJson();
};

#endif // JSONSTRUCTS_H
