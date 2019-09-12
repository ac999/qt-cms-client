#include "haveibeenpwned.h"

haveibeenpwned::haveibeenpwned()
{
    this->user = "" ;
    this->password = "" ;
    this->passwordHash = "" ;
    this->statusUser = false ;
    this->statusPassword = false;
};

haveibeenpwned::haveibeenpwned(
          QString user
        , QString password
        ) {
    this->user = user ;
    this->password = password ;
    this->passwordHash = SHA1(password) ;
    this->statusUser = false ;
    this->statusPassword = false ;
};

bool haveibeenpwned::checkUser() {
    return true ;
};

bool haveibeenpwned::checkPassword() {
    return true ;
};

void haveibeenpwned::setUser(QString user) {
    this->user = user ;
};

void haveibeenpwned::setPassword(QString password) {
    this->password = password ;
    this->passwordHash = SHA1(password) ;
};

QString haveibeenpwned::getUser() {
    return this->user ;
};

QString haveibeenpwned::getPassword() {
    return this->password ;
};

bool haveibeenpwned::getStatusUser() {
    return this->statusUser ;
};

bool haveibeenpwned::getStatusPassword() {
    return this->statusPassword ;
};

QByteArray haveibeenpwned::sendRequest(
        QString url
      , QString ApiKey
        ) {

};

QString SHA1(QString password) {
    QCryptographicHash* hash = new QCryptographicHash(QCryptographicHash::Sha1) ;
    hash->addData(password.toUtf8()) ;
    return QString::fromUtf8(hash->result() ) ;
};
