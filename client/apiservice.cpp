#include "apiservice.h"

ServerRequest::~ServerRequest() {} ;

QJsonObject* ServerRequest::exportJson() {return nullptr;} ;

ServerRequest::ServerRequest() {
    this->user = "" ;
    this->token = "" ;
};

ServerRequest::ServerRequest(QString user) {
    this->user = user ;
    this->token = "" ;
};

ServerRequest::ServerRequest(QString user, QString token) {
    this->user = user ;
    this->token = token ;
};

void ServerRequest::setUser(QString user) {
    this->user = user;
};

void ServerRequest::setToken(QString token) {
    this->token = token;
};

QString ServerRequest::getUser() {
    return this->user;
};

QString ServerRequest::getToken() {
    return this->token;
};

RegistrationRequest::~RegistrationRequest(){} ;

RegistrationRequest::RegistrationRequest() {
    this->mail = "" ;
};

RegistrationRequest::RegistrationRequest(QString mail, QString user) {
    this->mail = mail ;
    this->setUser(user) ;
};

void RegistrationRequest::setMail(QString mail) {
    this->mail = mail;
};

QString RegistrationRequest::getMail() {
    return this->mail;
};

QJsonObject* RegistrationRequest::exportJson() {
    QJsonObject* json = new  QJsonObject() ;
    json->insert("username", this->getUser() ) ;
    json->insert("email", this->getMail() ) ;
    return json;
};

LoginRequest::~LoginRequest(){} ;

LoginRequest::LoginRequest() {
    this->password = "";
};

LoginRequest::LoginRequest(QString user, QString password) {
    this->setUser(user) ;
    this->password = password ;
};

void LoginRequest::setPassword(QString password) {
    this->password = password ;
};

QString LoginRequest::getPassword() {
    return this->password ;
};

QJsonObject* LoginRequest::exportJson() {
    QJsonObject* json = new QJsonObject() ;
    json->insert("username", this->getUser() ) ;
    json->insert("password", this->getPassword() );
    return json;
};

VerificationRequest::~VerificationRequest() {} ;

VerificationRequest::VerificationRequest() {
    this->mail = "" ;
    this->verification = "" ;
};

VerificationRequest::VerificationRequest(QString mail, QString verification) {
    this->mail = mail ;
    this->verification = verification ;
};

void VerificationRequest::setMail(QString mail) {
    this->mail = mail ;
};

void VerificationRequest::setVerification(QString verification) {
    this->verification = verification ;
};

QString VerificationRequest::getMail() {
    return this->mail ;
};

QString VerificationRequest::getVerification() {
    return this->verification ;
};

QJsonObject* VerificationRequest::exportJson() {
    QJsonObject* json = new QJsonObject() ;
    json->insert("email", this->getMail() ) ;
    json->insert("verification", this->getVerification() ) ;
    return json;
};

CompleteRegistrationRequest::~CompleteRegistrationRequest() {} ;

CompleteRegistrationRequest::CompleteRegistrationRequest() {
    this->mail = "" ;
    this->password = "" ;
    this->rpassword = "" ;
};

CompleteRegistrationRequest::CompleteRegistrationRequest(
          QString mail
        , QString password
        , QString rpassword
        ) {
    this->mail = mail ;
    this->password = password ;
    this->rpassword = rpassword ;
};

void CompleteRegistrationRequest::setMail(QString mail) {
    this->mail = mail ;
};

void CompleteRegistrationRequest::setPassword(QString password) {
    this->password = password ;
};

void CompleteRegistrationRequest::setRpassword(QString rpassword) {
    this->rpassword = rpassword ;
};

QString CompleteRegistrationRequest::getMail() {
    return this->mail ;
};

QString CompleteRegistrationRequest::getPassword() {
    return this->password ;
};

QString CompleteRegistrationRequest::getRpassword() {
    return this->rpassword ;
}

QJsonObject* CompleteRegistrationRequest::exportJson() {
    QJsonObject* json = new QJsonObject() ;
    json->insert("username", this->getUser() ) ;
    json->insert("email", this->getMail() ) ;
    json->insert("password", this->getPassword() ) ;
    json->insert("token", this->getToken() ) ;
    return json;
}
