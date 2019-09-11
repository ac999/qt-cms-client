#include "haveibeenpwned.h"

haveibeenpwned::haveibeenpwned()
{
    this->user = "" ;
    this->password = "" ;
    this->response = "" ;
};

haveibeenpwned::haveibeenpwned(
          QString user
        , QString password
        ) {
    this->user = user ;
    this->password = password ;
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
};

QString haveibeenpwned::getUser() {
    return this->user ;
};

QString haveibeenpwned::getPassword() {
    return this->password ;
};

QString haveibeenpwned::getResponse() {
    return this->response ;
};
