#ifndef APISERVICE_H
#define APISERVICE_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QtNetwork>

class ServerRequest {
protected:
    QString  user ;
    QString token ;
public:
    ServerRequest() ;
    ServerRequest(QString user) ;
    ServerRequest(QString user, QString token) ;

    void setUser(QString user) ;
    void setToken(QString token) ;
    QString getUser() ;
    QString getToken() ;

    virtual ~ServerRequest() ;
    virtual QJsonObject* exportJson() ;
};

class ServerResponse {
protected:
    QString status;
    QString message;
public:
    ServerResponse() ;
    void getServerResponse() ;
    QString getStatus();
    QString getMessage();
};

class RegistrationRequest: public ServerRequest
{
private:
    QString mail;
public:
    RegistrationRequest();
    RegistrationRequest(QString mail, QString user) ;

    void setMail(QString mail) ;
    QString getMail() ;

    ~RegistrationRequest() ;
    QJsonObject* exportJson() ;
};

class LoginRequest: public ServerRequest
{
private:
    QString password;
public:
    LoginRequest() ;
    LoginRequest(QString user, QString password) ;

    void setPassword(QString password) ;
    QString getPassword() ;

    ~LoginRequest() ;
    QJsonObject* exportJson() ;
};

class VerificationRequest: public ServerRequest
{
private:
    QString mail;
    QString verification;
public:
    VerificationRequest() ;
    VerificationRequest(
              QString mail
            , QString verification
            ) ;

    void setMail(QString mail) ;
    void setVerification(QString verification) ;
    QString getMail() ;
    QString getVerification() ;

    ~VerificationRequest() ;
    QJsonObject* exportJson() ;
};

class CompleteRegistrationRequest: public ServerRequest
{
private:
    QString mail ;
    QString password ;
    QString rpassword ;
public:
    CompleteRegistrationRequest() ;
    CompleteRegistrationRequest(
              QString mail
            , QString password
            , QString rpassword
            ) ;
    void setMail(QString mail) ;
    void setPassword(QString password) ;
    void setRpassword(QString rpassword) ;
    QString getMail() ;
    QString getPassword() ;
    QString getRpassword() ;

    ~CompleteRegistrationRequest() ;
    QJsonObject* exportJson() ;
};

#endif // APISERVICE_H
